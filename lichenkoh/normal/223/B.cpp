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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=2e5+4;
string a,b;
int fw[mn],bk[mn];
int al,bl;
void go(int *f) {
  int bx=0;
  f[0]=bx;
  for (int i=0;i<al;i++) {
    if (a[i]==b[bx]) bx++;
    f[i+1]=bx;
  }
}
vector<int> v[28];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>a>>b;
  al=a.length(),bl=b.length();
  for (int x=0;x<bl;x++) {
    int c=b[x]-'a';
    v[c].PB(x);
  }
  go(fw);
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  go(bk);
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  for (int x=0;x<al;x++) {
    int p1=fw[x];
    int p2=bk[al-(x+1)];
    int c=a[x]-'a';
    int imin=0,imax=v[c].size();
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (v[c][imid]<=p1) imin=imid+1;
      else imax=imid;
    }
    int s1=0;
    if (imin>0) {
      s1=v[c][imin-1];
    }
    int s2=bl-s1-1;
    //printf("x:%d p1:%d s1:%d p2:%d s2:%d",x,p1,s1,p2,s2);
    if (v[c].size()==0||p2<s2) {
      printf("No\n");
      return 0;
    }
    //printf("Ok\n");
  }
  printf("Yes\n");
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