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
//#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();


const int mn=5e5+2;
vector<int> g[mn];
class EulerEdge {
	static const int maxn=mn;
	typedef pair<int,int> pii;
	int w[maxn];

	typedef struct S {
	  int sum=0;
	  S () {sum=0;}
	  S(const int &x) {sum=x;}
	  S operator*(const S &b) const { // Must be commutative
	    return S(sum+b.sum);
	  }
	  void upd(int x) {
	    // The problem may require t[x]= g(\prod_{y \in neighbor(x)} t[y]).
	    // At this point in time, we have t[x]= \prod_{y \in neighbor(x)} t[y].
	    // So we now want to perform the operation t[x]=g(t[x]).
	    // This function performs that operation.
	    sum++;
	  }
	} S;
	S identity=S(0);
	typedef struct VS {
	  vector<S> prefix;
	  vector<S> suffix;
	} VS;
	S t[maxn];
	VS vt[maxn];
public:
	void euler_init(int x, int p) {
	  int numchildren=g[x].size() - ((p==-1)?0:1);
	  for (auto &y:g[x]) {
	    if (y==p) continue;
	    euler_init(y,x);
	    t[x]=t[x]*t[y];
	  }
	  t[x].upd(x);
	  {
	    S prefix=identity;
	    vt[x].prefix.resize(numchildren);
	    int id=0;
	    for (auto &y:g[x]) {
	      if (y==p) continue;
	      vt[x].prefix[id]=prefix;
	      prefix=prefix*t[y];
	      id++;
	    }
	  }
	  {
	    S suffix=identity;
	    vt[x].suffix.resize(numchildren);
	    int id=0;
	    for (auto it=g[x].rbegin();it!=g[x].rend();++it) {
	      int y=*it;
	      if (y==p) continue;
	      vt[x].suffix[id]=suffix;
	      suffix=suffix*t[y];
	      id++;
	    }
	    reverse(vt[x].suffix.begin(),vt[x].suffix.end());
	  }
	}

	vector<int> vodd[mn];

	void euler_edge(int x, int p) {
	  // Start custom code
	  if (p!=-1) {
	  	//dbg("x:%d p:%d t[x]:%d t[p]:%d\n",x,p,t[x],t[p]);
	  	if (t[p].sum&1) {
	  		//dbg("x:%d -> p:%d odd\n",x,p);
	  		vodd[x].PB(p);
	  	}
	  	if (t[x].sum&1) {
	  		//dbg("p:%d -> x:%d odd\n",p,x);
	  		vodd[p].PB(x);
	  	}
	  }
	  // End custom code
	  int yid=0;
	  for (auto &y:g[x]) {
	    if (y==p) continue;

	    S old_tx=t[x];
	    t[x]=vt[x].prefix[yid]*vt[x].suffix[yid];
	    if (p!=-1) {
	      t[x]=t[x]*t[p];
	    }
	    t[x].upd(x);

	    euler_edge(y,x);
	    t[x]=old_tx;

	    yid++;
	  }
	}
};
EulerEdge ee;

class TreeSize {
static const int maxn=mn;
public:
	int vsize[maxn];
	void rst() {}
	int dfs(int x, int p) {
		int ans=1;
		for (auto &y:g[x]) {
			if (y==p) continue;
			ans+=dfs(y,x);
		}
		vsize[x]=ans;
		return ans;
	}
};
TreeSize tss;

class MatchTree {
public:
	static const int maxn=mn;
	int match[mn];
	void rst() {}
	bool doMatch(int x, int p) { // True iff x is matched with a child
		bool matched=false;
		for (auto &y:g[x]) {
			if (y==p) continue;
			if (!doMatch(y,x)) {
				if (matched) {assert(false);}
				matched=true;
				dbg("match %d %d\n",x,y);
				match[x]=y; match[y]=x;
			}
		}
		return matched;
	}
};

MatchTree mtt;

class CustomDfs {
	static const int maxn=mn;
public:
	int dpf[maxn][2];
	void f(int x, int p) {
		for (auto &y:g[x]) {
			if (y==p) continue;
			f(y,x);
			int t=(mtt.match[x]==y);
			dpf[x][t]+=dpf[y][t^1];
		}
		dpf[x][0]++;
		dbg("x:%d p:%d dp0:%d dp1:%d\n",x,p,dpf[x][0],dpf[x][1]);
	}
	ll ans=0;
	void rst() {ans=0;}
	void dfs(int x, int p, bool flag=0) {
		dbg("x:%d tss:%d\n",x,tss.vsize[x]);
			if ((tss.vsize[x]&1)) {
				ans+=dpf[x][0];
				//printf("x:%d p:%d add:%d\n",x,p,dpf[x][0]);
			}
		for (auto &y:g[x]) {
			if (y==p) continue;
			if (flag!=(mtt.match[x]==y)) continue;
			dfs(y,x,flag^1);
		}
	}
};

CustomDfs customdfs;

class EulerEdgeM {
	static const int maxn=mn;
	typedef pair<int,int> pii;
	int w[maxn];
	typedef struct S {
	  int sum[2];
	  int sz=0;
	  S () {sum[0]=0;sum[1]=0;sz=0;}
	  S(const int &x, const int &y, const int &szz) {sum[0]=x; sum[1]=y; sz=szz;}
	  S operator*(const S &b) const { // Must be commutative
	    return S(sum[0]+b.sum[0],sum[1]+b.sum[1],sz+b.sz);
	  }
	} S;
	S identity=S(0,0,0);
	typedef struct VS {
	  vector<S> prefix;
	  vector<S> suffix;
	} VS;
	S t[maxn];
	VS vt[maxn];
  void upd(int x, int p) {
    // The problem may require t[x]= g(\prod_{y \in neighbor(x)} t[y]).
    // At this point in time, we have t[x]= \prod_{y \in neighbor(x)} t[y].
    // So we now want to perform the operation t[x]=g(t[x]).
    // This function performs that operation.
    t[x].sum[0]=t[x].sum[1];
    t[x].sum[1]=0;
    for (auto &y:g[x]) {
    	if (y==p) continue;
    	if (mtt.match[x]==y) {
    		t[x].sum[1]=t[y].sum[0];
    	}
    }
    t[x].sum[0]++;
    t[x].sz++;
    //dbg("x:%d p:%d s0:%d s1:%d sz:%d\n",x,p,t[x].sum[0],t[x].sum[1],t[x].sz);
  }

public:
	void euler_init(int x, int p) {
	  int numchildren=g[x].size() - ((p==-1)?0:1);
	  for (auto &y:g[x]) {
	    if (y==p) continue;
	    euler_init(y,x);
	    t[x]=t[x]*t[y];
	  }
	  upd(x,p);
	  {
	    S prefix=identity;
	    vt[x].prefix.resize(numchildren);
	    int id=0;
	    for (auto &y:g[x]) {
	      if (y==p) continue;
	      vt[x].prefix[id]=prefix;
	      prefix=prefix*t[y];
	      id++;
	    }
	  }
	  {
	    S suffix=identity;
	    vt[x].suffix.resize(numchildren);
	    int id=0;
	    for (auto it=g[x].rbegin();it!=g[x].rend();++it) {
	      int y=*it;
	      if (y==p) continue;
	      vt[x].suffix[id]=suffix;
	      suffix=suffix*t[y];
	      id++;
	    }
	    reverse(vt[x].suffix.begin(),vt[x].suffix.end());
	  }
	}

	vector<int> vodd[mn];

	ll finalmatch=0;
	ll finalun=0;

	void euler_edge(int x, int p) {
	  // Start custom code
	  if (p!=-1) {
	  	ll contrib;
	  	/*if (x==4) {
	  		for (int x=1;x<=6;x++) {
	  			dbg("SPEC x:%d s0:%d s1:%d sz:%d\n",x,t[x].sum[0],t[x].sum[1],t[x].sz);
	  		}
	  	}*/
	  	if (mtt.match[x]!=p) {
	  		int lft=t[x].sz;
	  		int rt=t[p].sz;
	  		contrib=lft*(ll)rt;
	  		//dbg("x:%d un p:%d. contrib: %d*%d=%lld\n",x,p,lft,rt,contrib);
	  	}
	  	else {
	  		int lft=(t[x].sum[0]);
	  		int rt=(t[p].sum[0]);
	  		contrib=lft*(ll)rt;
	  		//dbg("x:%d match p:%d. contrib: %d*%d=%lld\n",x,p,lft,rt,contrib);
	  	}
	  	finalmatch+=contrib;
	  }
	  // End custom code
	  int yid=0;
	  for (auto &y:g[x]) {
	    if (y==p) continue;

	    S old_tx=t[x];
	    t[x]=vt[x].prefix[yid]*vt[x].suffix[yid];
	    if (p!=-1) {
	      t[x]=t[x]*t[p];
	    }
	    upd(x,y);
	    euler_edge(y,x);
	    t[x]=old_tx;

	    yid++;
	  }
	}
};
EulerEdgeM em;


void fail(int t) {
	//printf("t:%d\n",t);
	printf("0\n"); exit(0);
}
int search(int x, int p, int targ) {
	if (x==targ) return 0;
	for (auto &y:g[x]) {
		if (y==p) continue;
		int got=search(y,x,targ);
		if (got!=-1) return got+1;
	}
	return -1;
}

ll solve(int a, int ap, int b, int bp) {	
	mtt.doMatch(a,ap);
	customdfs.rst();
  customdfs.dfs(a,ap);
	ll lft=customdfs.ans;
	mtt.doMatch(b,bp);
	ll rt=customdfs.dpf[b][0];
	//printf("a:%d ap:%d b:%d bp:%d lft:%lld rt:%lld\n",a,ap,b,bp,lft,rt);
	return lft*rt;
}

ll head(int a, int ap, int b, int bp) {
	mtt.doMatch(a,ap);
	ll lft=customdfs.dpf[a][0];
	mtt.doMatch(b,bp);
	ll rt=customdfs.dpf[b][0];
	//printf("a:%d ap:%d b:%d bp:%d lft:%lld rt:%lld\n",a,ap,b,bp,lft,rt);
	return lft*rt;
}
bitset<mn> bspec;
int search2sum=0;
vector<int> vg;
bool search2(int x, int p, int targ) {
	//printf("s2:%d %d\n",x,p);
	if (x==targ) {
		search2sum+=bspec[x];
		//if (bspec[x])printf("ss:%d\n",x);
		return true;
	}
	for (auto &y:g[x]) {
		if (y==p) continue;
		int got=search2(y,x,targ);
		if (got) {
			int odds=0;
			for (auto &z:ee.vodd[x]) {
				if (z==p||z==y) continue;
				odds++;
			}
			if (p!=-1) {
				if (odds==0) {vg.PB(0);}
				else if (odds==1) {
					vg.PB(1);
				}
				else fail(10);
			}
			search2sum+=bspec[x];
			//if (bspec[x])printf("ss:%d\n",x);
			return true;
		}
	}
	return false;
}


class Diameter {
public:
	int dist[mn];
	int n;
	void init(int _n) {n=_n;}
	pii bfs(int init) {
		if (init==-1) return MP(-1,-1);
		for (int x=1;x<=n;x++) {dist[x]=INF;}
		queue<int> q;
		q.push(init);
		dist[init]=0;
		while(!q.empty()) {
			int x=q.front(); q.pop();
			int cand=dist[x]+1;
			for (auto &y:g[x]) {
				if (dist[y]>cand) {
					dist[y]=cand;
					q.push(y);
				}
			}
		}
		pii ans=MP(-1,-1);
		for (int x=1;x<=n;x++) {
			if (bspec[x]) chkmax(ans,MP(dist[x],x));
		}
		return ans;
	}
	pii getp(int init) {
		pii x=bfs(init);
		pii y=bfs(x.snd);
		return MP(x.snd,y.snd);
	}
};
Diameter diam;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  if (n&1) fail(1);
  for (int i=1;i<n;i++) {
  	int x=rint(),y=rint(); g[x].PB(y); g[y].PB(x);
  }
  ee.euler_init(1,-1);
  ee.euler_edge(1,-1);
  vector<int> vspec;
  for (int x=1;x<=n;x++) {
  	int sz=ee.vodd[x].size();
  	//dbg("x:%d sz:%d\n",x,sz);
  	assert(sz&1);
  	if (sz>3) {
  		fail(2);
  	}
  	else if (sz>1) {
  		assert(sz==3);
  		//if (special!=-1) fail(3);
  		bspec[x]=true;
  		//vspec.PB(x);
  		//printf("sp:%d sz:%d\n",x,sz);
  	}
  }
  diam.init(n);
  pii ends=diam.getp(1);
  //printf("emds %d %d\n",ends.fst,ends.snd);
  if (ends.fst!=-1) vspec.PB(ends.fst);
  if (ends.snd!=-1&&ends.snd!=ends.fst) vspec.PB(ends.snd);
  //printf("vspecsz:%d\n",vspec.size());
  if (vspec.size()>2) fail(4);
  if (vspec.size()==1) { // Tree has no matching.
  	int special=vspec[0];
  	tss.dfs(special,-1);
  	for (auto &x:ee.vodd[special]) {
  		mtt.doMatch(x,special);
  	}
  	customdfs.f(special,-1);
  	ll final=0;
  	for (auto &x:ee.vodd[special]) {
  		for (auto &y:ee.vodd[special]) {
  			if (x!=y) {
  				ll contrib=solve(x,special,y,special);
  				final+=contrib;
  			}
  		}
  	}
  	printf("%lld\n",final);
  }
  else if (vspec.size()==2) {
  	int special=vspec[0];
  	int s2=vspec[1];
  	search2(special,-1,s2);
  	if (search2sum!=bspec.count()) fail(9);
  	tss.dfs(special,-1);
  	vector<pii> g1, g2, ag;
  	bool found=0;
  	for (auto &x:ee.vodd[special]) {
  		if (-1==search(x,special,s2)) g1.PB(MP(x,special));
  		else found=1;
  	}
  	if (!found) fail(5);
  	found=1;
  	for (auto &x:ee.vodd[s2]) {
  		if (-1==search(x,s2,special)) g2.PB(MP(x,s2));
  		else found=1;
  	}
  	if (!found) fail(6);
  	//int dist=search(special,-1,s2);
  	//if ((dist&1)==0) {
  	//	assert(0);
  	//	fail(7);
  	//}
  	for (auto &x:g1) ag.PB(x);
  	for (auto &x:g2) ag.PB(x);
  	for (auto &x:ag) {
  		mtt.doMatch(x.fst,x.snd);
  	}
  	customdfs.f(special,-1);
  	ll final=0;
  	for (auto &x:g1) {
  		for (auto &y:g2) {
  			if (x!=y) {
  				{
  					ll contrib=solve(x.fst,x.snd,y.fst,y.snd);
  					dbg("x:%d y:%d contrib:%lld\n",x.fst,y.fst,contrib);
  					final+=contrib;
  				}
  				{
  					ll contrib=solve(y.fst,y.snd,x.fst,x.snd);
  					dbg("y:%d x:%d contrib:%lld\n",y.fst,x.fst,contrib);
  					final+=contrib;
  				}
  			}
  		}
  	}
  	int C=1;
  	int z=0;
  	for (auto &w:vg) {
  		//printf("w:%d\n",w);
  		if (w==0) z++;
  		else {
  			if (z!=0) fail(11);
  			C++;
  		}
  		if (z==2) {
  			z=0; C++;
  		}
  	}
  	if (z!=0) fail(12);
  	dbg("C:%d\n",C);
  	for (auto &x:g1) {
  		for (auto &y:g2) {
  			if (x!=y) {
  				{
  					ll contrib=head(x.fst,x.snd,y.fst,y.snd);
  					//printf("x:%d y:%d contrib:%lld*%d\n",x.fst,y.fst,contrib,C);
  					final+=contrib*C;
  				}
  			}
  		}
  	}
  	printf("%lld\n",final);
  }
  else {
  	assert(vspec.size()==0);
  	mtt.doMatch(1,-1);
  	em.euler_init(1,-1);
  	em.euler_edge(1,-1);
  	ll ans=em.finalmatch+em.finalun;
  	printf("%lld\n",ans);
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