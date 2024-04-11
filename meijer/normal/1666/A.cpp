#include <bits/stdc++.h>
using namespace std;

const int MX = 50005;

string s;
int n;
bitset<MX> B, X, Y, SB;
bitset<MX> comb1;
bitset<MX> comb2;

int main() {
  cin >> s;
  n = s.size();

  int ans = 0;
  for (int l=0; l<n; l++) {
    B.reset();
    X.reset();
    Y.reset();
    SB.reset();

    int x=-1, y=-1;
    int cntA = 0, cntB = 0;
    bool posA = true, posB = true;

    for (int r=l; r<n; r++) {
      int i = r-l;
      SB[i] = 1;
      if (x == -1 || y == -1) {
        if (s[r] == 'L') {
          if (i == 0) break;
          if (B[i-1]) break;
          B[i-1] = 1;
          cntB++;
        }
        if (s[r] == 'R') {
          B[i+1] = 1;
          cntB++;
        }
        if (s[r] == 'U') {
          X[i] = 1;
          if (x == -1) x = i;
        }
        if (s[r] == 'D') {
          Y[i] = 1;
          if (y == -1) y = i;
        }
        if (x == -1 && y == -1) {
          if (cntB == r-l+1 && s[r] != 'R') {
            ans++;
          }
        } else if(x != -1 && y != -1) {
          int firstZero = -1;
          for (int j=0; j<i; j++) {
            if (B[j] == 0) {
              firstZero = j;
              break;
            }
          }
          assert(firstZero != -1);
          x = abs(firstZero - x);
          y = abs(firstZero - y);
          if (x == 0) x = 1;
          if (y == 0) y = 1;
          comb1 = B;
          comb1 |= X >> x;
          comb1 |= Y << x;
          comb1 &= SB;
          cntA = comb1.count();
          comb2 = B;
          comb2 |= X >> y;
          comb2 |= Y << y;
          comb2 &= SB;
          cntB = comb2.count();
          for (int m=l; m<=r; m++) {
            int j = m-l;
            if(s[m] == 'L') {
              if (j % x == 0) posA = 0;
              if (j % y == 0) posB = 0;
            }
            if(s[m] == 'R') {
              if ((j+1) % x == 0) posA = 0;
              if ((j+1) % y == 0) posB = 0;
            }
          }
          if ((posA && cntA == r-l+1 && ((r-l+1)%x == 0)) || (posB && cntB == r-l+1 && ((r-l+1)%y == 0)))
            ans++;
          comb1 = B;
          comb1 |= X >> x;
          comb1 |= Y << x;
          comb2 = B;
          comb2 |= X >> y;
          comb2 |= Y << y;
        }
      } else {
        if (comb1[i]) cntA++;
        if (comb2[i]) cntB++;
        if (s[r] == 'L') {
          if (i % x == 0) posA = 0;
          if (i % y == 0) posB = 0;
          if (comb1[i-1] == 0) {
            comb1[i-1] = 1;
            cntA++;
          }
          if (comb2[i-1] == 0) {
            comb2[i-1] = 1;
            cntB++;
          }
        }
        if (s[r] == 'R') {
          if ((i+1) % x == 0) posA = 0;
          if ((i+1) % y == 0) posB = 0;
          comb1[i+1] = 1;
          comb2[i+1] = 1;
        }
        if (s[r] == 'U') {
          if (comb1[i-x] == 0) {
            comb1[i-x] = 1;
            cntA++;
          }
          if (comb2[i-y] == 0) {
            comb2[i-y] = 1;
            cntB++;
          }
        }
        if (s[r] == 'D') {
          comb1[i+x] = 1;
          comb2[i+y] = 1;
        }
        if ((posA && cntA == r-l+1 && ((r-l+1)%x == 0)) || (posB && cntB == r-l+1 && ((r-l+1)%y == 0)))
          ans++;
      }
    }
  }

  cout << ans << endl;
}