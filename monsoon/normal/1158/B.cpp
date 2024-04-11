#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 100100;
int n,k;
char s[N];

int main() {
  scanf("%d%d",&n,&k);

  REP(i,n) s[i] = '0';

  int mask = 0;
  int z = (n-k)/2;
  if (k == 1) {
    s[0] = '1';
  } else {
    REP(i,n) {
      if (i%(z+1)==0) s[i] = '1';
    }
  }
  puts(s);
}