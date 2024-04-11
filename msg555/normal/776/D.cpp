#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> S;
vector<pair<int, int> > T;
vector<vector<pair<int, int> > > A;
vector<int> color;

bool dfs(int x, int col) {
  if (color[x] != -1) {
    return color[x] == col;
  }
  color[x] = col;

  for (auto i : A[x]) {
    if (!dfs(i.first, col ^ i.second)) {
      return false;
    }
  }
  return true;
}

int main() {
  int N, M;
  cin >> N >> M;

  S = vector<int>(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
    S[i] = 1 - S[i];
  }

  T = vector<pair<int, int> >(N, make_pair(-1, -1));
  for (int i = 0; i < M; i++) {
    int sz; cin >> sz;
    for (int j = 0; j < sz; j++) {
      int xi; cin >> xi; xi--;
      if (T[xi].first != -1) {
        T[xi].second = i;
      } else {
        T[xi].first = i;
      }
    }
  }

  A.resize(M);
  for (int i = 0; i < N; i++) {
    A[T[i].first].push_back(make_pair(T[i].second, S[i]));
    A[T[i].second].push_back(make_pair(T[i].first, S[i]));
  }

  color = vector<int>(M, -1);
  for (int i = 0; i < M; i++) {
    if (color[i] != -1) {
      continue;
    }
    if (!dfs(i, 0)) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";

/*
  for (int i = 0; i < M; i++) {
    cout << color[i] << endl;
  }
*/

  return 0;
}