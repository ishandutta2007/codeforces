#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const int INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int readInt()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
typedef pair<int,int> pii;
vector<pii> v[2];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; int c[2]; scanf("%d %d %d\n",&n,&c[0],&c[1]);
  for (int i=0;i<n;i++) {
    int b,p; char t;
    scanf("%d %d %c\n",&b,&p,&t);
    int type=(t=='C')?0:1;
    v[type].PB(MP(p,b));
  }
  int final=0;
  {
    int best[2];
    for (int type=0;type<2;type++) {
      best[type]=-INF;
      for (auto &w:v[type]) {
        if (w.fst<=c[type]) chkmax(best[type],w.snd);
      }
    }
    if (best[0]>=0&&best[1]>=0) chkmax(final,best[0]+best[1]);
  }
  {
    for (int type=0;type<2;type++) {
      sort(v[type].begin(),v[type].end());
      map<int,int,greater<int> > h;
      int best=0;
      for (auto &w:v[type]) {
        int leftc=c[type]-w.fst;
        if (leftc>=0) {
          auto it=h.lower_bound(leftc);
          if (it!=h.end()) {
            int cand=it->snd + w.snd;
            chkmax(final,cand);
          }
        }
        if (w.snd>=best) {
          chkmax(h[w.fst],w.snd);
          best=w.snd;
        }
      }
    }
  }
  final=max(final,0);
  printf("%d\n",final);
}