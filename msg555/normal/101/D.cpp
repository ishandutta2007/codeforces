#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <iomanip>

using namespace std;

vector<pair<int, int> > E[100000];
long long W[100000];

long long weight(int u, int p) {
  long long& ref = W[u];
  if(ref != -1) return ref;
  ref = 0;
  for(int i = 0; i < E[u].size(); i++) {
    int v = E[u][i].first;
    if(v == p) continue;
    ref += 2 * E[u][i].second + weight(v, u);
  }
  return ref;
}

bool cmp(pair<long long, int> A, pair<long long, int> B) {
  return A.first * B.second < B.first * A.second;
}

pair<long long, int> solve(int u, int p) {
  pair<long long, int> ret(0ll, 1);
  vector<pair<long long, int> > V;
  for(int i = 0; i < E[u].size(); i++) {
    int v = E[u][i].first;
    if(v == p) continue;

    pair<long long, int> res = solve(v, u);
    ret.first += res.second * E[u][i].second + res.first;
    ret.second += res.second;

    long long ww = 2 * E[u][i].second + weight(v, u);
    V.push_back(make_pair(ww, res.second));
  }
  sort(V.begin(), V.end(), cmp);

  long long tm = 0;
  for(int i = 0; i < V.size(); i++) {
    ret.first += tm * V[i].second;
    tm += V[i].first;
  }
  return ret;
}

int main() {
  int N;
  cin >> N;
  memset(W, -1, sizeof(W));
  for(int i = 1; i < N; i++) {
    int u, v, d; cin >> u >> v >> d;
    u--; v--;
    E[u].push_back(make_pair(v, d));
    E[v].push_back(make_pair(u, d));
  }
  cout << fixed << 1. * solve(0, -1).first / (N - 1) << endl;
}