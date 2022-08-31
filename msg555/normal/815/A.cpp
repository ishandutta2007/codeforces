#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int> > A(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }

  int mnv = A[0][0];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      mnv = min(mnv, A[i][j]);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      A[i][j] -= mnv;
    }
  }

  // isrow, id
  vector<pair<bool, int> > result;
  for (int i = 0; i < mnv; i++) {
    for (int i = 0; i < min(N, M); i++) {
      result.push_back(make_pair(N <= M, i));
    }
  }

  for (int i = 0; i < N; i++) {
    mnv = A[i][0];
    for (int j = 0; j < M; j++) {
      mnv = min(mnv, A[i][j]);
    }
    for (int j = 0; j < M; j++) {
      A[i][j] -= mnv;
    }
    for (int j = 0; j < mnv; j++) {
      result.push_back(make_pair(true, i));
    }
  }
  for (int i = 0; i < M; i++) {
    mnv = A[0][i];
    for (int j = 0; j < N; j++) {
      mnv = min(mnv, A[j][i]);
    }
    for (int j = 0; j < N; j++) {
      A[j][i] -= mnv;
    }
    for (int j = 0; j < mnv; j++) {
      result.push_back(make_pair(false, i));
    }
  }

  bool ok = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (A[i][j]) {
        ok = false;
      }
    }
  }
  
  if (!ok) {
    cout << "-1\n";
  } else {
    cout << result.size() << '\n';
    for (auto i : result) {
      cout << (i.first ? "row " : "col ") << i.second + 1 << '\n';
    }
  }
  return 0;
}