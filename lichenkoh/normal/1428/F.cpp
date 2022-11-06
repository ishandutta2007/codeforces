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
const int mn=(5e5)+2;
vpii tseg;
int full[2][mn];
int clen[mn];
int n; string s;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n>>s;
  {
    int l=-1;
    for (int i=0;i<n;i++) {
      if (s[i]=='1') {
        if (l==-1) l=i;
      } else {
        if (l!=-1) {
          int r=i-1; int len=r-l+1;
          tseg.PB(MP(l,len));
          clen[len]++;
          l=-1;
        }
      }
    }
    if (l!=-1) {
      int r=n-1; int len=r-l+1;
      tseg.PB(MP(l,len));
      clen[len]++;
    }
  }
  ll dirSum=0;

  const bool DBG=0;  //////////////////////////////////////////////////////////////////////////////

  for (int k=0;k<2;k++) {
    vpii S;
    for (int q=0;q<tseg.size();q++) {
      auto seg=tseg[q];
      int al=seg.fst,alen=seg.snd; int ar=al+alen-1;
      int sublen=1;
      //int prevpos=al;
      bool fullset=false;
      while((!S.empty())) {
        int bl=S.back().fst,blen=S.back().snd; int br=bl+blen-1;
        //if (DBG) printf("alen:%d blen:%d\n",alen,blen);
        for(;sublen<=min(alen-1,blen);sublen++) {
          int pos=br-sublen+1;
          if (sublen==blen||k==1) pos++;
          dirSum += sublen * ll(max(0,al-pos));
          if(DBG)printf("k:%d q:%d sublen:%d al:%d pos:%d add:%lld\n",k,q,sublen,al,pos,sublen * ll(max(0,al-pos)));
          //prevpos=pos;
        }
        if (k==0&&alen==blen) {
          full[k][q]=al-(br-(alen-2));
          if(DBG)printf("C k:%d q:%d full:%d\n",k,q,full[k][q]);
          fullset=true;
        }
        if (blen > alen) break;
        S.pop_back();
      }
      if (S.empty()) {
        for(;sublen<=alen-1;sublen++) {
          dirSum += sublen * ll(al);
        }
        if (!fullset) {
          full[k][q]=al;
          if(DBG)printf("A k:%d q:%d full:%d\n",k,q,full[k][q]);
        }
      } else {
        int bl=S.back().fst,blen=S.back().snd; int br=bl+blen-1;
        if (!fullset) {
          full[k][q]=al-(br-(alen-1));
          if(DBG)printf("B k:%d q:%d full:%d\n",k,q,full[k][q]);
        }
      }
      S.PB(tseg[q]);
    }
    reverse(tseg.begin(),tseg.end());
    for (auto &seg:tseg) {
      int al=seg.fst,alen=seg.snd; int ar=al+alen-1;
      int nl=n-1-ar;
      seg.fst=nl;
    }
  }
  ll outerSum=0;
  for (int q=0;q<tseg.size();q++) {
    auto seg=tseg[q];
    int alen=seg.snd;
    int r=int(tseg.size())-1-q;
    outerSum+=(ll(full[0][q]+1)*ll(full[1][r]+1))*ll(alen);
  }
  ll innerSum=0;
  ll innerSingle=1;
  for (int len=1;len<mn;len++) {
    int numsegs=clen[len];
    innerSum += (innerSingle - len) * numsegs;
    innerSingle+=((len+2)*ll(len+1))/2;
  }
  if(DBG)printf("outer:%lld inner:%lld dirSum:%lld\n",outerSum,innerSum,dirSum);
  ll final=outerSum + innerSum + dirSum;
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