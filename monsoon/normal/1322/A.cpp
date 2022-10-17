#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1000100;
int n,cnt;
char s[N];
int opn,ans;

int main() {
  scanf("%d%s",&n,s);
  REP(i,n) { cnt += s[i] == '('; }
  if (n%2 || cnt != n/2) { puts("-1"); return 0; }
  for (int i=0; i<n; ++i) {
    if (s[i] == '(') opn++;
    else if (opn>0) opn--;
    else {
      int j=i;
      for ( ; j<n; ++j) {
        if (s[j] == ')') opn--;
        else if (opn<0) opn++;
        else {
          break;
        }
      }
      ans += j-i;
      i = j-1;
    }
  }
  printf("%d\n",ans);
}