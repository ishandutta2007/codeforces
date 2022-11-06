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

int query(vi &v, int l, int r) {
  return v[r+1]-v[l];
}

vi prebc(string &s) {
  int n=s.length();
  vi res(n+1);
  for (int i=0;i<n;i++) {
    res[i+1]=res[i];
    if (s[i]!='A') res[i+1]++;
  }
  return res;
}

vi prea(string &s) {
  int n=s.length();
  vi res(n);
  int taila=0;
  for (int i=0;i<n;i++) {
    if (s[i]=='A') {
      taila++;
    }
    else {
      taila=0;
    }
    res[i]=taila;
  }
  return res;
}

int qa(vi &va, vi &vbc, int l, int r) {
  int qbc=query(vbc,l,r);
  if (qbc==0) {
    return va[r]-((l==0)?0:va[l-1]);
  }
  else return va[r];
}

const int S=1,T=0;
string s[2];
vi vbc[2],va[2];
int solve() {
  int l[2],r[2];
  for (int k=0;k<2;k++) {cin>>l[k]>>r[k]; l[k]--; r[k]--;}
  int bc[2],a[2];
  for (int k=0;k<2;k++) bc[k]=query(vbc[k],l[k],r[k]);
  for (int k=0;k<2;k++) a[k]=qa(va[k],vbc[k],l[k],r[k]);
  //for (int k=0;k<2;k++) {
  //  printf("k:%d. a:%d bc:%d\n",k,a[k],bc[k]);
  //}
  int k2=bc[S]-bc[T];
  if (k2<0||(k2%2!=0)) return 0;
  int k=k2/2;
  if (k==0) {
    int inca=a[T]-a[S];
    //printf("inca:%d\n",inca);
    return inca>=0 && (inca%3==0);
  }
  else {
    assert(bc[S]>0);
    if (bc[T]==0) {
      assert(bc[S]/2==k);
      return a[T]>=a[S]+1;
    }
    else {
      return a[T]>=a[S];
    }
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int k=0;k<2;k++) {
    cin>>s[k];
    vbc[k]=prebc(s[k]);
    va[k]=prea(s[k]);
  }
  int q; cin>>q;
  for (int i=0;i<q;i++) {
    int ans=solve();
    printf("%d",ans?1:0);
  }
  printf("\n");
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