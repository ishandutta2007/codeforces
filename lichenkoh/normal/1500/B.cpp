#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
/*
template<typename Key, typename Val> class Premap {
public:
  vector<Key> vkey;
  vector<Val> vval;
  void addkey(Key const& key) {
    vkey.PB(key);
  }
  void init() {
    makeunique(vkey);
    vval.resize(vkey.size());
  }
  bool contains(Key const& i) {
    int x=bins(vkey,i);
    return x<vkey.size()&&vkey[x]==i;
  }
  Val operator [](Key const& i) const {
    //assert(contains(i));
    return vval[bins(vkey,i)];
  }
  Val & operator [](Key const& i) {
    //assert(contains(i));
    return vval[bins(vkey,i)];
  }
};
*/
int rotationLen=-1;

template<typename T> int bins2(vector<T> &v, T key) {
  int vsz=v.size();
  int imin=0,imax=2*vsz;
  while(imin<imax) {int imid=(imin+imax)>>1;
    int vval=imid<vsz?v[imid]:(v[imid-vsz]+rotationLen);
    if (vval<key) imin=imid+1;else imax=imid;
  }return imin;
}


const int mn=500004;
pii color2bi[2*mn];
int pos2step[mn];
vpii firstbi2allbi[mn];
vi firstbi2vstep[mn];
ll an,bn,glen; vi a,b;
ll f(ll fwdstep) {
  ll same=0;
  for (ll fbi=0;fbi<bn;fbi++) {
    //printf("fbi:%lld\n",fbi);
    if (firstbi2allbi[fbi].size()==0) continue;
    auto &v=firstbi2vstep[fbi];
    if (v.size()) {
      for (auto &w: firstbi2allbi[fbi]) {
        ll bi=w.fst,basehits=w.snd;
        ll upstep=pos2step[bi]+fwdstep;
        ll uphits=bins2(v,(int)upstep);
        ll hits=uphits-basehits;
        //printf("fbi:%lld bi:%lld basehits:%lld uphits:%lld hits:%lld\n",fbi,bi,basehits,uphits,hits);
        same+=hits;
      }
    }
  }
  ll total=fwdstep*ll(bn);
  ll diff=total-same;
  //printf("diff:%lld\n",diff);
  return diff;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  an=rint(); bn=rint(); ll k=rlong();
  a.resize(an);b.resize(bn);
  for (int i=0;i<an;i++) a[i]=rint();
  for (int i=0;i<bn;i++) b[i]=rint();
  if (an<bn) {
    swap(an,bn); swap(a,b);
  }
  glen=__gcd(an,bn);
  for (ll g=0;g<glen;g++) {
    ll initpos=g;
    ll pos=initpos;
    ll step=0;
    while(1) {
      pos2step[pos]=step;
      pos+=bn; if (pos>=an) pos-=an;
      step++;
      if (pos==initpos) break;
    }
    rotationLen=step;
  }
  for (ll g=0;g<glen;g++) {
    ll sig=g+1;
    for (ll bi=g;bi<bn;bi+=glen) {
      ll color=b[bi];
      if (color2bi[color].snd!=sig) {
        color2bi[color]=MP(bi,sig);
      }
    }
    for (ll ai=g;ai<an;ai+=glen) {
      ll color=a[ai];
      if (color2bi[color].snd==sig) {
        ll bi=color2bi[color].fst;
        ll step=pos2step[ai];
        firstbi2vstep[bi].PB(step);
        //printf("ai:%lld bi:%lld\n",ai,bi);
      }
    }
    for (ll bi=g;bi<bn;bi+=glen) {
      ll color=b[bi];
      ll firstbi=color2bi[color].fst;
      if (firstbi==bi) {
        sort(firstbi2vstep[bi].begin(),firstbi2vstep[bi].end());
      }
      //printf("firstbi:%lld bi:%lld\n",firstbi,bi);
      firstbi2allbi[firstbi].PB(MP(bi,-1));
    }
    for (ll obi=g;obi<bn;obi+=glen) {
      ll color=b[obi];
      ll firstbi=color2bi[color].fst;
      if (firstbi==obi) {
        auto & v=firstbi2vstep[firstbi];
        for (auto &w: firstbi2allbi[firstbi]) {
          ll bi=w.fst;
          ll step=pos2step[bi];
          ll basehits=bins2(v,(int)step);
          w.snd=basehits;
        }
      }
    }
  }
  //for (ll rot=2;rot<=2;rot++) {
  //  printf("rot:%lld f:%lld\n",rot,f(rot));
  //} exit(0);
  ll hitsPerRotation=f(rotationLen);

  ll rotations = k/hitsPerRotation;
  if (k%hitsPerRotation==0) rotations--;
  ll final=rotations*ll(bn)*ll(rotationLen);
  k-=rotations*hitsPerRotation;

  ll imin=0,imax=rotationLen+1;
  while(imin<imax) {
    ll imid=(imin+imax)/2;
    ll hits=f(imid);
    if (hits<k) imin=imid+1;
    else imax=imid;
  }
  imin=max(0LL,imin-1);
  k-=f(imin);
  ll initx=(imin*ll(bn));
  ll x=initx;
  ll ax=x%an,bx=x%bn;
  while(k>0) {
    if (a[ax]!=b[bx]) {
      --k;
    }
    ax++; if (ax==an) ax=0;
    bx++; if (bx==bn) bx=0;
    x++;
  }
  final+=x;
  printf("%lld\n",final);
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