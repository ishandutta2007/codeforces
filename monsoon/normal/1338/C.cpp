#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

ll A,B,C;

void solve(ll n) {
  ll i=0, len=1;
  while (len <= n) {
    n -= len;
    len *= 4;
    i++;
  }
  A = len + n;
  B = 2*len;
  ll x = n; i=0; len=1;
  while (x) {
    int c=x%4;
    if (c>=1) B += (5*len+1)/3;
    if (c>=2) B += (2*len+1)/3;
    if (c>=3) B -= (7*len-1)/3;
    x /= 4;
    i++;
    len *= 4;
  }
  x = n;
  while (x) {
    x /= 4;
    B += x;
  }
  C = A^B;
}


int main() {
  int _; scanf("%d",&_);
  while (_-->0) {
    ll n; scanf("%lld",&n); --n;
    solve(n/3);
    ll ans = A;
    if (n%3==1) ans = B;
    else if (n%3==2) ans = C;
    printf("%lld\n", ans);
  }
}