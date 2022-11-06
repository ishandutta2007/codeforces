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
int a[202];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readInt(),k=readInt();
  for (int i=0;i<n;i++) a[i]=readInt();
  int final=-(1<<30);
  for (int l=0;l<n;l++) for (int r=l;r<n;r++) {
    vector<int> b;
    int sum=0;
    for (int x=l;x<=r;x++) {
      b.PB(a[x]);
      sum+=a[x];
    }
    sort(b.begin(),b.end());
    vector<int> v;
    for (int x=0;x<l;x++) v.PB(a[x]);
    for (int x=r+1;x<n;x++) v.PB(a[x]);
    sort(v.begin(),v.end(),greater<int>());
    int ilim=min((int)v.size(),k);
    int bidx=0;
    int bsz=b.size();
    for (int i=0;i<ilim;i++) {
      if (v[i]>0) {
        sum+=v[i];
        if (bidx<bsz&&b[bidx]<0) {
          sum-=b[bidx];
          bidx++;
        }
      }
    }
    chkmax(final,sum);
  }	
  printf("%d\n",final);
}