#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();
//while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

vll a;
ll ci,cj,ck;
/*
ll query(ll l, ll r) {
  if (l>r) return 0;
  ll n=a.size(); --n;
  assert(1<=l&&l<=n);
  if(!(1<=r&&r<=n)) {
    printf("query l:%d r:%d n:%d\n",l,r,n);
    assert(0);
    exit(-1);
  }
  ll ans=0;
  for (ll x=l;x<=r;x++) {
    for (ll y=x+1;y<=r;y++) {
      if (a[x]>a[y]) ans++;
    }
  }
  return ans;
}
void out(ll i, ll j, ll k) {
  if (i!=ci || j!=cj || k!=ck) {
    printf("%lld %lld %lld. correct %lld %lld %lld\n",i,j,k,ci,cj,ck);
    exit(-1);
  } else {
    //printf(".");
  }
}
void check(ll D, ll E) {
  pll p=MP(cj-ci,ck-cj+1);
  if (MP(D,E)==p || MP(E,D)==p) {
    //printf(",");
  } else {
    printf("D:%lld E:%lld cor:%lld %lld\n",D,E,p.fst,p.snd);
  }
}
*/

ll query(ll l, ll r) {
  if (l>r) return 0;
  printf("? %lld %lld\n",l,r);
  fflush(stdout);
  ll ans; scanf("%lld",&ans);
  return ans;
}
void out(ll i, ll j, ll k) {
  printf("! %lld %lld %lld\n",i,j,k); fflush(stdout);
}

ll finde(ll all, ll d) {
  all -= (d*(d-1))/2;
  ll imin=0,imax=2e9;
  while(imin<imax) {
    ll imid=(imin+imax)/2;
    if (((imid-1)*imid)/2 < all) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
void go(ll n) {
  ll all=query(1,n);
  ll imin=1,imax=n+1;
  //printf("all:%lld\n",all);
  bool ok=0;
  while(imin<imax) {
    ll imid=(imin+imax)/2;
    ll left=query(imin,imid);
    //printf("imin:%lld imid:%lld imax:%lld left:%lld\n",imin,imid,imax,left);
    if (0<left && left<all) {
      ok=1;
      break;
    }
    if (left==all) {
      imax=imid+1;
    } else {
      assert(left==0);
      imin=imid;
    }
  }
  assert(ok);
  ll imid=(imin+imax)/2;
  assert(imid!=1);
  assert(imid!=n);
  //printf("Final imin:%lld imax:%lld imid:%lld\n",imin,imax,imid);
  ll dl=query(1,imid)-query(1,imid-1);
  ll dr=query(imid,n) - query(imid+1,n);
  ll farleft=query(1,imid-dl);
  //printf("dl:%lld dr:%lld farleft:%lld\n",dl,dr,farleft);
  ll D=dl+dr+1;
  if (farleft==0) {
    ll E=finde(all,D);
    ll i=imid-dl;
    ll j=i+D;
    ll k=j+E-1;
    out(i,j,k);
  } else {
    ll E=finde(all,D);
    ll k=imid+dr;
    ll j=k-(D-1);
    ll i=j-E;
    out(i,j,k);
  }
  
}

void test() {
  ll n=4+rand()%40;
  a.resize(n+1);
  for (ll i=1;i<=n;i++) a[i]=i;
  while(1) {
    ci=1+rand()%n;
    cj=1+rand()%n;
    ck=1+rand()%n;
    if (ci+1<cj && cj<ck) break;
  }
  reverse(a.begin()+ci,a.begin()+cj);
  reverse(a.begin()+cj,a.begin()+ck+1);
  //for (ll i=1;i<=n;i++) printf("%lld ",a[i]);
  //printf("\n");
  go(n);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //srand(1234);
  //for (ll i=0;i<900000;i++) test();
  //printf("Passed\n");
  //return 0;
  
  int t; scanf("%d",&t);
  for (int i=0;i<t;i++) {
    ll n; scanf("%lld",&n); go(n);
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