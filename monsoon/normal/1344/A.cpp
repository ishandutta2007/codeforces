#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 201000;
int _,n,a[N],was[N];

int real_mod(int x, int b) {
  if (x >= 0) return x % b;
  else return (b-((-x) % b)) % b;
}

int main() {
  scanf("%d",&_);
  while (_-->0) {
    scanf("%d",&n);
    REP(i,n) { scanf("%d",&a[i]); a[i] = real_mod(a[i] + i, n); }
    int mi = *min_element(a,a+n);
    int ok = 1;
    REP(i,n) {
      if (a[i]-mi >= n) ok = 0;
      if (was[a[i]-mi]) ok = 0;
      was[a[i]-mi] = 1;
    }
    REP(i,n) was[i] = 0;
    puts(ok ? "YES" : "NO");
  }
}