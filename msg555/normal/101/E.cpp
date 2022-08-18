#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXV 20000
#define THRESH 10000

int X[MAXV];
int Y[MAXV];
int S[2][MAXV];
vector<bool> MOVE[THRESH];

int main() {
  int N, M, P; cin >> N >> M >> P;
  for(int i = 0; i < N; i++) {
    cin >> X[i];
    X[i] %= P;
  }
  for(int i = 0; i < M; i++) {
    cin >> Y[i];
    Y[i] %= P;
  }

  int a = N - 1;
  int b = M - 1;
  string result;
  for(int bb = (N - 1) / THRESH * THRESH; bb >= 0; bb -= THRESH) {
    memset(S, 0, sizeof(S));
    for(int i = 0; i < THRESH; i++) MOVE[i] = vector<bool>(M, false);
    for(int i = 0; i < min(bb + THRESH, N); i++) {
      int* SR = S[i & 1];
      int* SW = S[~i & 1];
      for(int j = 0; j < M; j++) {
        SW[j] = X[i] + Y[j];
        if(SW[j] >= P) SW[j] -= P;
        if(j > 0 && SW[j - 1] >= SR[j]) {
          SW[j] += SW[j - 1];
          if(bb <= i) MOVE[i - bb][j] = true;
        } else {
          SW[j] += SR[j];
        }
      }
      if(i + 1 == N) cout << SW[M - 1] << endl;
    }
    while(a >= bb && (a || b)) {
      if(!MOVE[a - bb][b]) {
        result += 'C';
        a--;
      } else {
        result += 'S';
        b--;
      }
    }
  }

  reverse(result.begin(), result.end());
  cout << result << endl;
  return 0;
}