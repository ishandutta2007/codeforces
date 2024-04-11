#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

void solve(int n, int m) {
  if (n == 1 && m == 0) { puts("1"); return; }

  int beg = n-1, cnt = 0, add = 2;
  while (beg && m > cnt) {
    beg--;
    cnt += add/2;
    ++add;
  }
  if (beg == 0) { puts("-1"); return; }

  vector<int> a;
  REP(i,n+1) {
    a.push_back(beg+i);
  }

  vector<int> used(n+1);
  int total = 0;
  REP(k,n+1) REP(j,k) {
    int i = k-j-beg;
    if (0 <= i && i < j) { ++used[i]; ++used[j]; ++used[k]; ++total; }
  }

  REP(i,n+1) if (m == total - used[i]) {
    a.erase(a.begin() + i);
    for(auto x : a) printf("%d ",x);
    printf("\n");
    return;
  }
}

int main() {
  int n,m; scanf("%d%d",&n,&m);
  solve(n,m);
}