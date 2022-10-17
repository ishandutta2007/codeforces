#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 110000;
int n,k;
char s[N];

int main() {
  scanf("%d%d%s",&n,&k,s);
  REP(i,n-1) {
    if (k == 0) {
      break;
    }
    if (i%2 == 0 && s[i] == '4' && s[i+1] == '4' && i+2 < n && s[i+2] == '7') {
      k %= 2;
      if (k) { --k; s[i+1] = '7'; }
      break;
    }
    if (s[i] == '4' && s[i+1] == '7') {
      if (i%2 == 0) s[i+1] = '4';
      else s[i] = '7';
      --k; --i;
    }
  }
  puts(s);
}