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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=1000;

struct P { int x,y,col,id; P() {} P(int x,int y):x(x),y(y),col(-1),id(-1) {} };
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
ll side(const P &a,const P &b,const P &c) { return (b-a)^(c-a); }

int np;
P p[MAXN];

int nh;
P h[MAXN+1];

void makehull() {
	sort(p,p+np); nh=0; h[nh++]=p[0]; int tmp;
	tmp=nh; FOR(i,1,np) { while(nh>tmp&&side(h[nh-2],h[nh-1],p[i])<0) --nh; h[nh++]=p[i]; }
	tmp=nh; for(int i=np-2;i>=0;--i) { while(nh>tmp&&side(h[nh-2],h[nh-1],p[i])<0) --nh; h[nh++]=p[i]; }
	--nh;
}

vector<pair<int,int>> ans;

bool inside(const P &d,const P &a,const P &b,const P &c) {
	if(side(a,b,c)<0) return inside(d,a,c,b);
	return side(a,b,d)>0&&side(b,c,d)>0&&side(c,a,d)>0;
}
void solvetri(const P &a,const P &b,const P &c,const vector<P> &rem) {
	if(SZ(rem)==0) return;
	vector<int> cnt(2); ++cnt[a.col],++cnt[b.col],++cnt[c.col];
	int idx=-1; REPSZ(i,rem) { assert(cnt[rem[i].col]>0); if(cnt[rem[i].col]==1) { idx=i; break; } idx=i; }  assert(idx!=-1);
	P oth; if(a.col==rem[idx].col) oth=a; else if(b.col==rem[idx].col) oth=b; else if(c.col==rem[idx].col) oth=c; else assert(false); ans.PB(MP(oth.id,rem[idx].id));
	vector<P> remab,rembc,remca;
	REPSZ(i,rem) if(i!=idx) { if(inside(rem[i],rem[idx],a,b)) remab.PB(rem[i]); if(inside(rem[i],rem[idx],b,c)) rembc.PB(rem[i]); if(inside(rem[i],rem[idx],c,a)) remca.PB(rem[i]); }
	solvetri(rem[idx],a,b,remab); solvetri(rem[idx],b,c,rembc); solvetri(rem[idx],c,a,remca);
}
void solvetri(const P &a,const P &b,const P &c) {
	vector<P> rem; REP(i,np) if(inside(p[i],a,b,c)) rem.PB(p[i]);
	solvetri(a,b,c,rem);
}

bool solve() {
	ans.clear();
	makehull();
	//printf("h:"); REP(i,nh) printf(" (%d,%d,%d)",h[i].x,h[i].y,h[i].col); puts("");
	int l=INT_MAX,r=INT_MIN; bool any=false; REP(i,nh) if(h[i].col!=h[0].col) l=min(l,i),r=max(r,i),any=true;
	if(!any) {
		REP(i,nh-1) ans.PB(MP(h[i].id,h[i+1].id));
		int diff=-1; REP(i,np) if(p[i].col!=h[0].col) { diff=i; break; }
		if(diff!=-1) {
			REP(i,nh) solvetri(h[i],h[i+1],p[diff]);
		} else {
			FORE(i,1,nh-1) solvetri(h[0],h[i],h[i+1]);
		}
	} else {
		FORE(i,l,r) if(h[i].col==h[0].col) return false;
		REP(i,l-1) ans.PB(MP(h[i].id,h[i+1].id));
		FOR(i,l,r) ans.PB(MP(h[i].id,h[i+1].id));
		FOR(i,r+1,nh) ans.PB(MP(h[i].id,h[i+1].id));
		REP(i,l-1) solvetri(h[i],h[i+1],h[r]);
		FOR(i,l,r) solvetri(h[i],h[i+1],h[l-1]);
		FOR(i,r+1,nh) solvetri(h[i],h[i+1],h[r]);
	}
	return true;
}

void run() {
	scanf("%d",&np);
	REP(i,np) scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].col),p[i].id=i;
	if(!solve()) { printf("Impossible\n"); return; }
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) printf("%d %d\n",ans[i].first,ans[i].second);
}

void stress() {
	int mxcoord=1000;
	REP(rep,1000) {
		np=0; p[np++]=P(0,0),p[np++]=P(mxcoord,0),p[np++]=P(mxcoord,mxcoord),p[np++]=P(0,mxcoord);
		int nextra=20; REP(i,nextra) while(true) { P cur=P(rand()%(mxcoord+1),rand()%(mxcoord+1)); bool ok=true; REP(j,np) FOR(k,j+1,np) if(side(p[j],p[k],cur)==0) ok=false; if(!ok) continue; p[np++]=cur; break; }
		int kind=rand()%4;
		REP(i,np) p[i].id=i;
		if(kind==0) REP(i,np) p[i].col=0;
		if(kind==1) REP(i,np) p[i].col=i<4?0:rand()%2;
		if(kind==2) REP(i,np) p[i].col=i<3?0:i<4?1:rand()%2;
		if(kind==3) REP(i,np) p[i].col=i<2?0:i<4?1:rand()%2;
		bool ret=solve();
		int have=SZ(ans),want=kind==0?np-1:np-2;
		if(ret&&have==want) { printf("."); continue; }
		printf("err: %d\n",kind);
	}
}

int main() {
	run();
	//stress();
	return 0;
}