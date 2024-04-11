#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> V;

void gen(int dig) {
  for(int i = 1; i <= dig; i++) {
    for(int j = 0; j < 1 << i; j++) {
      int num = 0;
      for(int k = 0; k < i; k++) {
        num *= 10;
        num += (j & 1 << k) ? 7 : 4;
      }
      V.push_back(num);
    }
  }
  sort(V.begin(), V.end());
}

int N;
vector<pair<int, bool> > E[100000];

int M1[100000];
int M2[100000];

int solve_sum(int x, int p) {
  int& ref = M1[x];
  if(ref != -1) return ref;

  ref = 1;
  for(int i = 0; i < E[x].size(); i++) {
    if(E[x][i].first == p) continue;
    ref += solve_sum(E[x][i].first, x);
  }
  return ref;
}

int solve_front(int x, int p) {
  int& ref = M2[x];
  if(ref != -1) return ref;

  ref = 0;
  for(int i = 0; i < E[x].size(); i++) {
    if(E[x][i].first == p) continue;
    if(E[x][i].second) {
      ref += solve_sum(E[x][i].first, x);
    } else {
      ref += solve_front(E[x][i].first, x);
    }
  }
  return ref;
}

long long solve(int x, int p, int f) {
  long long myf = solve_front(x, p) + f;
  long long ret = myf * (myf - 1);

  for(int i = 0; i < E[x].size(); i++) {
    if(E[x][i].first == p) continue;
    if(E[x][i].second) {
      ret += solve(E[x][i].first, x, N - solve_sum(E[x][i].first, x));
    } else {
      ret += solve(E[x][i].first, x, myf - solve_front(E[x][i].first, x));
    }
  }
  return ret;
}

int main() {
  gen(9);

  cin >> N;
  for(int i = 1; i < N; i++) {
    int u, v, w; cin >> u >> v >> w; u--; v--;
    E[u].push_back(make_pair(v, binary_search(V.begin(), V.end(), w)));
    E[v].push_back(make_pair(u, binary_search(V.begin(), V.end(), w)));
  }

  memset(M1, -1, sizeof(M1));
  memset(M2, -1, sizeof(M2));
  cout << solve(0, -1, 0) << endl;

  return 0;
}