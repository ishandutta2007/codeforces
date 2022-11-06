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
const int INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=100+4;
char s[mn]; int cst[mn];
char a[mn],b[mn];
int ac[mn],bc[mn];
int hc[255];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; scanf("%d\n%s\n",&n,s);
  for (int i=0;i<n;i++) cst[i]=rint();
  int sb=0; for (int i=0;i<n;i++) {
    sb+=cst[i];
  }
  int k=n/2;
  for (int i=0;i<k;i++) {
    a[i]=s[i];
    b[i]=s[n-1-i];
    ac[i]=cst[i];
    bc[i]=cst[n-1-i];
  }
  int ans=0;
  int hsum=0;
  for (int i=0;i<k;i++) {
    if (a[i]==b[i]) {
      ans+=min(ac[i],bc[i]);
      hc[a[i]]++;
      hsum++;
    }
  }
  for (int c='a';c<='z';c++) {
    if (hc[c]>hsum/2) {
      int exceed=0;
      while(hc[c]> (exceed+hsum)/2) exceed++;
      //printf("c:%c exceed:%d hc:%d hsum:%d\n",c,exceed,hc[c],hsum);
      vector<int> v;
      for (int i=0;i<k;i++) {
        if (a[i]!=c&&b[i]!=c&&a[i]!=b[i]) {
          int vi=min(ac[i],bc[i]);
          v.PB(vi);
          //if (vi==2) printf("%c%c\n",a[i],b[i]);
        }
      }
      sort(v.begin(),v.end());
      for (int i=0;i<exceed;i++) {
        //printf("vi: %d\n",v[i]);
        ans+=v[i];
      }
    }
  }
  int final=sb-ans;
  printf("%d\n",final);
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