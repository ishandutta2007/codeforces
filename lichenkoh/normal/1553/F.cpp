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
using ll = __int128;
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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
int ilog2(int n) {
  return 31-__builtin_clz(n);
}
const int SQ=sqrt(3e5);
const int mx=(3e5)+4;
struct Fenwick {
    vector<ll> bit;  // binary indexed tree
    ll n;
    ll logn;
    void init(ll _n) {
      n = _n;
      logn=ilog2(n);
      bit.resize(n);
    }
 
    ll sum(ll r) {
      ll ret = 0;
      for (; r >= 0; r = (r & (r + 1)) - 1) {
        ret += bit[r];
      }
      return ret;
    }
    ll sum(ll l, ll r) {
      return sum(r) - sum(l - 1);
    }
 
    void add(ll _idx, ll delta) {
      for (ll idx=_idx; idx < n; idx = idx | (idx + 1)) {
        bit[idx] += delta;
      }
    }
};
Fenwick fenSumMul, fencnt;
int rawcnt[mx];
ll gpresum=0;
ll valModPre(ll ai, ll val) {
  ll all=val*ai;
  ll sub=fenSumMul.sum(val);
  ll tiny=0;
  for (ll s=1;s<SQ;s++) {
    tiny+=rawcnt[s]*s*(val/s);
  }
  //printf("\nai:%lld val:%lld all:%lld sub:%lld tiny:%lld\n",ai,val,all,sub,tiny);
  return all-sub-tiny;
}

ll preModVal(ll ai, ll val) {
  ll presum=gpresum;
  ll sub=0;
  for (ll k=0;k<mx;k+=val) {
    ll cnt=fencnt.sum(k, k+val-1);
    sub+=cnt*k;
  }
  return presum-sub;
}
ll preModSmall[mx], smallModPre[mx];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  fenSumMul.init(2*mx);
  fencnt.init(2*mx);
  int n; cin>>n;
  vi a(n);
  for (int i=0;i<n;i++) cin>>a[i];
  ll final=0;
  for (int ai=0;ai<n;ai++) {
    int val=a[ai];
    if (val<SQ) {
      final+=preModSmall[val];
      final+=smallModPre[val];
    } else {
      // val Mod pre
      final+= valModPre(ai,val);
      // pre mod val
      final+= preModVal(ai, val);
      //printf("\nai:%d val:%d vp:%lld pv:%lld\n",ai,val,valModPre(ai,val),preModVal(ai, val));
    }

    gpresum+=val;
    ++rawcnt[val];
    for (int s=1;s<SQ;s++) {
      preModSmall[s]+=val%s;
    }
    for (int s=1;s<SQ;s++) {
      smallModPre[s]+=s%val;
    }
    fencnt.add(val,1);
    if (val>=SQ) {
      for (ll k=val;k<mx;k+=val) {
        //if (k<=10) printf("add k:%lld\n",k);
        fenSumMul.add(k,val);
      }
    }

    printf("%lld ",(long long)final);
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