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

const int MAXN=2000;
struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
ll operator*(const P &a,const P &b) { return (ll)a.x*b.x+(ll)a.y*b.y; }
P rot(const P &a) { return P(-a.y,a.x); }
struct E { P dir; int u,v; E() {} E(P dir,int u,int v):dir(dir),u(u),v(v) {} };
bool operator<(const E &a,const E &b) { ll val=(a.dir)^(b.dir); if(val!=0) return val>0; if(a.u!=b.u) return a.u<b.u; return a.v<b.v; }

int n; ll want;
P p[MAXN];

E e[MAXN*(MAXN-1)/2]; int ne;
int who[MAXN],pos[MAXN]; // who are indexes of points in with increasing inproduct with current normal, pos is the reverse mapping

bool scmp(const int &a,const int &b) { if(p[a].y!=p[b].y) return p[a].y<p[b].y; return p[a].x<p[b].x; }

int solve(P norm,ll tgt) {
	int l=-1,r=n; // [l,r) // norm*p[who[i]]<=tgt
	while(l+1<r) {
		int m=l+(r-l)/2;
		ll cur=norm*p[who[m]];
		//printf("\t\ttesting %d -> %lld\n",who[m],cur);
		if(cur<=tgt) l=m; else r=m;
	}
	int ret=l!=-1&&norm*p[who[l]]==tgt?who[l]:-1;
	//printf("\tsolving (%d,%d) tgt=%lld -> %d\n",norm.x,norm.y,tgt,ret);
	return ret;
}

int solve(P a,P b) {
	P dir=b-a; if(dir.y<0||dir.y==0&&dir.x<0) dir.x=-dir.x,dir.y=-dir.y,swap(a,b);
	P norm=rot(dir); // +-2*area=(c-a)*norm -> c*norm=a*norm+-2*area

	int opt1=solve(norm,a*norm-2*want); if(opt1!=-1) return opt1;
	int opt2=solve(norm,a*norm+2*want); if(opt2!=-1) return opt2;
	return -1;
}

int ans[3];
bool solve() {
	ne=0;
	REP(i,n) FOR(j,i+1,n) {
		P dir=p[j]-p[i]; if(dir.y<0||dir.y==0&&dir.x<0) dir.x=-dir.x,dir.y=-dir.y;
		e[ne++]=E(dir,i,j);
	}
	sort(e,e+ne);
	REP(i,ne) 

	REP(i,n) who[i]=i; sort(who,who+n,scmp); REP(i,n) pos[who[i]]=i;
	for(int l=0,r=l;l<ne;l=r) {
		while(r<ne&&(e[l].dir^e[r].dir)==0) ++r;
		//FOR(i,l,r) printf("%d-%d: (%d,%d)\n",e[i].u,e[i].v,e[i].dir.x,e[i].dir.y);
		//REP(k,n) printf(" %d=(%d,%d)->%lld",who[k],p[who[k]].x,p[who[k]].y,p[who[k]]*rot(e[l].dir)); puts("");
		FOR(i,l,r) { int cur=solve(p[e[i].u],p[e[i].v]); if(cur!=-1) { ans[0]=e[i].u,ans[1]=e[i].v,ans[2]=cur; return true; } }
		FOR(i,l,r) { int u=e[i].u,v=e[i].v; assert(abs(pos[u]-pos[v])==1); swap(pos[u],pos[v]),swap(who[pos[u]],who[pos[v]]); }
	}
	return false;
}

void run() {
	scanf("%d%lld",&n,&want);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	if(!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	REP(i,3) printf("%d %d\n",p[ans[i]].x,p[ans[i]].y);
}

int main() {
	run();
	return 0;
}