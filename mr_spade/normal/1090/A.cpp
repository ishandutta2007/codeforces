#include <bits/stdc++.h>
using namespace std;

int n, m[201000], mx[201000], M;
long long Ans;

int main(void) {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &m[i]);
    for(int j = 1, x; j <= m[i]; j++) {
      scanf("%d", &x);
      mx[i] = max(mx[i], x);
    }
    M = max(M, mx[i]);
  }
  for(int i = 1; i <= n; i++) {
    Ans += 1LL * (M - mx[i]) * m[i];
  }
  cout << Ans << endl;
}