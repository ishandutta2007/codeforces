#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;
const int MAXQ=100000;

int n,nq;
int par[MAXN];
int ainit[MAXN],binit[MAXN];
int qkind[MAXQ],qidx[MAXQ],qval[MAXQ]; ll qans[MAXQ];

ll asum[MAXN],bsum[MAXN];

vector<int> ch[MAXN];
int pre[MAXN],fstpreidx[MAXN],lstpreidx[MAXN],npre;

int bsz,nb;
vector<int> blazy;
vector<vector<pair<ll,int>>> border;
vector<vector<pair<ll,ll>>> bpos;
vector<int> bposidx;
vector<vector<pair<ll,ll>>> bneg;
vector<int> bnegidx;
vector<ll> bmxneg;

void init(int b) {
	int l=b*bsz,r=min(n,(b+1)*bsz);
	FOR(i,l,r) border[b].PB(MP(bsum[pre[i]],pre[i]));
	sort(border[b].begin(),border[b].end());
}

ll overtake(const pair<ll,ll> &a,const pair<ll,ll> &b) {
	assert(a.first>b.first); assert(a.second<b.second);
	return (b.second-a.second+a.first-b.first-1)/(a.first-b.first);
}
void append(vector<pair<ll,ll>> &z,ll c,ll d) {
	//printf("\tappend(%lld,%lld)\n",c,d);
	int nz=SZ(z);
	while(nz>=1&&z[nz-1].second<=d) z.pop_back(),--nz;
	if(nz>=1) assert(c>=z[nz-1].first);
	if(nz>=1&&z[nz-1].first==c) return;
	while(nz>=1) {
		assert(c>z[nz-1].first);
		ll t1=overtake(MP(c,d),z[nz-1]);
		if(nz==1) {
			if(t1>0) break;
		} else {
			ll t2=overtake(z[nz-1],z[nz-2]);
			if(t1>t2) break;
		}
		z.pop_back(),--nz;
	}
	z.PB(MP(c,d));
}
void push(int b) {
	int l=b*bsz,r=min(n,(b+1)*bsz);
	FOR(i,l,r) asum[pre[i]]+=blazy[b];
	blazy[b]=0;
}
void rebuild(int b) {
	//printf("rebuild(%d)\n",b);
	int l=b*bsz,r=min(n,(b+1)*bsz);
	bmxneg[b]=LLONG_MIN;
	bpos[b].clear();
	bposidx[b]=0;
	REPSZ(_,border[b]) {
		int at=border[b][_].second;
		if(asum[at]>=0) {
			ll c=bsum[at],d=asum[at]*bsum[at];
			append(bpos[b],c,d);
		}
	}
	bneg[b].clear();
	bnegidx[b]=0;
	REPSZ(_,border[b]) {
		int at=border[b][SZ(border[b])-_-1].second;
		if(asum[at]<0) {
			bmxneg[b]=max(bmxneg[b],asum[at]);
			ll c=bsum[at],d=-asum[at]*bsum[at];
			append(bneg[b],-c,d);
		}
	}
}

void mod(int l,int r,int by) {
	if(l<=r&&l%bsz!=0) {
		int b=l/bsz;
		push(b);
		while(l<=r&&l%bsz!=0) { asum[pre[l]]+=by; ++l; }
		rebuild(b);
	}
	if(l<=r&&r%bsz!=bsz-1) {
		int b=r/bsz;
		push(b);
		while(l<=r&&r%bsz!=bsz-1) { asum[pre[r]]+=by; --r; }
		rebuild(b);
	}
	if(l<=r) {
		int bl=l/bsz,br=r/bsz;
		FORE(b,bl,br) blazy[b]+=by;
	}
}

ll eval(const pair<ll,ll> &a,int x) { return a.first*x+a.second; }
ll calc(vector<pair<ll,ll>> &z,int x,int &pos) {
	int nz=SZ(z);
	while(pos+1<nz&&eval(z[pos+1],x)>eval(z[pos],x)) ++pos;
	return pos<nz?eval(z[pos],x):LLONG_MIN;
}

ll bcalc(int b) {
	if(bmxneg[b]!=LLONG_MIN&&bmxneg[b]+blazy[b]>=0) { push(b); rebuild(b); }
	ll ret=LLONG_MIN;
	ret=max(ret,calc(bpos[b],blazy[b],bposidx[b]));
	ret=max(ret,calc(bneg[b],blazy[b],bnegidx[b]));
	return ret;
}

ll calc(int l,int r) {
	ll ret=LLONG_MIN;
	if(l<=r&&l%bsz!=0) {
		int b=l/bsz;
		push(b);
		while(l<=r&&l%bsz!=0) { ret=max(ret,abs(asum[pre[l]])*bsum[pre[l]]); ++l; }
		rebuild(b);
	}
	if(l<=r&&r%bsz!=bsz-1) {
		int b=r/bsz;
		push(b);
		while(l<=r&&r%bsz!=bsz-1) { ret=max(ret,abs(asum[pre[r]])*bsum[pre[r]]); --r; }
		rebuild(b);
	}
	if(l<=r) {
		int bl=l/bsz,br=r/bsz;
		FORE(b,bl,br) ret=max(ret,bcalc(b));
	}
	return ret;
}

void dfsinit(int at) {
	pre[npre]=at,fstpreidx[at]=npre,++npre;
	REPSZ(i,ch[at]) { int to=ch[at][i]; dfsinit(to); }
	lstpreidx[at]=npre-1;
}

void solve() {
	REP(i,n) { asum[i]=ainit[i]; if(par[i]!=-1) asum[i]+=asum[par[i]]; }
	REP(i,n) { bsum[i]=binit[i]; if(par[i]!=-1) bsum[i]+=bsum[par[i]]; }
	REP(i,n) bsum[i]=abs(bsum[i]);
	//printf("asum:"); REP(i,n) printf(" %lld",asum[i]); puts("");
	//printf("bsum:"); REP(i,n) printf(" %lld",bsum[i]); puts("");

	REP(i,n) ch[i].clear(); REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	npre=0; dfsinit(0); assert(npre==n);

	bsz=sqrt(1.0*n); nb=(n+bsz-1)/bsz;
	//printf("bsz=%d nb=%d\n",bsz,nb);
	blazy=vector<int>(nb,0);
	border=vector<vector<pair<ll,int>>>(nb);
	bpos=vector<vector<pair<ll,ll>>>(nb);
	bposidx=vector<int>(nb);
	bneg=vector<vector<pair<ll,ll>>>(nb);
	bnegidx=vector<int>(nb);
	bmxneg=vector<ll>(nb);
	REP(b,nb) init(b),rebuild(b);

	REP(i,nq) {
		//printf("processing %d\n",i);
		if(qkind[i]==1) {
			mod(fstpreidx[qidx[i]],lstpreidx[qidx[i]],qval[i]);
		}
		if(qkind[i]==2) {
			qans[i]=calc(fstpreidx[qidx[i]],lstpreidx[qidx[i]]);
		}
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	REP(i,n) scanf("%d",&ainit[i]);
	REP(i,n) scanf("%d",&binit[i]);
	REP(i,nq) { scanf("%d",&qkind[i]); if(qkind[i]==1) scanf("%d%d",&qidx[i],&qval[i]),--qidx[i]; if(qkind[i]==2) scanf("%d",&qidx[i]),--qidx[i]; }
	solve();
	REP(i,nq) if(qkind[i]==2) printf("%lld\n",qans[i]);
}

ll qchk[MAXQ];

ll stupidget(vector<ll> &a,vector<ll> &b,int at,int want,bool seen,ll aa,ll bb) {
	aa+=a[at],bb+=b[at]; if(at==want) seen=true;
	ll ret=LLONG_MIN;
	if(seen) ret=max(ret,abs(aa)*abs(bb));
	REPSZ(i,ch[at]) { int to=ch[at][i]; ret=max(ret,stupidget(a,b,to,want,seen,aa,bb)); }
	return ret;
}
void solvestupid() {
	vector<ll> a(n),b(n); REP(i,n) a[i]=ainit[i],b[i]=binit[i];
	REP(i,nq) {
		if(qkind[i]==1) {
			a[qidx[i]]+=qval[i];
		}
		if(qkind[i]==2) {
			qchk[i]=stupidget(a,b,0,qidx[i],false,0,0);
		}
	}
}

void stress() {
	int mxn=10,mxq=10,mxabsval=10;
	REP(rep,1000) {
		n=rand()%mxn+1; nq=rand()%mxq+1;
		par[0]=-1; FOR(i,1,n) par[i]=rand()%i;
		REP(i,n) ainit[i]=rand()%(2*mxabsval+1)-mxabsval;
		REP(i,n) binit[i]=rand()%(2*mxabsval+1)-mxabsval;
		REP(i,nq) { qkind[i]=rand()%2+1; if(qkind[i]==1) qidx[i]=rand()%n,qval[i]=rand()%mxabsval; if(qkind[i]==2) qidx[i]=rand()%n; }
		solve();
		solvestupid();
		bool ok=true; REP(i,nq) if(qkind[i]==2&&qans[i]!=qchk[i]) ok=false;
		if(ok) { printf("."); continue; }
		printf("err rep=%d\n",rep);
		printf("%d %d\n",n,nq);
		FOR(i,1,n) { if(i!=1) printf(" "); printf("%d",par[i]+1); } puts("");
		REP(i,n) { if(i!=0) printf(" "); printf("%d",ainit[i]); } puts("");
		REP(i,n) { if(i!=0) printf(" "); printf("%d",binit[i]); } puts("");
		REP(i,nq) { printf("%d %d",qkind[i],qidx[i]+1); if(qkind[i]==1) printf(" %d",qval[i]); puts(""); }
		printf("have:"); REP(i,nq) if(qkind[i]==2) printf(" %lld",qans[i]); puts("");
		printf("want:"); REP(i,nq) if(qkind[i]==2) printf(" %lld",qchk[i]); puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}