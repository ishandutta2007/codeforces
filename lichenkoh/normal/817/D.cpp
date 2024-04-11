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
const int INF=1<<25;
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

const int mn=1000000;
pair<int,int> vp[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readInt();
  for (int i=0;i<n;i++) {
    int val=readInt();
    vp[i]=MP(val,i);
  }
  sort(vp,vp+n);
  ll final=0;
  ll sign=-1;
  for (int k=0;k<2;k++) {
    set<int> s;
    s.insert(-1); s.insert(n);
    for (int i=0;i<n;i++) {
      int x=vp[i].snd;
      auto got=s.insert(x);
      auto it=got.fst;
      auto lit=it; --lit;
      auto rit=it; ++rit;
      ll l=x-*lit; ll r=*rit-x;
      ll prod=l*r;
      ll val=(ll)vp[i].fst*(ll)prod*sign;
      //printf("vpifst:%d l:%lld r:%lld sign:%lld val:%lld\n",vp[i].fst,l,r,sign,val);
      final+=val;
    }
    reverse(vp,vp+n);
    sign=-sign;
  }
  printf("%lld\n",final);
}