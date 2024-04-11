#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAXN 100010
#define MOD 1000000007

int T[MAXN];
vector<int> dokmp(const char* S, const char* K) {
  T[0] = -1;
  for(int i = 0; K[i]; i++) {
    int pos = T[i];
    while(pos != -1 && K[pos] != K[i]) pos = T[pos];
    T[i + 1] = pos + 1;
  }
  int sp = 0, kp = 0;
  vector<int> res;
  while(S[sp]) {
    while(kp != -1 && (!K[kp] || K[kp] != S[sp])) kp = T[kp];
    kp++;
    sp++;
    if(!K[kp]) {
      res.push_back(sp - kp);
      /* S[sp - kp] ... S[sp] is a match for K. */
    }
  }
  return res;
}

int RE[MAXN];

int DP[MAXN];
int SM[MAXN];

int madd(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

int N;
int memo[MAXN][2];

int solve(int x, int st) {
  if (x == N) {
    return 1;
  }

  int& ref = memo[x][st];
  if (ref != -1) {
    return ref;
  }
  ref = solve(x + 1, st);

  if (st) {
    ref = madd(ref, solve(x, st - 1));
  } else if(RE[x] != -1) {
    ref = madd(ref, solve(RE[x], 1));
  }
  return ref;
}

int main() {
  string S, T;
  cin >> S >> T;
  N = S.size();
  vector<int> res = dokmp(S.c_str(), T.c_str());

  int j = 0;
  for (int i = 0; i < S.size(); i++) {
    if (j == res.size()) {
      RE[i] = -1;
    } else {
      RE[i] = res[j] + T.size();
    }
    if (j < res.size() && i == res[j]) {
      j++;
    }
  }

  memset(memo, -1, sizeof(memo));
  cout << madd(solve(0, 0), MOD - 1) << '\n';
  return 0;
}