#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 210000;
int n,b[N],a[N];

int main() {
  scanf("%d",&n);
  REP(i,n) { scanf("%d",&b[i]); }
  int m = 0;
  REP(i,n) {
    a[i] = b[i] + m;
    m = max(m, a[i]);
  }
  REP(i,n) printf("%d ",a[i]);
  printf("\n");
}