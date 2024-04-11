#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

int N, M;
string CR[1010];
string CC[1010];

int A[1010][1010];

int count() {
  int cnt = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(i + 1 < N) {
        cnt += (A[i][j] == A[i + 1][j]) == (CC[i][j] == 'E');
      }
      if(j + 1 < M) {
        cnt += (A[i][j] == A[i][j + 1]) == (CR[i][j] == 'E');
      }
    }
  }
  return cnt;
}

int main() {
  int K;

  cin >> N >> M >> K;
  int T = (N - 1) * M + N * (M - 1);
  T = (T * 3 + 3) / 4;

  for(int i = 0; i + 1 < N; i++) {
    cin >> CR[i] >> CC[i];
  }
  cin >> CR[N - 1];

  if(K == 1) {
    if(count() < T) {
      cout << "NO" << endl;
      return 0;
    }
  } else {
    int NN, MM;
    if(N < M) {
      NN = 1;
      MM = 1 + M - N;
    } else {
      NN = 1 + N - M;
      MM = 1;
    }
    for(; NN <= N; NN++, MM++) {
      vector<pair<pair<int, int>, int> > V;
      for(int i = 0; i + 1 < NN; i++) {
        V.push_back(make_pair(make_pair(i, MM - 1), CC[i][MM - 1] == 'N'));
      }
      for(int i = MM - 1; i > 0; i--) {
        V.push_back(make_pair(make_pair(NN - 1, i), CR[NN - 1][i - 1] == 'N'));
      }
      V.push_back(make_pair(make_pair(NN - 1, 0), -1));

      int b = 0;
      int cnt = 0;
      int tcnt = 0;
      
      for(int i = 0; i < V.size(); i++) {
        int r = V[i].first.first;
        int c = V[i].first.second;
        if(r == NN - 1 && c == MM - 1) {
        } else if(r == NN - 1 && r > 0) {
          cnt += (b == A[r - 1][c]) == (CC[r - 1][c] == 'E');
          tcnt++;
        } else if(c == MM - 1 && c > 0) {
          cnt += (b == A[r][c - 1]) == (CR[r][c - 1] == 'E');
          tcnt++;
        }
        b ^= V[i].second;
      }

      b = cnt < tcnt - cnt;
      for(int i = 0; i < V.size(); i++) {
        int r = V[i].first.first;
        int c = V[i].first.second;
        A[r][c] = b;
        b ^= V[i].second;
      }
    }
  }
  //cerr << count() << "/" << T << endl;

  cout << "YES" << endl;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(j) cout << ' ';
      cout << A[i][j] + 1;
    }
    cout << endl;
  }

  return 0;
}