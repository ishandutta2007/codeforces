#include <bits/stdc++.h>
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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=4e5+4;
typedef struct ST {
  int ans,tag;
} S;
S seg[2*mn];

void upd(int il, int ir, int idx) {
  if (seg[idx].tag>0) {
    seg[idx].ans=ir-il+1;
  }
  else seg[idx].ans=(il==ir)?0:seg[idx<<1].ans+seg[(idx<<1)|1].ans;
}
void modify(int delta, int il, int ir, int ql, int qr, int idx) {
  if (ql<=il&&ir<=qr) {
    seg[idx].tag+=delta;
    upd(il,ir,idx);
    //printf("il:%d ir:%d ql:%d qr:%d tag:%d ans:%d\n",il,ir,ql,qr,seg[idx].tag,seg[idx].ans);
    return;
  }
  if (qr<il||ql>ir) return;
  int mid=(il+ir)>>1;
  modify(delta, il,mid,ql,qr,idx<<1);
  modify(delta, mid+1,ir,ql,qr,(idx<<1)|1);
  upd(il,ir,idx);
  //printf("il:%d ir:%d ql:%d qr:%d tag:%d ans:%d\n",il,ir,ql,qr,seg[idx].tag,seg[idx].ans);
}

vector<int> g[mn];
vector<pair<int,int> > hf[mn];
vector<pair<int,int> > hr[mn];
int enter[mn],leave[mn];
int id2v[mn];
int gid=-1;
void dfs(int x, int p) {
  enter[x]=++gid;
  //printf("enter x:%d gid:%d\n",x,gid);
  id2v[gid]=x;
  for (auto &y:g[x]) {
    if (y==p) continue;
    dfs(y,x);
  }
  leave[x]=++gid;
  //printf("exit x:%d gid:%d\n",x,gid);
}



void addrect(int xl, int xr, int yl, int yr) {
  hf[xl].PB(MP(yl,yr));
  hr[xr+1].PB(MP(yl,yr));
}
void addrect2(int a, int b) {
  int xl=enter[a],xr=leave[a];
  int yl=enter[b],yr=leave[b];
  addrect(xl,xr,yl,yr);
}
int vans[mn];
int main() 
{
  int n=rint(),m=rint();
  for (int i=1;i<n;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  dfs(1,-1);
  gid+=2;
  for (int i=0;i<m;i++) {
    int a=rint(),b=rint();
    addrect2(a,a);
    addrect2(a,b);
    addrect2(b,a);
    addrect2(b,b);
  }
  for (int x=0;x<gid;x++) {
    reverse(hr[x].begin(),hr[x].end());
    for (auto &w:hr[x]) {
      int yl=w.fst,yh=w.snd,delta=-1;
      //printf("x:%d yl:%d yh:%d delta:%d\n",x,yl,yh,delta);
      modify(delta,0,gid,yl,yh,1);
    }
    for (auto &w:hf[x]) {
      int yl=w.fst,yh=w.snd,delta=1;
      //printf("x:%d yl:%d yh:%d delta:%d\n",x,yl,yh,delta);
      modify(delta,0,gid,yl,yh,1);
    }
    int vtx=id2v[x];
    if (vtx!=0) {
      int score=seg[1].ans;
      int ans=max(0,(score/2)-1);
      vans[vtx]=ans;
      //printf("x:%d vtx:%d score:%d ans:%d\n",x,vtx,score,ans);
    }
  }
  for (int x=1;x<=n;x++) printf("%d ",vans[x]);
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

inline int rint()
{
  int x; scanf("%d",&x); return x;
  /*  readAhead(16);

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

    return neg ? -x : x;*/
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