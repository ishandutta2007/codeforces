#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

double dist(pair<int, int> x, pair<int, int> y) {
  return sqrt(1.0 * (x.first - y.first) * (x.first - y.first) +
              1.0 * (x.second - y.second) * (x.second - y.second));
}

int main() {
  int N, M; cin >> N >> M;

  vector<pair<int, int > > A;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      A.push_back(make_pair(i, j));
      A.push_back(make_pair(N - i, j));
      A.push_back(make_pair(N - i, M - j));
      A.push_back(make_pair(i, M - j));
    }
  }
  for(int i = 0; i < A.size(); i++) {
    if(A[i].first < 0 || A[i].first > N ||
       A[i].second < 0 || A[i].second > M) {
      A[i] = A.back();
      A.resize(A.size() - 1);
      i--;
    }
  }
  sort(A.begin(), A.end());
  A.resize(unique(A.begin(), A.end()) - A.begin());

  double best = -1;
  vector<int> S(4);
  vector<int> V(4);
  for(V[0] = 0; V[0] < A.size(); V[0]++)
  for(V[1] = 0; V[1] < A.size(); V[1]++)
  for(V[2] = 0; V[2] < A.size(); V[2]++)
  for(V[3] = 0; V[3] < A.size(); V[3]++) {
    if(set<int>(V.begin(), V.end()).size() != 4) continue;

    double res = 0;
    for(int i = 0; i < 3; i++) {
      res += dist(A[V[i]], A[V[i + 1]]);
    }
    if(res > best) {
      best = res;
      S = V;
    }
  }

  for(int i = 0; i < 4; i++) {
    cout << A[S[i]].first << ' ' << A[S[i]].second << '\n';
  }
  return 0;
}