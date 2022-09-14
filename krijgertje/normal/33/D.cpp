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
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
typedef struct F { int x,y,r; } F;
bool operator<(const F &a,const F &b) { return a.r<b.r; }

vector<int> parent;
vector<vector<int> > memupp;

int upp(int a,int p) {
	assert(SZ(memupp[a])>0);
	while(p>=SZ(memupp[a])) { int i=SZ(memupp[a])-1; memupp[a].PB(upp(upp(a,i),i)); }
	return memupp[a][p];
}

int up(int a,int cnt) {
	for(int i=0;i<=cnt;++i) if((cnt&(1<<i))!=0) { cnt-=1<<i; a=upp(a,i); } return a;
}

bool contains(const F &f,const P &p) {
//	printf("%lld vs %lld\n",(ll)(f.x-p.x)*(f.x-p.x)+(ll)(f.y-p.y)*(f.y-p.y),(ll)f.r*f.r);
	return (ll)(f.x-p.x)*(f.x-p.x)+(ll)(f.y-p.y)*(f.y-p.y)<=(ll)f.r*f.r;
}

void gen(int xl,int xr,int yl,int yr,vector<F> &f) {
	if(xl>xr||yl>yr) return;
	int xm=xl+(xr-xl)/2;
	int ym=yl+(yr-yl)/2;
	int r=min(min(xr-xm,xm-xl),min(yr-ym,ym-yl));
	if(r<=0) return;
	f.PB((F){xm,ym,r});
	gen(xm-r/2,xm-1,ym-r/2,ym-1,f);
	gen(xm-r/2,xm-1,ym+1,ym+r/2,f);
	gen(xm+1,xm+r/2,ym-r/2,ym-1,f);
	gen(xm+1,xm+r/2,ym+1,ym+r/2,f);
}

void run() {
	int ncontrol,nfence,nq; scanf("%d%d%d",&ncontrol,&nfence,&nq);
	vector<P> p(ncontrol); REP(i,ncontrol) scanf("%d%d",&p[i].x,&p[i].y);
	vector<F> f(nfence); REP(i,nfence) scanf("%d%d%d",&f[i].r,&f[i].x,&f[i].y); sort(f.begin(),f.end());
	
/*	ncontrol=10; nq=100000;
	p=vector<P>(ncontrol); REP(i,ncontrol) p[i].x=rand()%10000,p[i].y=rand()%10000;
	f.clear(); gen(0,10000,0,10000,f); nfence=SZ(f);
	REP(i,ncontrol) if(i<nfence) p[i].x=f[i].x,p[i].y=f[i].y; sort(f.begin(),f.end());
//	printf("%d %d %d\n",ncontrol,nfence,nq);
//	REPSZ(i,p) printf("%d %d\n",p[i].x,p[i].y);
//	REPSZ(i,f) printf("%d %d %d\n",f[i].r,f[i].x,f[i].y);  */
	
//	vector<bitset<2000> > bit(ncontrol);
//	REP(j,ncontrol) REP(i,nfence) bit[j][i] = contains(f[i],p[j])?1:0;
	
	vector<int> c2f(ncontrol,-1);
	REP(i,ncontrol) REP(j,nfence) if(contains(f[j],p[i])) { c2f[i]=j; break; }
	parent=vector<int>(nfence,-1);
	REP(i,nfence) FOR(j,i+1,nfence) if(contains(f[j],P(f[i].x,f[i].y))) { parent[i]=j; break; }
	vector<int> depth(nfence,-1);
	vector<int> root(nfence,-1);
	REP(i,nfence) if(parent[i]==-1) depth[i]=0,root[i]=i;
	REP(i,nfence) if(depth[i]==-1) {
		vector<int> path; int at=i; while(depth[at]==-1) { path.PB(at); at=parent[at]; }
		for(int j=SZ(path)-1;j>=0;--j) { at=path[j]; depth[at]=depth[parent[at]]+1,root[at]=root[parent[at]]; }
	}
	memupp=vector<vector<int> >(nfence); REP(i,nfence) if(parent[i]!=-1) memupp[i].PB(parent[i]);
	
//	REP(i,ncontrol) printf("%d => %d\n",i,c2f[i]);

	vector<int> ans(nq);
	REP(q,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		//int a=rand()%ncontrol,b=rand()%ncontrol;
		int aa=a+1,bb=b+1; a=c2f[a],b=c2f[b];
		if(a==-1&&b==-1) { ans[q]=0; continue; }
		if(a==-1) { ans[q]=depth[b]+1; continue; }
		if(b==-1) { ans[q]=depth[a]+1; continue; }
		if(root[a]!=root[b]) { ans[q]=depth[a]+1+depth[b]+1; continue; }
//		printf("%d %d [%d,%d]\n",a,b,depth[a],depth[b]);
		int cur=0;
		if(depth[a]>depth[b]) { cur+=depth[a]-depth[b]; a=up(a,depth[a]-depth[b]); }
		if(depth[b]>depth[a]) { cur+=depth[b]-depth[a]; b=up(b,depth[b]-depth[a]); }
		assert(depth[a]==depth[b]);
		if(a==b) { ans[q]=cur; continue; }
		int maxupp=0; while((1<<(maxupp+1))<=depth[a]) ++maxupp;
		for(int i=maxupp;i>=0;--i) {
			if((1<<i)>depth[a]) continue;
			int aa=upp(a,i),bb=upp(b,i);
			if(aa!=bb) { cur+=2<<i; a=aa,b=bb; }
		}
		assert(parent[a]==parent[b]);
		ans[q]=cur+2;
//		printf("%d vs %d\n",ans[q],(bit[aa - 1] ^ bit[bb - 1]).count());
//		assert(ans[q]==(bit[aa - 1] ^ bit[bb - 1]).count());
	}
	REP(i,nq) printf("%d\n",ans[i]);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}