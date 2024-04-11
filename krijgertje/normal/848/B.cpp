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

const int MAXN=100000;
typedef struct P { int x,y,t,k,id; } P;
bool operator<(const P &a,const P &b) { if(a.k!=b.k) return a.k<b.k; return a.x-a.y<b.x-b.y; }

int n,w,h;
P p[MAXN];
pair<int,int> ans[MAXN];

void run() {
	scanf("%d%d%d",&n,&w,&h);
	REP(i,n) {
		int kind,coord; scanf("%d%d%d",&kind,&coord,&p[i].t);
		if(kind==1) p[i].x=coord,p[i].y=0; else p[i].x=0,p[i].y=coord;
		p[i].id=i,p[i].k=p[i].x+p[i].y-p[i].t;
	}
	sort(p,p+n);

	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&p[l].k==p[r].k) ++r;
		int nx=0,ny=0; FOR(i,l,r) if(p[i].y!=0) ++ny; else if(p[i].x!=0) ++nx;
		REP(i,ny) ans[p[l+nx+i].id]=MP(w,p[l+i].y);
		REP(i,nx) ans[p[l+i].id]=MP(p[l+ny+i].x,h);
	}
	REP(i,n) printf("%d %d\n",ans[i].first,ans[i].second);
}

int main() {
	run();
	return 0;
}