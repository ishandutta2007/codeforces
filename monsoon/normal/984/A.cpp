#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N=1100;
int n,a[N];

int main() {
  scanf("%d",&n);
  REP(i,n) scanf("%d",&a[i]);
  nth_element(a,a+(n-1)/2,a+n);
  printf("%d\n", a[(n-1)/2]);
}