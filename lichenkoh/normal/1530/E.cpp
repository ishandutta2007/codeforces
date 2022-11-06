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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

void go() {
  string s; cin>>s;
  int n=s.length();
  vi h(26);
  for (auto &c:s) ++h[c-'a'];
  int hi=-INF;
  for (int c=0;c<26;c++) {
    chkmax(hi,h[c]);
  }
  if (hi==1||hi==n) {
    sort(s.begin(),s.end());
    cout<<s<<"\n";
    return;
  }
  int only=-1;
  for (int c=0;c<26;c++) {
    if (h[c]==1) {only=c; break;}
  }
  if (only!=-1) {
    vector<char> vfinal;
    vfinal.PB(only);
    --h[only];
    while(1) {
      int x=-1;
      for (int c=0;c<26;c++) {
        if (h[c]>0) {x=c; break;}
      }
      if (x==-1) break;
      vfinal.PB(x);
      --h[x];
    }
    for (int c=0;c<26;c++) {assert(h[c]==0);}
    assert(vfinal.size()==n);
    for (int i=0;i<n;i++) {vfinal[i]+='a';}
    string sfinal(vfinal.begin(),vfinal.end());
    cout<<sfinal<<"\n";
    return;
  }
  int a=-1;
  for (int c=0;c<26;c++) {
    if (h[c]>0) {a=c; break;}
  }
  int b=-1;
  for (int c=a+1;c<26;c++) {
    if (h[c]>0) {b=c; break;}
  }
  if (h[a]>=2 && h[a]-2<=n-h[a]) {
    vector<char> vfinal;
    vfinal.PB(a); vfinal.PB(a);
    h[a]-=2;
    while(1) {
      int x=-1;
      for (int c=a+1;c<26;c++) {
        if (h[c]>0) {x=c; break;}
      }
      if (x==-1) break;
      vfinal.PB(x);
      --h[x];
      if (h[a]>0) {
        vfinal.PB(a);
        --h[a];
      }
    }
    for (int c=0;c<26;c++) {assert(h[c]==0);}
    assert(vfinal.size()==n);
    for (int i=0;i<n;i++) {vfinal[i]+='a';}
    string sfinal(vfinal.begin(),vfinal.end());
    cout<<sfinal<<"\n";
    return;
  } else if (h[a]+h[b]==n) {
    vector<char> vfinal;
    vfinal.PB(a); --h[a];
    for (int i=0;i<h[b];i++) vfinal.PB(b);
    for (int i=0;i<h[a];i++) vfinal.PB(a);
    assert(vfinal.size()==n);
    for (int i=0;i<n;i++) {vfinal[i]+='a';}
    string sfinal(vfinal.begin(),vfinal.end());
    cout<<sfinal<<"\n";
    return;
  } else {
    vector<char> vfinal;
    assert(h[a]+h[b]<n);
    int q=-1;
    for (int c=b+1;c<26;c++) {
      if (h[c]>0) {q=c; break;}
    }
    vfinal.PB(a); --h[a];
    vfinal.PB(b); --h[b];
    while(1) {
      if (h[a]==0) break;
      vfinal.PB(a); --h[a];
    }
    vfinal.PB(q); --h[q];
    while(1) {
      int x=-1;
      for (int c=a+1;c<26;c++) {
        if (h[c]>0) {x=c; break;}
      }
      if (x==-1) break;
      vfinal.PB(x);
      --h[x];
    }
    for (int c=0;c<26;c++) {assert(h[c]==0);}
    assert(vfinal.size()==n);
    for (int i=0;i<n;i++) {vfinal[i]+='a';}
    string sfinal(vfinal.begin(),vfinal.end());
    cout<<sfinal<<"\n";
    return;
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) go();
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