#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstdio>

using namespace std;

#define MAXD (1 << 20)

int PI[MAXD];
pair<int, int> A[MAXD];

void solve(int lo, int hi, int d, int x, int y) {
  if (lo + 1 >= hi) {
    return;
  }

  int md = d >> 1;
  for (int xx = 0; xx < 2; xx++) {
    for (int yy = 0; yy < 2; yy++) {
      int nx = x + xx * md;
      int ny = y + ((yy + xx) % 2) * md;

      int olo = lo;
      for (int i = lo; i < hi; i++) {
        pair<int, int> v = A[i];
        if (nx <= v.first && v.first < nx + md &&
            ny <= v.second && v.second < ny + md) {
          swap(A[lo], A[i]);
          swap(PI[lo++], PI[i]);
        }
      }

      solve(olo, lo, md, nx, ny);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    PI[i] = i;
    scanf("%d%d", &A[i].first, &A[i].second);
  }

  solve(0, N, MAXD, 0, 0);
  for (int i = 0; i < N; i++) {
    if (i) cout << ' ';
    cout << PI[i] + 1;
  }
  cout << endl;

  return 0;
}