#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
//#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
class SegTree {
	static const int mseg=2e5+8;
  typedef int STV;
  STV identity = INF;
  STV combine(const STV &x, const STV &y) {
    return min(x,y);
  }
  STV t[2*mseg];
  int segn;
  void _modify(int l, int r, const STV& value) {
    r++;
    int n=segn;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) {
        t[l] = combine(t[l], value);
        l++;
      }
      if (r&1) {
        --r;
        t[r] = combine(t[r], value);
      }
    }
  }

  STV _query(int p) {
    int n=segn;
    STV res = identity;
    for (p += n; p > 0; p >>= 1) res = combine(res, t[p]);
    return res;
  }
  vector<int> v;
  int bins(int key) {
    int imin=0,imax=v.size();
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (v[imid]<key) imin=imid+1;
      else imax=imid;
    }
    //printf("key:%d imin:%d\n",key,imin);
    return imin;
  }
public:
  void preload(vector<int> &_v) {
    v=_v;
    v.PB(-INF); v.PB(INF);
    sort(v.begin(),v.end());
    auto it = std::unique (v.begin(), v.end());
    v.resize(std::distance(v.begin(),it));
    //for (auto &w:v) dbg("%d ",w); dbg("\n");
    segn=v.size()+1;
    fill(t,t+2*segn,INF);
  }
  void modify(int lo, int ro, const STV& value) {
    int l=bins(lo);
    int r=bins(ro);
    if (v[r]>ro) r--;
    //dbg("lo:%d ro:%d l:%d r:%d value:%d\n",lo,ro,l,r,value);
    return _modify(l,r,value);
  }
  STV query(int ox) {
    int x=bins(ox);
    //dbg("x:%d ox:%d\n",x,ox);
    return _query(x);
  }
};
SegTree segt;

const int mn=1e5+4;
int vsummod[mn];
int a[mn];
ll vsum[mn];
int vredl[mn],vredr[mn],vreducedr[mn];
int cyc;
ll vtax[mn];
int vq[mn];
int vqmod[mn];

void norm(int &x) {x%=cyc; if (x<0) x+=cyc;}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),green=rint(),red=rint();
  cyc=green+red;
  for (int i=0;i<=n;i++) {
    a[i]=rint();
  }
  int qlim=rint();
  for (int qi=0;qi<qlim;qi++) {vq[qi]=rint(); vqmod[qi]=vq[qi]%cyc;}
  {
    int sum=0;
    for (int i=0;i<=n;i++) {
      int l=a[i];
      sum-=l; norm(sum);
      vsummod[i+1]=sum;
    }
  }
  for (int i=0;i<=n;i++) {vsum[i+1]=a[i]+vsum[i];}
  {
  	vector<int> vpreload;
    for (int id=n;id>=1;id--) {
      int redl=green+vsummod[id]; norm(redl);
      int redr=redl+red;
      vredl[id]=redl; vredr[id]=redr;
      int reducedr=redr; if (reducedr>=cyc) {reducedr-=cyc;}
      vreducedr[id]=reducedr;
      vpreload.PB(reducedr);
    }
    for (int qi=0;qi<qlim;qi++) {
    	vpreload.PB(vqmod[qi]);
    }
    vpreload.PB(0); vpreload.PB(cyc-1);
    segt.preload(vpreload);
  }
  {
    for (int id=n;id>=1;id--) {
      int redl=vredl[id];
      int redr=vredr[id];
      int reducedr=vreducedr[id];
      {
      	int qid=segt.query(reducedr);
      	ll restax=0;
      	if (qid!=INF) {
      		//ll len=vsum[qid]-vsum[id];
      		int tax=(vredr[qid]-redr)%cyc;
      		if (tax<0) tax+=cyc;
      		restax+=vtax[qid]+tax;
      	}
      	vtax[id]=restax;
      }
      if (redl<reducedr) {
      	segt.modify(redl,reducedr,id);
      }
      else {
      	segt.modify(redl,cyc-1,id);
      	segt.modify(0,reducedr,id);
      }
    }
  }
  {
  	
  	for (int qi=0;qi<qlim;qi++) {
  		int init=vq[qi];
  		int initmod=vqmod[qi];
  		int qid=segt.query(initmod);
  		ll sumtax=0;
  		if (qid!=INF) {
  			//ll len=vsum[qid];
      	int timeAtQid=initmod;
      	int tax=(vredr[qid]-timeAtQid)%cyc;
      	sumtax=vtax[qid]+tax;
      	//dbg("timeAtQid:%d vredrqid:%d tax:%d sumtax:%lld qid:%d\n",timeAtQid,vredr[qid],tax,sumtax,qid);
      }
      ll final=sumtax+vsum[n+1]+init;
      printf("%lld\n",final);
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