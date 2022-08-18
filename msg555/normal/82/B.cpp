#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  int M = N * (N - 1) / 2;
  vector<vector<int> > S(M, vector<int>());
  for(int i = 0; i < M; i++) {
    int sz; cin >> sz;
    for(int j = 0; j < sz; j++) {
      int x; cin >> x;
      S[i].push_back(x);
    }
    sort(S[i].begin(), S[i].end());
  }
  int pivot = S[0][0];
  
  vector<int> V(1, pivot);
  vector<vector<int> > S2(1, S[0]);
  for(int i = 1; i < M; i++) {
    if(binary_search(S[i].begin(), S[i].end(), pivot)) {
      S2.push_back(S[i]);
      for(int j = 0; j < S[i].size(); j++) {
        if(binary_search(S[0].begin(), S[0].end(), S[i][j])) {
          V.push_back(S[i][j]);
        }
      }
    }
  }
  sort(V.begin(), V.end());
  V.resize(unique(V.begin(), V.end()) - V.begin());
  cout << V.size();
  for(int i = 0; i < V.size(); i++) {
    cout << ' ' << V[i];
  }
  cout << endl;
  for(int i = 0; i < S2.size(); i++) {
    cout << S2[i].size() - V.size();
    for(int j = 0; j < S2[i].size(); j++) {
      if(!binary_search(V.begin(), V.end(), S2[i][j])) {
        cout << ' ' << S2[i][j];
      }
    }
    cout << endl;
  }
}