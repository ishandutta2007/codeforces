#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

#define INF 0x3FFFFFFFFFFFFFFFLL

int N;
int A[100010];
vector<int> E[100010];

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

double flcm(long long a, long long b) {
  return 1.0 * a / gcd(a, b) * b;
}

pair<long long, long long> solve(int u, int p) {
  if(A[u]) {
    return make_pair(A[u], 1);
  }

  int cnt = 0;
  pair<long long, long long> ret(INF, 1);
  for(int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if(v == p) continue;

    pair<long long, long long> res = solve(v, u);
    double ochk = flcm(ret.second, res.second);
    ret.second = lcm(ret.second, res.second);
    if (ochk > 1e16) {
      ret.first = 0;
      ret.second = 1;
    } else {
      ret.first = min(res.first, ret.first) / ret.second * ret.second;
      if (ret.first == 0) ret.second = 1;
    }
    cnt++;

  }

  if(cnt == 0) return make_pair(0, 1);
  ret.first *= cnt;
  ret.second *= cnt;
  if (ret.first == 0) ret.second = 1;
  return ret;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for(int i = 1; i < N; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  cout << accumulate(A, A + N, -solve(0, -1).first) << endl;
  return 0;
}