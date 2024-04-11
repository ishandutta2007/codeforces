#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=202;
bitset<6*mn> inp;
int pre[6*mn];
int good[6*mn][6*mn];
int type[6*mn][6*mn];

struct S {
  S() {}
  S(int _li,int _ri,int _src): li(_li),ri(_ri),src(_src) {}
  int li,ri,src;
};

S f[2*mn][2*mn][2];
struct Elem {
  Elem(int _e0,int _e1,int _e2){e[0]=_e0,e[1]=_e1,e[2]=_e2;}
  int e[3];
};
struct Group {
  vector<Elem> v;
};

const int EMPTY=1,SPLIT=2,TRIPLE=3;

int getcnt(int l, int r) {
  return pre[r]-pre[l-1];
}

Group go(int l, int r) {
  int mid=good[l][r];
  Group gl,gr,ans;
  Elem triple(-1,-1,-1);
  if (type[l][r]==EMPTY) {
    return ans;
  }
  if (type[l][r]==SPLIT) {
    gl=go(l,mid-1);
    gr=go(mid,r);
    // DP with gl,gr
  } else if (type[l][r]==TRIPLE) {
    gl=go(l+1,mid-1);
    gr=go(mid+1,r-1);
    triple=Elem(l,mid,r);
  } else assert(0);
  int bias=getcnt(l,r) > (r-l+1)/2 ? 1:0;
  int sl=gl.v.size(), sr=gr.v.size();
  for (int attempt=0;attempt<2;attempt++) {
    for (int li=0;li<=sl;li++) {
      for (int ri=0;ri<=sr;ri++) {
        for (int src=0;src<2;src++) {
          f[li][ri][src].li=-1;
        }
      }
    }
    if (attempt==1) {
      f[0][0][0]=S(0,0,0);
      f[0][0][1]=S(0,0,0);
    }
    else {
      if (0<sl && inp[gl.v[0].e[0]]) f[1][0][1]=S(0,0,0);
      if (0<sr && inp[gr.v[0].e[0]]) f[0][1][1]=S(0,0,0);
    }
    for (int li=0;li<=sl;li++) {
      for (int ri=0;ri<=sr;ri++) {
        if (li<sl) {
          int t=inp[gl.v[li].e[0]];
          for (int src=0;src<2;src++) {
            if (f[li][ri][src].li!=-1) {
              if (t!=src || t==bias) f[li+1][ri][t]=S(li,ri,src);
            }
          }
        }
        if (ri<sr) {
          int t=inp[gr.v[ri].e[0]];
          for (int src=0;src<2;src++) {
            if (f[li][ri][src].li!=-1) {
              if (t!=src || t==bias) f[li][ri+1][t]=S(li,ri,src);
            }
          }
        }
      }
    }
    for (int src=0;src<2;src++) {
      if (f[sl][sr][src].li!=-1) {
        if (triple.e[0]!=-1) {
          int t=inp[triple.e[0]];
          if (!(t!=src || t==bias)) continue;
          ans.v.PB(triple);
        }
        S now(sl,sr,src);
        for (int i=0;i<sl+sr;i++) {
          S prev=f[now.li][now.ri][now.src];
          if (prev.li==now.li-1) ans.v.PB(gl.v[prev.li]);
          else if (prev.ri==now.ri-1) ans.v.PB(gr.v[prev.ri]);
          else assert(0);
          now=prev;
        }
        reverse(ans.v.begin(),ans.v.end());
        /*printf("\nl:%d r:%d\n",l,r);
        for (auto &w:ans.v) {
          printf("%d %d %d\n",w.e[0],w.e[1],w.e[2]);
        }
        printf("\n");*/
        return ans;
      }
    }
  }
  assert(0);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<3*n;i++) {
    int x=rint(); inp[x]=true; pre[x]=1;
  }
  for (int x=1;x<=6*n;x++) pre[x]+=pre[x-1];
  memset(good,-1,sizeof good);
  for (int x=1;x<=6*n+1;x++) {
    good[x][x-1]=x;
    type[x][x-1]=EMPTY;
  }
  for (int len=3;len<=6*n;len+=3) {
    for (int l=1;l<=6*n-(len-1);l++) {
      int r=l+(len-1);
      for (int x=l+3;x<=r-2;x+=3) {
        if (good[l][x-1]!=-1 && good[x][r]!=-1) {
          good[l][r]=x; type[l][r]=SPLIT;
        }
      }
      if (good[l][r]==-1 && inp[l]==inp[r]) {
        for (int x=l+1;x<=r-1;x+=3) {
          if (inp[x]==inp[l] && good[l+1][x-1]!=-1 && good[x+1][r-1]!=-1) {
            good[l][r]=x; type[l][r]=TRIPLE;
            break;
          }
        }
      }
    }
  }
  assert(good[1][6*n]);
  Group final=go(1,6*n);
  for (auto &w:final.v) {
    printf("%d %d %d\n",w.e[0],w.e[1],w.e[2]);
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