#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <complex>
#include <cstring>

using namespace std;

#define INF 1000000000000000000LL

long long DP[310][310];

int CHP[310][310];

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  vector<pair<pair<int, int>, int> > A(M);
  for(int i = 0; i < M; i++) {
    cin >> A[i].first.first >> A[i].first.second >> A[i].second;
    A[i].first.first--;
  }
  sort(A.begin(), A.end());

  int ind = 0;
  memset(CHP, -1, sizeof(CHP));
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j <= N; j++) {
      if(i) {
        CHP[i][j] = CHP[i - 1][j];
      }
    }
    while(ind < M && A[ind].first.first == i) {
      int& r = CHP[i][A[ind].first.second];
      if(r == -1 || A[ind].second < A[r].second) {
        r = ind;
      }
      ind++;
    }
  }

  for(int i = 0; i <= K; i++) {
    DP[N][i] = INF;
  }
  DP[N][0] = 0;
  
  for(int i = N - 1; i >= 0; i--) {
    for(int k = 0; k <= K; k++) {
      DP[i][k] = DP[i + 1][k];
      for(int j = i + 1; j <= N; j++) {
        if(CHP[i][j] != -1) {
          DP[i][k] = min(DP[i][k],
                         A[CHP[i][j]].second + DP[j][max(0, k - (j - i))]);
        }
      }
    }
  }
  
  if(DP[0][K] < INF) {
    cout << DP[0][K] << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}