#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N=200;
int n,cnt[10];
char s[N];

int main() {
  scanf("%d%s",&n,s);
  REP(i,n) { cnt[s[i]-'0']++; }
  int ile = min(cnt[8], n/11);
  printf("%d\n",ile);
}