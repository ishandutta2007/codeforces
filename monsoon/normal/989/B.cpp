#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 2100;
int n,p;
char s[N];

int main() {
  scanf("%d%d%s",&n,&p,s);
  REP(i,n) if (s[i] == '.') s[i] = '2';
  int ok = 0;
  REP(i,p) {
    int cnt[3] = {0,0,0};
    for(int j=i; j<n; j+=p) {
      cnt[s[j]-'0']++;
    }
    int start = 0;
    if (cnt[0] && cnt[1]) { ok = 1; }
    else if (cnt[0] && cnt[2]) { ok = 1; start = 1; }
    else if (cnt[1] && cnt[2]) { ok = 1; start = 0; }
    else if (cnt[2] >= 2) { ok = 1; }
    for(int j=i; j<n; j+=p) {
      if (s[j] == '2') {
        s[j] = '0'+start;
        start ^= 1;
      }
    }
  }
  puts(ok ? s : "No");
}