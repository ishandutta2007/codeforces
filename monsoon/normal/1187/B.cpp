#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 210000;
int n,q;
char s[N],t[N];
int len[26][N],cnt[26],Cnt[26];

int main() {
  scanf("%d%s%d",&n,s,&q);
  REP(i,n) {
    int ch = s[i]-'a';
    len[ch][++cnt[ch]] = i+1;
  }
  REP(i,q) {
    scanf("%s",t);
    int ans = 0;
    for(char* p=t; *p; p++) {
      int ch = *p-'a';
      ans = max(ans, len[ch][++Cnt[ch]]);
    }
    printf("%d\n", ans);
    for(char* p=t; *p; p++) {
      int ch = *p-'a';
      Cnt[ch] = 0;
    }
  }
}