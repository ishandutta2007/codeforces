#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <queue>

using namespace std;

int A[200010];
int B[200010];
int C[200010];
int D[200010];

int S[200010];

vector<int> E[200010];

int get_src(int i) {
  return i < 0 ? B[-i] : A[i];
}

int get_dst(int i) {
  return i < 0 ? A[-i] : B[i];
}

int get_cap(int i) {
  return i < 0 ? C[-i] : C[i];
}

int main() {
  int N, M;
  cin >> N >> M;
  for(int i = 1; i <= M; i++) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--;
    B[i]--;
    E[A[i]].push_back(i);
    E[B[i]].push_back(-i);

    S[A[i]] += C[i];
    S[B[i]] += C[i];
  }

  queue<int> q;
  q.push(0);
  memset(D, -1, sizeof(D));
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int i = 0; i < E[u].size(); i++) {
      int j = E[u][i];
      int& d = D[j < 0 ? -j : j];
      if(d != -1) continue;

      int v = get_dst(j);
      d = j < 0;
      S[v] -= 2 * get_cap(j);
      if(v + 1 != N && S[v] == 0) {
        q.push(v);
      }
    }
  }

  for(int i = 1; i <= M; i++) {
    cout << D[i] << '\n';
  }

  return 0;
}