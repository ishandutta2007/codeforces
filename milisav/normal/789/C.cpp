#include <cstdio>
using namespace std;
#define lli long long int
#define maxN 100000
#define max(a, b) a>b?a:b
#define min(a, b) a>b?b:a

int n;
lli a[maxN];
lli s[maxN + 1];
lli maX;

int f(int x, int s) {
  if (s == 0) {
    if (x >= 0)
      return x;
    return -x;
  }
  if (x >= 0)
    return -x;
  return x;
}

lli p[4];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  s[0] = 0;
  for (int i = 1; i < n; i++)
    s[i] = s[i - 1] + f(a[i] - a[i - 1], (i & 1)^1);
  p[0] = p[1] = p[2] = p[3] = 0;
  maX = 0;
  for (int i = 1; i <= n; i++) {
    if ((i & 1) == 0) {
      maX = max(maX, s[i] - p[0]);
      maX = max(maX, p[3] - s[i]);
      p[0] = min(p[0], s[i]);
      p[1] = max(p[1], s[i]);
    }
    else {
      maX = max(maX, s[i] - p[0]);
      maX = max(maX, p[3] - s[i]);
      p[2] = min(p[2], s[i]);
      p[3] = max(p[3], s[i]);
    }
  }
  printf("%lld\n", maX);
}