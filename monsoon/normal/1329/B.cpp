#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

int _,d,m;

int solve() {
  int k = 1;
  int g = 1;
  int ans = 1;
  while (d >= (1<<k)) {
    ans = (ans + ll(g) * (1<<k) % m) % m;
    g = ll(g) * ((1<<k-1)+1) % m;
    k++;
  }
  ans = (ans + ll(g) * (d - (1<<k-1)) % m) % m;
  return ans;
}

int main() {
  scanf("%d",&_);
  while (_-->0) {
    scanf("%d%d",&d,&m);
    printf("%d\n",solve());
  }
}