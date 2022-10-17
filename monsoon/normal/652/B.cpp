#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1100;
int n,a[N],b[N];

int main() {
  scanf("%d",&n);
  REP(i,n) scanf("%d",&a[i]);
  sort(a,a+n);
  REP(i,n-n/2) b[2*i] = a[i];
  REP(i,n/2) b[2*i+1] = a[i+n-n/2];
  REP(i,n) printf("%d ",b[i]);
  printf("\n");
}