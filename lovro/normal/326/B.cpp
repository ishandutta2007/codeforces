#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;
#define ZERO(v) memset((v), 0, sizeof (v))
#define MINUSONE(v) memset((v), -1, sizeof (v))
#define ALL(x) (x).begin(), (x).end()

const int MAXN = 50005;

int n;
string seq;
int dp[MAXN][51];
bool take[MAXN][51];

int main() {
  cin.sync_with_stdio(0);

  cin >> seq;
  n = seq.size();

  vector<int> pos[26];
  for (int i=0; i<n; ++i) {
    pos[seq[i] - 'a'].push_back(i);
  }

  MINUSONE(dp);
  ZERO(take);
  dp[0][0] = n-1;
  for (int a=0; a<n; ++a) {
    int ch = seq[a] - 'a';
    const vector<int> &v = pos[ch];

    for (int plen=0; plen<50; ++plen) {
      int b = dp[a][plen];
      if (b == -1 || a > b) {
        continue;
      }

      // fprintf(stderr, "dp[a=%d][plen=%d] = %d\n", a, plen, b);

      // take
      int lastpos = *(lower_bound(ALL(v), b+1) - 1);
      if (lastpos > a) {
        if (lastpos-1 > dp[a+1][plen+1]) {
          dp[a+1][plen+1] = lastpos - 1;
          take[a+1][plen+1] = true;
        }
      }

      // don't take
      if (b > a && b > dp[a+1][plen]) {
        dp[a+1][plen] = b;
        take[a+1][plen] = false;
      }
    }
  }

  for (int plen=50; plen>0; --plen) {
    int even = -1, odd = -1;
    for (int a=0; a<n; ++a) {
      int b = dp[a][plen];
      if (b != -1) {
        even = a;
        if (plen < 50 && b >= a) {
          odd = a;
        }
      }
    }
    if (odd != -1 || even != -1) {
      string output;
      int pos;
      if (odd != -1) {
        pos = odd;
        output = seq[pos];
      } else {
        pos = even;
      }
      // debug(pos);
      for (; pos > 0; --pos) {
        if (take[pos][plen]) {
          output = seq[pos-1] + output + seq[pos-1];
          --plen;
        }
      }
      // debug(output.size());
      cout << output << '\n';
      exit(0);
    }
  }
  cout << seq[0] << '\n';
  return 0;
}