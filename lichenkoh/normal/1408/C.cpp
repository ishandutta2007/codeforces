#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#include "bits/stdc++.h"
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sovrt(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
ld go() {
  int n=rint(); int LEN=rint();
  vi a; a.reserve(n+2);
  a.PB(0);
  for (int i=0;i<n;i++) a.PB(rint());
  a.PB(LEN);
  n+=2;
  vector<ld> vlt(n);
  {
    vlt[0]=0;
    for (int i=1;i<n;i++) {
      vlt[i]=vlt[i-1]+(a[i]-a[i-1])/((ld)i);
      //printf("L i:%d lt:%f\n",i,(double)vlt[i]);
    }
  }
  vector<ld> vrt(n);
  {
    vrt[n-1]=0;
    for (int i=n-2;i>=0;i--) {
      vrt[i]=vrt[i+1]+(a[i+1]-a[i])/((ld)(n-1-i));
      //printf("L i:%d rt:%f\n",i,(double)vrt[i]);
    }
  }
  int prcand=-1;
  for (int i=0;i<n;i++) {
    if (vrt[i]<vlt[i]) {prcand=i; break;}
  }
  {
    int p=prcand-1;
    ld lt=vlt[p],rt=vrt[p+1];
    ld ls=p+1;
    ld rs=n-p-1;
    ld d=a[p+1]-a[p];
    if (lt<rt) {
      d-=(rt-lt)*ls;
    } else {
      d-=(lt-rt)*rs;
    }
    //printf("p:%d d:%f ls:%f rs:%f\n",p,(double)d,(double)ls,(double)rs);
    return max(lt,rt)+(d/(ls+rs));
  }


}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t=rint();
  for (int i=0;i<t;i++) {
    ld final=go();
    printf("%.9f\n",(double)final);
  }
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