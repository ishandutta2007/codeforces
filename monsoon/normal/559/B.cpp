#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=210000;
int n;
char a[N],b[N];

void go(int l, int p) {
  if ((p-l) % 2) return;
  int s = (p+l)/2;
  go(l, s);
  go(s, p);
  if (strncmp(a+l, a+s, s-l) > 0) { rotate(a+l, a+s, a+p); }
  if (strncmp(b+l, b+s, s-l) > 0) { rotate(b+l, b+s, b+p); }
}

int main() {
  scanf("%s%s",a,b);
  n = strlen(a);
  go(0, n);
  int same = strncmp(a, b, n) == 0;
  puts(same ? "YES" : "NO");
}