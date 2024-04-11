#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

bool H[110];
int P[110];

int find(int x) {
  return P[x] == x ? x : P[x] = find(P[x]);
}

bool merge(int x, int y) {
  int X = find(x);
  int Y = find(y);
  if(X == Y) return false;
  P[X] = P[Y] = P[x] = P[y] = rand() & 1 ? X : Y;
  return true;
}

int main() {
  int N, M; cin >> N >> M;
  for(int i = 0; i < M; i++) {
    P[i] = i;
  }

  int count = 0;
  for(int i = 0; i < N; i++) {
    int K; cin >> K;

    if(K == 0) {
      count++;
    }

    int lst = -1;
    for(int j = 0; j < K; j++) {
      int x; cin >> x; x--;
      H[x] = true;
      if(lst != -1) {
        merge(x, lst);
      }
      lst = x;
    }
  }

  set<int> st;
  for(int i = 0; i < M; i++) {
    if(H[i]) {
      st.insert(find(i));
    }
  }
  if(st.empty()) {
    cout << N << endl;
  } else {
    cout << count + st.size() - 1 << endl;
  }
}