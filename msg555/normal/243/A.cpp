#include <iostream>
#include <set>

using namespace std;

#define MAXN 100000
#define BITS 20

int A[MAXN + 1];
int nxt[MAXN + 1][BITS];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < BITS; i++) nxt[N][i] = N;
  for(int i = N - 1; i >= 0; i--) {
    for(int j = 0; j < BITS; j++) {
      nxt[i][j] = A[i] & 1 << j ? i : nxt[i + 1][j];
    }
  }

  set<int> st;
  for(int i = 0; i < N; i++) {
    int v = A[i];
    int j = i + 1;
    while(1) {
      st.insert(v);

      int nj = N;
      for(int k = 0; k < BITS; k++) {
        if(v & 1 << k) continue;
        nj = min(nxt[j][k], nj);
      }
      if(nj == N) break;

      v |= A[nj];
      j = nj + 1;
    }
  }
  cout << st.size() << endl;
}