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
typedef vector<vi> vvi;
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
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
const int mn=2e6+4;
int _idx=0;
char _prealloc[mn];
char * alloc(int sz) {
  char *ans=_prealloc+_idx;
  _idx+=sz;
  return ans;
}
char *t[mn];
char tmp[mn];
pii tab[mn];
char vfinal[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; scanf("%d",&n);
  int flen=0;
  for (int i=0;i<n;i++) {
    int k;
    scanf("%s %d",tmp,&k);
    int slen=strlen(tmp);
    t[i]=alloc(slen);
    memcpy(t[i],tmp,slen);
    for (int j=0;j<k;j++) {
      int x; scanf("%d",&x);
      //printf("i:%d k:%d x:%d\n",i,k,x); fflush(stdout);
      --x;
      chkmax(tab[x],MP(slen,i));
      chkmax(flen,slen+x);
    }
  }
  //memset(vfinal,'a',flen);
  int last=-1;
  for (int x=0;x<flen;x++) {
    if (tab[x].fst>0&&(last==-1||tab[x].fst+x>tab[last].fst+last)) {
      last=x;
    }
    if (last==-1) vfinal[x]='a';
    else {
      pii got=tab[last];
      int idx=x-last;
      int slen=got.fst;
      //printf("x:%d idx:%d got.snd:%d %c\n",x,idx,got.snd,t[got.snd][idx]);
      if (idx>=slen) vfinal[x]='a';
      else vfinal[x]=t[got.snd][idx];
    }
  }
  printf("%s\n",vfinal);
}