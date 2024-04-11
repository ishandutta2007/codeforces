#include <bits/stdc++.h>

using namespace std;

#define MAXV 62
#define INF 0x3FFFFFFF

int N;
int A[110];
int M[MAXV];
int low;
vector<int> P;

int memo[110][1 << 10][10];

int solve(int x, int m) {
  if(__builtin_popcount((m >> low) + 1) != 1) return INF;
  if(x == N) return 0;

  int& ref = memo[x][m & ((1 << low) - 1)][__builtin_popcount(m >> low)];
  if(ref != -1) return ref;

  ref = INF;
  for(int i = 1; i < MAXV; i++) {
    if((M[i] & m) == 0) {
      ref = min(ref, abs(A[x] - i) + solve(x + 1, m | M[i]));
    }
  }
  return ref;
}

void recover(int x, int m) {
  if(x == N) return;

  int val = solve(x, m);
  for(int i = 1; i < MAXV; i++) {
    if((M[i] & m) == 0) {
      if(abs(A[x] - i) + solve(x + 1, m | M[i]) == val) {
        if(x) cout << ' ';
        cout << i;
        recover(x + 1, m | M[i]);
        break;
      }
    }
  }
}

int main() {
  for(int p = 2; p < MAXV; p++) {
    bool isp = true;
    for(int i = 2; i < p && isp; i++) {
      isp = p % i != 0;
    }
    if(isp) {
      P.push_back(p);
      if(p <= 30) low++;
    }
  }

  for(int i = 1; i < MAXV; i++) {
    M[i] = 0;
    for(int j = 0; j < P.size(); j++) {
      if(i % P[j] == 0) {
        M[i] |= 1 << j;
      }
    }
  }

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  memset(memo, -1, sizeof(memo));
  recover(0, 0);
  cout << endl;
  return 0;
}