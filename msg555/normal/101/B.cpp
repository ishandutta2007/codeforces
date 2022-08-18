#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int main() {
  int N, M; cin >> N >> M;
  vector<pair<int, int> > V;
  for(int i = 0; i < M; i ++) {
    int s, t; cin >> s >> t;
    V.push_back(make_pair(t, s));
  }
  V.push_back(make_pair(0, -1));
  sort(V.begin(), V.end());

  int sm = 0, val = 0;
  multiset<pair<int, int> > subs;
  for(int i = V.size() - 1; i >= 0; ) {
    while(!subs.empty() && V[i].first < -subs.begin()->first) {
      sm = (MOD + sm - subs.begin()->second) % MOD;
      subs.erase(subs.begin());
    }
    int smn = sm;
    for(int j = i; i >= 0 && V[i].first == V[j].first; i--) {
      val = V[i].first == N ? 1 : smn;
      sm = (sm + val) % MOD;
      subs.insert(make_pair(-V[i].second, val));
    }
  }
  cout << val << endl;
}