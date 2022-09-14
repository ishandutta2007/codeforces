#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
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
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

typedef struct R { int lx,ly,hx,hy; R() {} R(int lx,int ly,int hx,int hy):lx(lx),ly(ly),hx(hx),hy(hy) {} } R;
bool operator==(const R &a,const R &b) { return a.lx==b.lx&&a.ly==b.ly&&a.hx==b.hx&&a.hy&&b.hy; }
bool inside(const R &a,const R &b) { return b.lx<=a.lx&&a.hx<=b.hx&&b.ly<=a.ly&&a.hy<=b.hy; }
R rot(int n,const R &a) { return R(a.ly,n-a.hx+1,a.hy,n-a.lx+1); }

int n;

typedef int (*processor)(R q);
pair<R,R> solve(processor proc) {
	int lx=1,ly=1,hx=n,hy=n;
	{ int l=lx,h=hx+1; while(l+1<h) { int m=l+(h-l)/2; if(proc(R(m,ly,hx,hy))==2) l=m; else h=m; } lx=l; }
	{ int l=ly,h=hy+1; while(l+1<h) { int m=l+(h-l)/2; if(proc(R(lx,m,hx,hy))==2) l=m; else h=m; } ly=l; }
	{ int l=lx-1,h=hx; while(l+1<h) { int m=l+(h-l)/2; if(proc(R(lx,ly,m,hy))==2) h=m; else l=m; } hx=h; }
	{ int l=ly-1,h=hy; while(l+1<h) { int m=l+(h-l)/2; if(proc(R(lx,ly,hx,m))==2) h=m; else l=m; } hy=h; }
	int LX=lx,LY=ly,HX=hx,HY=hy;
	{ int l=lx,h=hx+1; while(l+1<h) { int m=l+(h-l)/2; if(proc(R(m,ly,hx,hy))>=1) l=m; else h=m; } lx=l; }
	{ int l=ly,h=hy+1; while(l+1<h) { int m=l+(h-l)/2; if(proc(R(lx,m,hx,hy))>=1) l=m; else h=m; } ly=l; }
	{ int l=lx-1,h=hx; while(l+1<h) { int m=l+(h-l)/2; if(proc(R(lx,ly,m,hy))>=1) h=m; else l=m; } hx=h; }
	{ int l=ly-1,h=hy; while(l+1<h) { int m=l+(h-l)/2; if(proc(R(lx,ly,hx,m))>=1) h=m; else l=m; } hy=h; }
	R b(lx,ly,hx,hy); lx=LX,ly=LY,hx=HX,hy=HY;
	if(lx==b.lx&&lx+1<=hx&&proc(R(lx+1,ly,hx,hy))==1) ++lx;
	else if(ly==b.ly&&ly+1<=hy&&proc(R(lx,ly+1,hx,hy))==1) ++ly;
	else if(hx==b.hx&&hx-1>=lx&&proc(R(lx,ly,hx-1,hy))==1) --hx;
	else if(hy==b.hy&&hy-1>=ly&&proc(R(lx,ly,hx,hy-1))==1) --hy;
	else return MP(R(LX,LY,HX,HY),b);
	assert(proc(R(lx,ly,hx,hy))==1);
	{ int l=lx,h=hx+1; while(l+1<h) { int m=l+(h-l)/2; if(proc(R(m,ly,hx,hy))==1) l=m; else h=m; } lx=l; }
	{ int l=ly,h=hy+1; while(l+1<h) { int m=l+(h-l)/2; if(proc(R(lx,m,hx,hy))==1) l=m; else h=m; } ly=l; }
	{ int l=lx-1,h=hx; while(l+1<h) { int m=l+(h-l)/2; if(proc(R(lx,ly,m,hy))==1) h=m; else l=m; } hx=h; }
	{ int l=ly-1,h=hy; while(l+1<h) { int m=l+(h-l)/2; if(proc(R(lx,ly,hx,m))==1) h=m; else l=m; } hy=h; }
	R a(lx,ly,hx,hy);
	return MP(a,b);
}
int externalprocessor(R q) {
	printf("? %d %d %d %d\n",q.lx,q.ly,q.hx,q.hy); fflush(stdout);
	int ret; scanf("%d",&ret); return ret;
}
vector<R> ans; int nq;
int localprocessor(R q) {
	++nq; if(q.lx<1||q.ly<1||q.hx>n||q.hy>n||q.lx>q.hx||q.ly>q.hy) printf("? %d %d %d %d\n",q.lx,q.ly,q.hx,q.hy);
	int ret=0;
	REPSZ(i,ans) if(inside(ans[i],q)) ++ret;
	return ret;
}

void run() {
	scanf("%d",&n);
	pair<R,R> ret=solve(externalprocessor);
	printf("! %d %d %d %d %d %d %d %d\n",ret.first.lx,ret.first.ly,ret.first.hx,ret.first.hy,ret.second.lx,ret.second.ly,ret.second.hx,ret.second.hy); fflush(stdout);
}

void test(int n,R a,R b) {
	::n=n; ans.clear(); ans.PB(a); ans.PB(b);
	//printf("testing  %d %d %d %d %d %d %d %d\n",ans[0].lx,ans[0].ly,ans[0].hx,ans[0].hy,ans[1].lx,ans[1].ly,ans[1].hx,ans[1].hy);
	nq=0; pair<R,R> ret=solve(localprocessor); if(nq>=200) printf("%d queries\n",nq);
	bool ok=ret.first==ans[0]&&ret.second==ans[1]||ret.first==ans[1]&&ret.second==ans[0];
	if(!ok) printf("! %d %d %d %d %d %d %d %d -> %d %d %d %d %d %d %d %d\n",ans[0].lx,ans[0].ly,ans[0].hx,ans[0].hy,ans[1].lx,ans[1].ly,ans[1].hx,ans[1].hy,ret.first.lx,ret.first.ly,ret.first.hx,ret.first.hy,ret.second.lx,ret.second.ly,ret.second.hx,ret.second.hy);
	//printf("%s\n",ok?"ok":"ERROR!!!");
}
void testrot(int nrot,int n,R a,R b) {
	REP(i,nrot) a=rot(n,a),b=rot(n,b);
	test(n,a,b);
}

void testmanual() {
	R a,b; scanf("%d",&n); scanf("%d%d%d%d",&a.lx,&a.ly,&a.hx,&a.hy); scanf("%d%d%d%d",&b.lx,&b.ly,&b.hx,&b.hy);
	test(n,a,b);
}

void testcases() {
	printf("four sides\n");
	REP(lx,2) REP(hx,2) REP(ly,2) REP(hy,2) test(3,R(1,1,3,3),R(1+lx,1+ly,3-hx,3-hy));
	printf("three sides\n");
	REP(rot,4) REP(ly,2) REP(hy,2) REP(lx,4) testrot(rot,4,R(1,1,2,4),R(1+lx,1+ly,4,4-hy));
	printf("two sides - cross\n");
	test(3,R(2,1,2,3),R(1,2,3,2));
	printf("two sides - diag\n");
	REP(rot,4) REP(lx,4) REP(ly,4) testrot(rot,4,R(1,1,2,2),R(1+lx,1+ly,4,4));
}

int main() {
	run();
	//testmanual();
	//testcases();
	return 0;
}