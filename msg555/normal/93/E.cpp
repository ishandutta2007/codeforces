#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

int N;
int A[100];

#define TV 10000

int tab[TV][100];

int comp(int V, int x) {
  if(x == N) return V;
  int& ref = tab[V][x];
  if(ref != -1) return ref;
  return ref = comp(V, x + 1) - comp(V / A[x], x + 1);
}

long long solve(long long V, int x) {
  if(V < TV) return comp(V, x);
  long long ret = V;
  for(; x < N; x++) {
    ret -= solve(V / A[x], x + 1);
  }
  return ret;
}

int main() {
  long long V; cin >> V >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  memset(tab, -1, sizeof(tab));
  sort(A, A + N);
  reverse(A, A + N);
  cout << solve(V, 0) << endl;
}