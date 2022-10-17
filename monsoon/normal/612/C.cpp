#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1000100;
int n,se,ans;
char s[N],st[N],closing[256];
bool isopen[256];

void error() {
  puts("Impossible");
  exit(0);
}

int main() {
  scanf("%s",s);
  n = strlen(s);

  isopen['<'] = isopen['{'] = isopen['('] = isopen['['] = 1;
  closing['<'] = '>';
  closing['{'] = '}';
  closing['('] = ')';
  closing['['] = ']';

  REP(i,n) {
    if (isopen[s[i]]) st[se++] = s[i];
    else {
      if (se == 0) error();
      if (closing[st[se-1]] != s[i]) ++ans;
      --se;
    }
  }
  if (se != 0) error();
  printf("%d\n",ans);
}