#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 100100;
int n,a[N];

int main() {
  int ev=0,od=0;
  scanf("%d",&n);
  REP(i,n) scanf("%d",&a[i]);
  REP(i,n) { if (a[i]%2) od++; else ev++; }
  if (od && ev) { sort(a,a+n); }
  REP(i,n) { printf("%d ",a[i]); }
  printf("\n");
}