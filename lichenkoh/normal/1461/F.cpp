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
const int TONES=-1;
const ll PRODLIM=INT_MAX;
const bool DBG=0;
vector<char> combine(vector<vector<char> > const & groups) {
  vector<char> vfinal;
  for (int i=0;i<groups.size();i++) {
    for (auto &w:groups[i]) vfinal.PB(w);
    if (i+1!=groups.size()) vfinal.PB('+');
  }
  return vfinal;
}
vector<char> go(vpii const &bin) {
  vpii b=bin;
  int n=b.size();
  if (n==0) return vector<char>();
  assert(n <= 2*17-1);
  assert(n%2==1);
  assert(b[0].snd!=TONES);
  assert(b.back().snd!=TONES);
  for (int i=1;i<n;i++) assert((b[i].snd==TONES)!=(b[i-1].snd==TONES));
  b.PB(MP(0,TONES));
  vpii f(n+2,MP(0,-1));
  for (int x=0;x<n;x+=2) {
    assert(b[x].snd!=TONES);
    int prod=1;
    for (int y=x+2;y<=n+1;y+=2) {
      if(DBG){if (b[y-1].snd!=TONES) printf("Not TONES y-1:%d\n",y-1);}
      assert(b[y-1].snd==TONES);
      assert(b[y-2].snd!=TONES);
      prod*=b[y-2].fst;
      int cand=prod+b[y-1].fst+f[x].fst;
      if(DBG)printf("x:%d y:%d cand:%d\n",x,y,cand);
      chkmax(f[y],MP(cand,x));
    }
  }
  vector<char> vans;
  int y=n+1;
  while(y>0) {
    int x=f[y].snd;
    int ones=b[y-1].fst;
    if(DBG)printf("y:%d f[y]:%d x:%d f[x]:%d ones:%d\n",y,f[y].fst,x,f[x].fst,ones);
    for (int i=0;i<ones;i++) vans.PB('+');
    int times=0;
    for (int p=y-2;p>=x;p--) {
      if (b[p].snd==TONES) {
        times+=b[p].fst;
      }
      else {
        times+=b[p].snd;
      }
      if (DBG)printf("p:%d b[p]:%d\n",p,b[p].snd);
    }
    if (DBG)printf("times:%d\n",times);
    if (vans.size()) vans.PB('+');
    for (int i=0;i<max(0,times-1);i++) vans.PB('*');
    y=x;
  }
  int symbols=0;
  for (int i=0;i<n;i++) {
    if (b[i].snd==TONES) symbols+=b[i].fst;
    else symbols+=b[i].snd;
  }
  if(DBG){
    for (auto &w:vans) printf("%c",w);
    printf(" go vans:%d symbols:%d\n",int(vans.size()),symbols);
  }
  assert(vans.size()==symbols-1);
  reverse(vans.begin(),vans.end());
  return vans;
}
vpii makeb(vi const & a) {
  int n=a.size();
  vpii b;
  int prod=1,prodseg=0; int ones=0;
  for (int i=0;i<n;i++) {
    if (a[i]==1) {
      if (prod>=2) {
        b.PB(MP(prod,prodseg));
        prod=1;prodseg=0;
      }
      ones++;
    } else {
      if(ones>0) {
        b.PB(MP(ones,TONES));
        ones=0;
      }
      prod=min(PRODLIM,prod*ll(a[i]));
      prodseg++;
    }
  }
  if (ones==0) {
    assert(prod>=2);
    b.PB(MP(prod,prodseg));
    prod=1;prodseg=0;
  } else {
    b.PB(MP(ones,TONES));
    ones=0;
  }
  if(DBG){
  for (auto &w:b) printf("%d %d\n",w.fst,w.snd);
  printf(" end b\n");
  }
  return b;
}
vector<char> solve(vi const & a) {
  int n=a.size();
  if (n==0) return vector<char>();
  vpii b=makeb(a);
  int pre=0,suf=0;
  if (b[0].snd==TONES) {
    pre=b[0].fst;
    b.erase(b.begin());
  }
  if (b.size()>=1 && b.back().snd==TONES) {
    suf=b.back().fst;
    b.pop_back();
  }
  int exc=pre+suf;
  int numones=-exc; for (auto &w:a) if (w==1) numones++;
  assert(numones>=0 && numones <n);
  int prod=1;
  for (auto &w:b) {
    if (w.snd!=TONES) {
      prod=min(PRODLIM, w.fst*ll(prod));
    }
  }
  ll lo=LLONG_MAX;
  int bsz=b.size();
  vector<vector<char> > groups;
  if (pre) {
    groups.PB(vector<char>(pre-1,'+'));
  }

  if(DBG)printf("prod:%d numones:%d\n",prod,numones);
  if (b.size()) {
    if (prod>=INT_MAX || b.size()>=50){
      groups.PB(vector<char>(max(0,n-exc-1),'*'));
    } else {
      groups.PB(go(b));
    }
  }
  if (suf) groups.PB(vector<char>(suf-1,'+'));
  vector<char> vfinal=combine(groups);
  if (DBG) {
    for (auto &w:a) printf("%d ",w);
    printf("end a. pre:%d suf:%d vfinalsz:%d n:%d\n",(int)pre,(int)suf,(int)vfinal.size(),n);
    for (auto &w:vfinal) printf("%c ",w);
    printf("end vfinal\n");
  }
  assert(vfinal.size() == n-1);
  return vfinal;
}
vector<char> plustimes(vi const & inp) {
  int n=inp.size();
  vector<vector<char> > groups;
  vi a;
  for (int i=0;i<=n;i++) {
    int x=(i==n)?0:inp[i];
    if (x==0) {
      if(a.size()) {
        groups.PB(solve(a));
      }
      if (i<n) groups.PB(vector<char>()); // Add 0
      a.clear();
    } else {
      a.PB(x);
    }
  }
  vector<char> vfinal=combine(groups);
  if(DBG){
    for (auto &w:inp) printf("%d ",w);
    printf("end a.vfinalsz:%d n:%d\n",(int)vfinal.size(),n);
    for (auto &w:vfinal) printf("%c ",w);
    printf("end vfinal\n");
  }
  assert(vfinal.size()==n-1);
  return vfinal;
}
vector<char> starminus(vi const & inp) {
  int n=inp.size();
  int zero=-1;
  for (int i=0;i<n;i++) {
    if (inp[i]==0) {zero=i; break;}
  }
  if (zero==-1||zero==0) {
    vector<char> vans(n-1,'*');
    return vans;
  } else {
    vector<char> vans;
    for (int i=0;i<zero-1;i++) vans.PB('*');
    vans.PB('-');
    for (int i=zero;i<n-1;i++) vans.PB('*');
    assert(vans.size()==n-1);
    return vans;
  }
}
vector<char> mainsolve(vi const & inp, string & s) {
  int n=inp.size();
  if (s.find('+') != -1 && s.find('*') != -1) {
    return plustimes(inp); 
  }
  if (s=="-*" || s=="*-") {
    return starminus(inp);
  }
  if (s.length()==1) {
    return vector<char> (n-1,s[0]);
  }
  s.erase(std::remove(s.begin(), s.end(), '-'), s.end());
  assert(s.length()==1);
  return vector<char> (n-1,s[0]);
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n; vi inp(n);
  for (int i=0;i<n;i++) cin>>inp[i];
  string s; cin>>s;
  vector<char> final=mainsolve(inp,s);
  assert(final.size()==n-1);
  for (int i=0;i<n;i++) {
    printf("%d",inp[i]);
    if (i!=n-1) printf("%c",final[i]);
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