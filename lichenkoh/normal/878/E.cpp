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
const int INF=INT_MAX;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
//#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=100000+1;
int a[mn];
int n;
int norm(ll x) {
	x%=MOD; if (x<0) x+=MOD; return x;
}

const int THRES=2*1000*1000*1000 + 1;
const int THRESLEN=31;
ll vsig[mn];
ll ptwo[THRESLEN];
int vl[mn];
vector<int> vpos;
void initsig(int initx) {
	ll sig=a[initx];
	for (int x=initx-1;x>=1;) {
		if (a[x]>0) {
			int len=x-vl[x]+1;
			ll ptwosig;
			bool ovf=false;
			if (sig>0) {
				ovf|=(len>=THRESLEN)||__builtin_smulll_overflow(ptwo[len], sig, &ptwosig);
				sig=ptwosig; ovf|=(sig>=THRES);
			}
			else {
        assert(sig==0);
			}
			sig+=vsig[x]; ovf|=(sig>=THRES);
  		if (ovf) {
  			vsig[initx]=THRES;
  			vl[initx]=1;
  			return;
  		}
      if (sig<0) {
        dbg("A initx:%d x:%d sig:%lld\n",initx,x,sig);
        vsig[initx]=sig;
        vl[initx]=vl[x];
        return;
      }
			x=vl[x]-1;
		}
		else {
  		sig*=2;
  		sig+=a[x];
  		//printf("initx:%d x:%d sig:%lld\n",initx,x,sig);
  		if (sig>=THRES) {
  			vsig[initx]=THRES;
  			vl[initx]=1;
  			return;
  		}
  		if (sig<0) {
        dbg("B initx:%d x:%d sig:%lld\n",initx,x,sig);
  			vsig[initx]=sig;
  			vl[initx]=x;
  			return;
  		}
  		x--;
  	}
	}
	vsig[initx]=sig;
	vl[initx]=1;
}
int invp2mod[mn],p2mod[mn];
int vpre2[mn],vpreopt[mn],vopt[mn],vr[mn];
int queryp2(int l, int r) {
  if (l>r) return 0;
  return ((vpre2[r]-vpre2[l-1])*(ll)invp2mod[l])%MOD;
}
int queryopt(int l, int r) {
  if (l>r) return 0;
  return vpreopt[r]-vpreopt[l-1];
}
int solve(int l, int r, int base) {
  dbg("l:%d r:%d base:%d\n",l,r,base);
  ll final=0;
  int x=r;
  for (;x>=max(l,base+1);) {
    if (a[x]>0) {
      int lx=max(vl[x],l);
      int got=queryp2(lx,x);
      final+=got;
      dbg("x:%d bas:%d lx:%d got:%d\n",x,base,lx,got);
      x=lx-1;
    }
    else {
      final+=a[x]; x--;
      dbg("x:%d a[x]:%d\n",x,a[x]);
    }
  }
  int plus=0;
  if (vr[l]!=0) {
    int rr=min(vr[l],x);
    int prefix=queryp2(l,rr);
    int suffix=queryopt(rr+1,x);
    plus=prefix+suffix;
  }
  else {
    plus=queryopt(l,x);
  }
  dbg("l:%d x:%d plus:%d\n",l,x,plus);
  final+=plus;
  return norm(final);
}
vector<pii> vq[mn];
int vans[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  invp2mod[0]=1;
  const int inv2=(MOD+1)/2;
  for (int t=1;t<mn;t++) invp2mod[t]=(invp2mod[t-1]*(ll)inv2)%MOD;
  ptwo[0]=1;
  for (int t=1;t<THRESLEN;t++) {
  	ptwo[t]=(ptwo[t-1]*2);
  }
  n=rint(); int q=rint();
  int C=1;
  p2mod[0]=1;
  for (int x=1;x<=n;x++) {
    C*=2; if (C>=MOD) C-=MOD;
    dbg("x:%d C:%d\n",x,C);
    p2mod[x]=C;
  }
  for (int x=1;x<=n;x++) {
  	a[x]=rint();
  }
  for (int qi=1;qi<=q;qi++) {
    int l=rint(),r=rint();
    vq[r].PB(MP(qi,l));
  }
  for (int x=1;x<=n;x++) {
  	if (a[x]>0) initsig(x);
  }
  for (int x=1;x<=n;x++) {
    vpre2[x]=norm(vpre2[x-1]+p2mod[x]*(ll)a[x]);
    dbg("pre:%d %d\n",x,vpre2[x]);
  }
  int slim=sqrt(max(q,n))+1;
  //int slim=2;
  for (int r=1;r<=n;r++) {
    int base=(r/slim)*slim;
    if (r==base) {
      for (int x=1;x<=r;x++) vopt[x]=INF;
      for (int x=1;x<=r;x++) vr[x]=0;
      for (int x=r;x>=1;x--) {
        int l=vl[x];
        dbg("x:%d l:%d\n",x,l);
        if (l==0) continue;
        for (int y=l;y<=x;y++) {
          if (vopt[y]!=INF) break;
          vopt[y]=norm(a[y]*(ll)p2mod[y-l]);
          vr[y]=x;
          dbg("y:%d vopt:%d\n",y,vopt[y]);
        }
      }
      for (int x=1;x<=r;x++) if(vopt[x]==INF) {vopt[x]=a[x];if (vopt[x]<0) vopt[x]+=MOD;}
      for (int x=1;x<=r;x++) {
        dbg("x:%d vopt:%d\n",x,vopt[x]);
        vpreopt[x]=vpreopt[x-1]+vopt[x];
        if (vpreopt[x]>=MOD) vpreopt[x]-=MOD; 
      }
    }
    for (auto &qw:vq[r]) {
      int l=qw.snd;
      int final=solve(l+1,r,base);
      final=norm(a[l]+final*2LL);
      vans[qw.fst]=final;
    }
  }
  for (int qi=1;qi<=q;qi++) {
    printf("%d\n",vans[qi]);
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