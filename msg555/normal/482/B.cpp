#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<pair<pair<int, int>, int> > A(M);
  for(int i = 0; i < M; i++) {
    cin >> A[i].first.first >> A[i].first.second >> A[i].second;
    A[i].first.first--;
  }

  vector<pair<int, pair<int, bool> > > E;
  for(int i = 0; i < M; i++) {
    E.push_back(make_pair(A[i].first.first, make_pair(A[i].second, true)));
    E.push_back(make_pair(A[i].first.second, make_pair(A[i].second, false)));
  }
  sort(E.begin(), E.end());

  int epos = 0;
  vector<int> X(N);
  vector<int> C(30);
  for(int i = 0; i < N; i++) {
    while(epos < E.size() && E[epos].first == i) {
      int m = E[epos].second.first;
      for(int j = 0; j < 30; j++) {
        if(m & 1 << j) {
          C[j] += E[epos].second.second ? 1 : -1;
        }
      }
      epos++;
    }
    for(int j = 0; j < 30; j++) {
      if(C[j]) {
        X[i] |= 1 << j;
      }
    }
  }

  for(int i = 0; i < M; i++) {
    swap(A[i].first.first, A[i].first.second);
  }
  sort(A.begin(), A.end());

  int apos = 0;
  vector<int> SF = X;
  for(int i = 0; i < N; i++) {
    for(int j = i - 1; j >= 0; j--) {
      if((SF[j] & SF[i]) == SF[j]) {
        break;
      }
      SF[j] &= SF[i];
    }
    while(apos < A.size() && A[apos].first.first == i + 1) {
      if (SF[A[apos].first.second] != A[apos].second) {
        cout << "NO\n";
        return 0;
      }
      apos++;
    }
  }

  cout << "YES\n";
  for(int i = 0; i < N; i++) {
    if(i) cout << ' ';
    cout << X[i];
  }
  cout << '\n';
  return 0;
}