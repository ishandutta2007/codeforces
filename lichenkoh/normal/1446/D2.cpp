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

template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=200000;
const int mk=126;
const int mfreq=(mn+mk-2)/mk;
int f[mn];
int a[mn+1];
vi k2pos[mk];
int k2h[mk-1];
int h2l[mn+(mn/2)+1][mk-1];
int prevkhi[mn];
int p[mk-1][mn+1];

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int final=0,baseh=0;
  int n=rint(); vpii vcnt(n);
  for (int i=0;i<n;i++) {
    int k=rint()-1;
    a[i]=k;
    ++vcnt[k].fst;
  }
  for (int k=0;k<n;k++) vcnt[k].snd=k;
  sort(vcnt.begin(),vcnt.end(),greater<pii>());
  if (n==1) {
    printf("0\n"); return 0;
  }
  if (vcnt[0].fst == vcnt[1].fst) {
    printf("%d\n",n); return 0;
  }
  int freqlim=(mk<n)?vcnt[mk].fst:0;
  //const int freqlim=mfreq;

  int khi=min(mk,n)-1;
  //printf("freqlim:%d khi:%d\n",freqlim,khi);

  //printf("khi:%d\n",khi);
  swap(vcnt[0],vcnt[khi]);
  vi perm(n);
  for (int k=0;k<n;k++) perm[vcnt[k].snd]=k;
  for (int i=0;i<n;i++) {
    a[i]=perm[a[i]];
    //printf("i:%d a:%d\n",i,a[i]);
  }
  for (int i=0;i<n;i++) {
    int k=a[i];
    if (k<khi) {
      int sz=k2pos[k].size();
      k2pos[k].PB(i);
    }
  }
  prevkhi[0]=-1;
  for (int x=1;x<n;x++) {
    if (a[x-1]==khi) prevkhi[x]=x-1;
    else prevkhi[x]=prevkhi[x-1];
  }
  for (int k=0;k<khi;k++) {
    if (k==khi) continue;
    int idx=0;
    for (int x=0;x<=n;x++) {
      p[k][x]=idx;
      if (a[x]==k) idx++;
    }
  }

  for (int k=0;k<khi;k++) {
    h2l[mn][k]=1;
  }
  for (int r=0;r<n;r++) {
    int know=a[r];
    if (know==khi) {
      --baseh;
    } else if (know < khi) {
      ++k2h[know];
    }
    pii bestCntD=MP(-INF,-INF);
    for (int k=0;k<khi;k++) {
      int h=baseh + k2h[k];
      int l=h2l[h+mn][k];
      if (l==0) {
        h2l[h+mn][k]=r+2;
      }
      else {
        l--;
        int kli=p[k][l];
        int kri=p[k][r+1];
        //int kli=bins(k2pos[k], l);
        //int kri=bins(k2pos[k], r+1);
        int cnt=kri-kli;
        if (cnt>freqlim) {
          int prevl=prevkhi[l];
          if (kli>0) chkmax(prevl,k2pos[k][kli-1]);
          int dist=r-prevl;
          chkmax(bestCntD,MP(cnt,dist));
        }
      }
    }
    chkmax(final, bestCntD.snd);
  }
  
  for (int freq=1;freq<=freqlim;freq++) {
    if (freq!=1) memset(f,0,sizeof f);
    int r=0;
    int isfreq=0;
    for (int l=0;l<n;l++) {
      chkmax(r,l);
      while(r<n) {
        int k=a[r];
        if (f[k]<freq) {
          ++f[k];
          //printf("l:%d r:%d k:%d f[k]:%d\n",l,r,k,f[k]);
          if(freq==f[k]) {
            isfreq++;
          }
          r++;
        } else {break;}
      }
      //printf("l:%d r:%d isfreq:%d\n",l,r,isfreq);
      if (isfreq>=2) chkmax(final,r-l);
      {
        int k=a[l];
        if (f[k]==freq) isfreq--;
        --f[k];
      }
    }
  }
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