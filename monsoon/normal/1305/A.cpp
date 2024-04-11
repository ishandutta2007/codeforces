#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 110;
int _,n,a[N],b[N];

int main() {
  scanf("%d",&_);
  while (_-->0) {
    scanf("%d",&n);
    REP(i,n) scanf("%d",&a[i]);
    REP(i,n) scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    REP(i,n) printf("%d ",a[i]);
    printf("\n");
    REP(i,n) printf("%d ",b[i]);
    printf("\n");
  }
}