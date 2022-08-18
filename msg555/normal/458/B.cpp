#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAXN 100010

long long A[MAXN];
long long B[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;

  long long asum = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    asum += A[i];
  }

  long long bsum = 0;
  for(int i = 0; i < M; i++) {
    cin >> B[i];
    bsum += B[i];
  }

  sort(A, A + N);
  sort(B, B + M);

  long long res = asum + bsum;
  long long rem;

  rem = asum + bsum;
  for(int i = N - 1; i >= 0; i--) {
    rem -= A[i];
    res = min(res, rem);
    rem += bsum;
    if(rem > (asum + bsum) * 16) break;
  }

  rem = asum + bsum;
  for(int i = M - 1; i >= 0; i--) {
    rem -= B[i];
    res = min(res, rem);
    rem += asum;
    if(rem > (asum + bsum) * 16) break;
  }

  cout << res << endl;
  return 0;
}