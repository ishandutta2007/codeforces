#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 500100;
int n,m;
map<int,int> mapa;
char s[N];

int val() {
  int v = 0;
  REP(i,m) {
    if (s[i] == '(') ++v;
    else if (--v < 0) return -1;
  }
  return v;
}

int main() {
  scanf("%d",&n);
  REP(i,n) {
    scanf("%s",s);
    m = strlen(s);
    int v = val();
    if (v >= 0) mapa[v]++;
    else {
      REP(i,m) s[i] = '(' + ')' - s[i];
      reverse(s,s+m);
      v = val();
      if (v > 0) mapa[-v]++;
    }
  }

  int ans = mapa[0] / 2;
  FORE(i,mapa) if (i->first > 0) ans += min(i->second, mapa[-i->first]);
  printf("%d\n",ans);
}