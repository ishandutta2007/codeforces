#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

int N, M;

int V[1010];
int A[1010];
int B[1010];
vector<int> NX[1010];

struct state {
  int X, y;
  bool sd;
  double a, b;
};

double memo[1010][1010][2];

state next_st(int ind, int X, int Y) {
  state st;
  int X_ind = *lower_bound(NX[X].begin(), NX[X].end(), ind);
  int Y_ind = *lower_bound(NX[Y].begin(), NX[Y].end(), ind);
  st.y = min(X_ind, Y_ind);
  if(st.y == M) {
    st.a = 1; st.b = 0;
    st.X = X < Y ? 1 : 0;
    st.sd = false;
  } else if(st.y == Y_ind) {
    st.a = 1; st.b = 0;
    st.X = X;
    st.sd = A[st.y] == Y ? false : true;
  } else {
    st.a = -1; st.b = 1;
    st.X = Y;
    st.sd = A[st.y] == X ? false : true;
  }
  return st;
}

double solve(int X, int y, bool sd) {
  if(y == M) return X;

  int Y = (sd ? B : A)[y];
  int YP = (sd ? A : B)[y];
  if(YP == X) return 0.5;

  double& ref = memo[X][y][sd];
  if(ref >= 0) return ref;

  state s1 = next_st(y + 1, X, YP);
  state s2 = next_st(y + 1, X, Y);
  ref = 0.5 * (s1.b + s1.a * solve(s1.X, s1.y, s1.sd) +
               s2.b + s2.a * solve(s2.X, s2.y, s2.sd));
  return ref;
}

int main() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> V[i];
  for(int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    NX[A[i]].push_back(i);
    NX[B[i]].push_back(i);
  }
  for(int i = 0; i < 1010; i++) {
    sort(NX[i].begin(), NX[i].end());
    NX[i].push_back(M);
  }
  for(int i = 0; i < 1010; i++) for(int j = 0; j < 1010; j++) {
    memo[i][j][0] = memo[i][j][1] = -1;
  }

  double res = 0;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      state st = next_st(0, i, j);
      double p = st.b + st.a * solve(st.X, st.y, st.sd);
      if(V[i] < V[j]) p = 1 - p;
      res += p;
    }
  }
  printf("%.9f\n", res);
}