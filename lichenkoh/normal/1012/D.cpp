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
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

string inp[2];
vector<pii> oq[2];
vector<pii> q[2];
const int T=0,B=1;
vector<pii> vans;

void vadd(int k, pii &p) {
	if (q[k].size()==0) {
		q[k].push_back(p);
	}
	else {
		if (p.snd==q[k].back().snd) q[k].back().fst+=p.fst;
		else q[k].PB(p);
	}
}
const int mn=(5e5)+4;
template <typename LST> struct LimitedVec  {
  LST a[mn];
  int sz;
  void push_back(LST val) {
    a[sz++]=val;
  }
  LST * begin()
  {
    return &a[0];
  }
  LST * end()
  {
    return &a[sz];
  }
  void clear() {
    sz=0;
  }
};

LimitedVec<pii> g[2];
int tempc[2];
void sw(int top, int bot) {
	//printf("goswap top:%d bot:%d\n",top,bot);
	int vc[2]; vc[T]=top; vc[B]=bot;
	for (int k=0;k<2;k++) tempc[k]=0;
	for (int k=0;k<2;k++) g[k].clear();
	for (int k=0;k<2;k++) {
		for (int i=0;i<vc[k];i++) {
			tempc[k]+=q[k].back().fst;
			g[k].PB(q[k].back());
			q[k].pop_back();
		}
		reverse(g[k].begin(),g[k].end());
	}
	for (int k=0;k<2;k++) {
		for (auto &w:g[k^1]) vadd(k,w);
	}
	vans.PB(MP(tempc[0],tempc[1]));
}

vector<pii> final;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>inp[0]>>inp[1];
  for (int t=0;t<2;t++) {
  	int now=1;
  	int sz=inp[t].size();
  	for (int i=1;i<sz;i++) {
  		if (inp[t][i]!=inp[t][i-1]) {
  			oq[t].push_back(MP(now,inp[t][i-1]-'a')); now=1;
  		}
  		else now++;
  	}
  	oq[t].push_back(MP(now,inp[t][inp[t].size()-1]-'a'));
  	reverse(oq[t].begin(),oq[t].end());
  }
  int total=q[0].size()+q[1].size();
  int half=total/2;
  	for (int k=0;k<2;k++) q[k]=oq[k];
	  while(1) {
	  	/*for (int k=0;k<2;k++) {
	  		for (auto &w:q[k]) printf("(%d, %d) ",w.fst,w.snd);
	  		printf("\n");
	  	}*/
	  	if (q[0].size()==1 && q[1].size()==1 && q[0].back().snd!=q[1].back().snd) {
	  		break;
	  	}
	  	pair<pii,pii> best=MP(MP(1e9,1e9),MP(1e9,1e9));
	  	//int diffmod=(q[0].back().snd==q[1].back().snd)?1:0;
	  	for (int wanttop=half-2;wanttop<=half+2;wanttop++) {
	  		int wantbot=total-wanttop;
	  		int taketop,takebot;
	  		if (q[0].size()>wanttop) {
	  			takebot=1;
	  			taketop=q[0].size()-wanttop;
	  		}
	  		else {
	  			taketop=1;
	  			takebot=q[1].size()-wantbot;
	  		}
	  		for (int tt=taketop-2;tt<=taketop+2;tt++) {
	  			for (int bb=takebot-2;bb<=takebot;bb++) {
	  				if (0<=tt&&tt<=q[0].size()&&
	  					0<=bb&&bb<=q[1].size()&&
	  					tt+bb>0
	  					//abs(tt-bb)%2==diffmod
	  					) {
	  					int newtop=q[0].size()-tt+bb; if (q[0].size()>tt&&bb>0&&q[0][q[0].size()-1-tt].snd==q[1][q[1].size()-1-(bb-1)].snd) newtop--;
	  					int newbot=q[1].size()-bb+tt; if (q[1].size()>bb&&tt>0&&q[1][q[1].size()-1-bb].snd==q[0][q[0].size()-1-(tt-1)].snd) newbot--;
              //printf("tt:%d bb:%d newtop:%d newbot:%d\n",tt,bb,newtop,newbot);
	  					chkmin(best,MP(MP(newbot+newtop,abs(newtop-newbot)),MP(tt,bb)));
	  				}
	  			}
	  		}
	  	}
	  	//printf("Sw %d %d diffmod:%d\n",best.snd.fst,best.snd.snd,diffmod);
	  	//printf("\n");
	  	sw(best.snd.fst,best.snd.snd);
      assert(best.fst.fst==q[0].size()+q[1].size());
      assert(best.fst.snd==abs((int)q[0].size()-(int)q[1].size()));
	  }
  printf("%d\n",(int)vans.size());
  for (auto &w:vans) {
  	printf("%d %d\n",w.fst,w.snd);
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