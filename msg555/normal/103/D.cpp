#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 300000
#define THRESH 400

int W[MAXN];
long long S[THRESH][THRESH];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> W[i];

  int M; cin >> M;
  vector<long long> R(M, -1);
  vector<pair<pair<int, int>, int> > V;
  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b; a--;
    if(b >= THRESH) {
      R[i] = 0;
      for(int j = a; j < N; j += b) {
        R[i] += W[j];
      }
    } else {
      V.push_back(make_pair(make_pair(a, b), i));
    }
  }
  memset(S, 0, sizeof(S));
  sort(V.begin(), V.end());
  int j = V.size() - 1;
  for(int i = N - 1; j >= 0; i--) {
    for(int k = 1; k < THRESH; k++) {
      S[k][i % k] += W[i];
    }
    while(j >= 0 && V[j].first.first == i) {
      R[V[j].second] = S[V[j].first.second][i % V[j].first.second];
      j--;
    }
  }

  for(int i = 0; i < M; i++) {
    cout << R[i] << '\n';
  }
}