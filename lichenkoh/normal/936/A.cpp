#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll k,d,t; cin>>k>>d>>t;
  ll blocklen=((k+d-1)/d)*d;
  chkmin(k,blocklen);
  ld imin=0,imax=4*t;
  ld on=1.0L/t; ld off=1.0L/(2*t);
  ld blockcook=on*k+off*(blocklen-k);
  for (int i=0;i<500;i++) {
  	ld imid=(imin+imax)/2;
  	ll intpart=floor(imid);
  	ll blocks=intpart/blocklen;
  	ld blockscook=blocks*blockcook;
  	ll rem=intpart%blocklen;
  	ld res0;
  	{
  		ld x=rem;
  		res0=min(x,(ld)k)*on+max((ld)0.0,x-k)*off;
  	}
  	ld res1;
  	{
  		ld x=rem+1;
  		res1=min(x,(ld)k)*on+max((ld)0.0,x-k)*off;
  	}
  	ld res=res0+(res1-res0)*(imid-intpart);
  	ld final=blockscook+res;
  	//printf("imid:%f res:%f blockscook:%f blocklen:%lld res0:%f res1:%f\n",
  	//	imid,res,blockscook,blocklen,res0,res1);
  	if (final<1.0L) imin=imid;
  	else imax=imid;
  }
  printf("%.12f\n",(double)imin);
}




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

int rint()
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
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
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