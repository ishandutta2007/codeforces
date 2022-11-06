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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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

int readi()
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

char readc()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
const int mn=1e5+4;
bitset<mn> a;
bitset<mn> known;
bitset<mn> leader;
char vc[mn];
int vx[mn];
int b[mn];
vector<pair<int,char> > x2i[mn];
int query(int l, int r) {
  return b[r]-b[l-1];
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readi(),m=readi();
  for (int i=1;i<=m;i++) {
    vc[i]=readc(),vx[i]=readi();
  }
  for (int i=1;i<=m;i++) {
    char c=vc[i]; int x=vx[i];
    if (!known[x]) {
      //printf("x:%d\n",x);
      known[x]=1;
      if (c=='+') a[x]=0;
      else a[x]=1;
    }
  }
  for (int i=1;i<=m;i++) {
    char c=vc[i]; int x=vx[i];
    x2i[x].PB(MP(i,c));
  }
  int live=a.count();
  for (int i=1;i<=m;i++) {
    b[i]=live?1:0;
    char c=vc[i];
    if (c=='+') {
      live++;
    }
    else {
      live--;
    }
  }
  b[m+1]=live?1:0;
  for (int i=1;i<=m+1;i++) b[i]+=b[i-1];
  for (int x=1;x<=n;x++) {
    //printf("fx:%d\n",x);
    if (!known[x]) {
      //printf("x:%d\n",x);
      leader[x]=1;
      continue;
    }
    leader[x]=1;
    int last=0;
    for (auto &w:x2i[x]) {
      if (w.snd=='+') {
        int l=last+1,r=w.fst;
        if (query(l,r)){
          leader[x]=0;
        }
        last=-1;
      }
      else {
        last=w.fst;
      }
    }
    if (known[x]&&last!=-1) {
      int l=last+1,r=m+1;
      if (query(l,r)){
        leader[x]=0;
      }
    }
  }
  printf("%d\n",(int)leader.count());
  for (int x=1;x<=n;x++) {
    if (leader[x]) printf("%d ",x);
  }
  if(leader.count()>0) printf("\n");
}