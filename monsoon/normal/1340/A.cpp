#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 110000;
int _,n,p[N],pos[N],bl[N];

int main() {
  scanf("%d",&_);
  while (_-->0) {
    scanf("%d",&n);
    REP(i,n) { scanf("%d",&p[i]); --p[i]; }
    REP(i,n) pos[p[i]] = i;
    int can = 1;
    int ok = 1;
    REP(i,n) bl[i] = 0;
    bl[n] = 1;
    REP(i,n) {
      if (!can && p[pos[i]-1] != i-1) ok = 0;
      bl[pos[i]] = 1;
      can = bl[pos[i]+1];
    }
    puts(ok ? "Yes" : "No");
  }
}