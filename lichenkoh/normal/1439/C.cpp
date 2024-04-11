#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end(),greater<int>());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]>key) imin=imid+1;else imax=imid;}return imin;}
const int segn=1<<19;  // array size
struct Seg {
typedef int S;
S t[2 * segn];
S identity = 0;
S combine(const S& lefts, const S& rights) {
  return lefts+rights;
}
void build() {  // build the tree
  int n=segn;
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}

void rawWrite(int p, const S& value) {
  t[p+segn]=value;
}

void setPosVal(int p, const S& value) { // set value at position p
  int n=segn;
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}
void combinePosVal(int p, const S&value) {
  //printf("Modify:%d %d\n",p,value);
  setPosVal(p, combine(value,t[p+segn]));
}

S query(int l, int r) { // sum on interval [l, r]
  r++;
  int n=segn;
  S resl=identity, resr=identity;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}

int getAtLeastWithinNode(int atleast, int l, int r, int p) {
  // Finds leftmost idx with sum at least atleast
  while(l+1!=r) {
    int m=(l+r)>>1;
    p=p<<1;
    if (atleast<=t[p]) {
      r=m;
    } else {
      atleast -= t[p];
      l=m;
      p|=1;
    }
  }
  //printf("atleast:%d l:%d r:%d t[p]:%d\n",atleast,l,r,t[p]);
  if (t[p] >= atleast) {
    return l;
  } else {
    return INF;
  }
}

// Returns MP(position, attainedAtleast)
int atleastFromZero(int atleast) {
  assert(__builtin_popcount(segn)==1); // Must be power of 2
  return getAtLeastWithinNode(atleast,0,segn,1);
}

/*
// Returns MP(position, attainedAtleast)
int atLeastFromPos(int fromPos, int atleast) {
  assert(__builtin_popcount(segn)==1); // Must be power of 2
  if (fromPos>=segn) return INF;
  int p=segn+fromPos,l=fromPos,r=fromPos+1;
  if (t[p] >= atleast) return fromPos;
  atleast -= t[p];
  while(p!=1) {
    assert(atleast>0);
    if ((p&1) == 0) {
      if (t[p^1] >= atleast) {
        return getAtLeastWithinNode(atleast, r, r+(r-l), p^1);
      } else {
        atleast -= t[p^1];
        r+=(r-l);
      }
    } else {
      l-=(r-l);
    }
    p=p>>1;
  }
  return INF; // No solution
}*/

};

const int mn=(2e5)+2;
int a[mn],qt[mn],qx[mn],qy[mn];
vi s2key;
int s2cnt[2*mn];
Seg seg;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int qn=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  for (int qi=0;qi<qn;qi++) {
    qt[qi]=rint(); qx[qi]=rint(); qy[qi]=rint();
  }
  s2key.reserve(n+qn);
  for (int i=0;i<n;i++) s2key.PB(a[i]);
  for (int qi=0;qi<qn;qi++) {
    if (qt[qi]==1) {
      s2key.PB(qy[qi]);
    }
  }
  makeunique(s2key);
  {
    int cnt=1;
    for (int p=1;p<=n;p++) {
      if (p==n||a[p]!=a[p-1]) {
        int s=bins(s2key,a[p-1]);
        s2cnt[s]=cnt;
        //printf("s:%d cnt:%d\n",s,cnt);
        seg.rawWrite(s,cnt);
        cnt=1;
      } else {
        ++cnt;
      }
    }
  }
  seg.build();
  for (int qi=0;qi<qn;qi++) {
    if (qt[qi]==1) {
      int newS=bins(s2key,qy[qi]);
      int needShops=qx[qi];
      int usedShops=seg.query(0,newS);
      int s=newS;
      while(usedShops < needShops) {
        s=seg.atleastFromZero(usedShops+1);
        if (s>=INF) break;
        int takeShops=min(needShops - usedShops,s2cnt[s]);
        seg.combinePosVal(s, -takeShops);
        seg.combinePosVal(newS, takeShops);
        s2cnt[s]-=takeShops;
        s2cnt[newS]+=takeShops;
        usedShops+=takeShops;
      }
    } else {
      int money=qy[qi];
      int ans=0;
      int s=seg.atleastFromZero(qx[qi]);
      int initS=s;
      int initCnt=seg.query(0,s) - qx[qi]+1;
      while(money>0) {
        chkmax(s, bins(s2key,money));
        if (s2cnt[s]==0) {
          s=seg.atleastFromZero(seg.query(0,s-1)+1);
        }
        if (s>=INF) break;
        int cnt;
        if (s==initS) {
          cnt=initCnt;
        } else {
          cnt=s2cnt[s];
        }
        int key=s2key[s];
        int take=cnt;
        if (money < cnt * ll(key)) {
          chkmin(take,money/key);
        }
        //printf("key:%d take:%d money:%d s:%d s2cnt:%d cnt:%d\n",key,take,money,s,s2cnt[s],cnt);
        ans+=take;
        money-=take*key;
        s++;
      }
      printf("%d\n",ans);
    }
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