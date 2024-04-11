#include <bits/stdc++.h>
using namespace std;

const long long INF = 8000000000000000000L;
const int N = 20100000;

int T, n, l, r, m;
unsigned int x, y, z, b[N];
long long Mi[N], Mx[N];
int a[N];

void Print(long long o) {
  if(o == INF) {
    printf("IMPOSSIBLE\n");
  } else {
    printf("%lld\n", o);
  }
}

int main(void) {
  //   cout << INF << endl;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d%d%u%u%u%u%u", &n, &l, &r, &x, &y, &z, &b[1], &b[2]);
    for(int i = 3; i <= n; i++) {
      b[i] = x * b[i - 2] + y * b[i - 1] + z;
    }
    for(int i = 1; i <= n; i++) {
      a[i] = (1LL * b[i] % (1LL * r - l + 1)) + l;
    }

    long long mi = a[1], Ans = INF;
    for(int i = 2; i <= n; i++) {
      if(mi < a[i])
	Ans = min(Ans, mi * a[i]);
      mi = min(mi, 1LL * a[i]);
    }
    for(int i = 1; i <= n; i++)
      a[i] = -a[i];
    reverse(a + 1, a + n + 1);

    mi = a[1];
    for(int i = 2; i <= n; i++) {
      if(mi < a[i])
	Ans = min(Ans, mi * a[i]);
      mi = min(mi, 1LL * a[i]);
    }
    Print(Ans);
  }
  return 0;
}