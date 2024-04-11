#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 110000;
int _,n;
char s[N];

int main() {
  scanf("%d",&_);
  while (_-->0) {
    scanf("%d",&n);
    if (n == 1) {
      puts("-1");
    } else {
      s[0] = '4';
      REP(i,n-1) s[i+1] = '3';
      s[n] = 0;
      puts(s);
    }
  }
}