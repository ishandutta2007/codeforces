#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 10100;
int q;
char s[N];

int main() {
  scanf("%s%d",s,&q);
  REP(i,q) {
    int l,r,k; scanf("%d%d%d",&l,&r,&k); --l;
    int nl = l + (long long)(k) * (r-l-1) % (r-l);
    rotate(s+l,s+nl,s+r);
  }
  puts(s);
}