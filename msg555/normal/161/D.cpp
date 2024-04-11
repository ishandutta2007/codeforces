#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cassert>

using namespace std;

#define MAXN 100010

long long N, K;
long long ANS;
vector<int> E[MAXN];

struct Result {
  long long base_len;
  map<long long, long long> st;
};

bool cmpsz(Result* a, Result* b) {
  return a->st.size() > b->st.size();
}

Result* solve(int u, int p) {
  vector<Result*> C;
  C.push_back(new Result);
  C.back()->base_len = 0;
  C.back()->st[0] = 1;
  for(int i = 0; i < E[u].size(); i++) {
    if(E[u][i] != p) {
      Result* res = solve(E[u][i], u);
      res->base_len++;
      C.push_back(res);
    }
  }
  sort(C.begin(), C.end(), cmpsz);

  for(int i = 1; i < C.size(); i++) {
    for(typeof(C[i]->st.begin()) it = C[i]->st.begin();
        it != C[i]->st.end(); ++it) {
      long long want = K - it->first - C[i]->base_len - C[0]->base_len;
      typeof(it) sr = C[0]->st.find(want);
      if(sr != C[0]->st.end()) {
        ANS += it->second * sr->second;
      }
    }
    for(typeof(C[i]->st.begin()) it = C[i]->st.begin();
        it != C[i]->st.end(); ++it) {
      C[0]->st[it->first + C[i]->base_len - C[0]->base_len] += it->second;
    }
    delete C[i];
  }
  return C[0];
}

int main() {
  cin >> N >> K;
  for(int i = 1; i < N; i++) {
    int u, v; cin >> u >> v; u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  ANS = 0;
  delete solve(0, -1);
  cout << ANS << endl;
}