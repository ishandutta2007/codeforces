#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int IND[200010];
vector<int> E[200010];

int main() {
  int N, M;
  cin >> N >> M;

  int VN = M;
  for(int i = 0; i < N; i++) {
    vector<pair<int, int> > A;
    for(int j = 0; j < M; j++) {
      int x; cin >> x;
      if(x != -1) {
        A.push_back(make_pair(x, j));
      }
    }
    sort(A.begin(), A.end());

    for(int j = 0; j < A.size(); ) {
      int k = 1;
      while(j + k < A.size() && A[j].first == A[j + k].first) k++;

      if(j > 0) for(int a = 0; a < k; a++) {
        E[VN - 1].push_back(A[j + a].second);
      }
      if(j + k == A.size()) break;

      VN++;
      for(int a = 0; a < k; a++) {
        E[A[j + a].second].push_back(VN - 1);
      }

      j += k;
    }
  }

  for(int i = 0; i < VN; i++) {
    for(int j = 0; j < E[i].size(); j++) {
      IND[E[i][j]]++;
    }
  }

  queue<int> q;
  for(int i = 0; i < VN; i++) {
    if(IND[i] == 0) {
      q.push(i);
    }
  }

  vector<int> R;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    if(u < M) R.push_back(u);
    for(int i = 0; i < E[u].size(); i++) {
      int v = E[u][i];
      if(--IND[v] == 0) {
        q.push(v);
      }
    }
  }
  if(R.size() != M) {
    cout << "-1";
  } else for(int i = 0; i < R.size(); i++) {
    if(i) cout << ' ';
    cout << R[i] + 1;
  }
  cout << endl;

  return 0;
}