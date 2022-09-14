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
const int MAXSIGN=5;

typedef struct Road { int A,B,C,idx; } Road;
typedef struct F { ll num,den; F() { num=0,den=1; } F(ll n,ll d) { ll g=gcd(abs(n),abs(d)); if(d<0) n=-n,d=-d; num=n/g,den=d/g; } } F;
typedef struct P { F x,y; } P;
bool operator<(const F &a,const F &b) { return a.num*b.den<b.num*a.den; }
bool operator==(const F &a,const F &b) { return a.num==b.num&&a.den==b.den; }
bool operator<(const P &a,const P &b) { return a.x<b.x||a.x==b.x&&a.y<b.y; }
bool operator==(const P &a,const P &b) { return a.x==b.x&&a.y==b.y; }
bool online(const P &p,const Road &u) { ll g=gcd(p.x.den,p.y.den); /*printf("%d*%lld*%lld+%d*%lld*%lld==%d*%lld*%lld\n",u.A,p.x.num,p.y.den/g,u.B,p.y.num,p.x.den/g,u.C,p.y.den/g,p.x.den/g);*/  return u.A*p.x.num*(p.y.den/g)+u.B*p.y.num*(p.x.den/g)==u.C*p.y.den*(p.x.den/g); }
void print(const F &a) { printf("%lld",a.num); if(a.den!=1) printf("/%lld",a.den); }
void print(const P &p) { printf("("); print(p.x); printf(","); print(p.y); printf(")"); }
void print(const Road &u) { printf("[%d,%d,%d]",u.A,u.B,u.C); }

bool intersect(const Road &u,const Road &v,P &p) {
	// p.x=(v.C*u.B-v.B*u.C)/(v.A*u.B-v.B*u.A)
	// p.y=(u.C*v.A-u.A*v.C)/(v.A*u.B-v.B*u.A)
	ll numx=(ll)v.C*u.B-(ll)v.B*u.C;
	ll numy=(ll)u.C*v.A-(ll)u.A*v.C;
	ll den=(ll)v.A*u.B-(ll)v.B*u.A;
	if(den==0) {
		//print(u); printf(" parallel to "); print(v); puts("");
		return false;
	} else {
		p.x=F(numx,den); p.y=F(numy,den);
		//print(u); printf(" intersect "); print(v); printf(" -> "); print(p); puts("");
		return true;
	}
}

vector<vector<int> > ans;
bool solve(vector<Road> road,int k) {
	// if there are at least k*k+1 roads, at least one of the signs must be for at least k+1 of them
	// if there is a crossing of at least k+1 roads, we must place a sign there, since at least two of them must share a sign
	// there must be at least one sign for at least (n+k-1)/k roads

	int n=SZ(road);
	if(n<=k) { REP(i,n) ans.PB(vector<int>(1,road[i].idx)); return true; }
	if(k==0) return false;
	int ntest=n>=k*k+1?k*k+1:n;
	int nwant=n>=k*k+1?k+1:(n+k-1)/k;

	vector<P> p; p.reserve(ntest*(ntest-1)/2);
	REP(i,ntest) FOR(j,i+1,ntest) { P cur; if(!intersect(road[i],road[j],cur)) continue; p.PB(cur); }
	sort(p.begin(),p.end()); p.erase(unique(p.begin(),p.end()),p.end());

	REPSZ(i,p) {
		int cnt=0; REP(j,ntest) if(online(p[i],road[j])) ++cnt; if(cnt<nwant) continue;
		vector<Road> nroad; nroad.reserve(n);
		vector<int> onroad; onroad.reserve(n);
		REP(j,n) if(online(p[i],road[j])) onroad.PB(road[j].idx); else nroad.PB(road[j]);
		if(solve(nroad,k-1)) { ans.PB(onroad); return true; }
		if(n>=k*k+1) break;
	}
	return false;
}

int n,k;
vector<Road> road;

void run() {
	scanf("%d%d",&n,&k);
	road.resize(n);
	REP(i,n) scanf("%d%d%d",&road[i].A,&road[i].B,&road[i].C),road[i].idx=i+1;
	if(!solve(road,k)) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) if(SZ(ans[i])==1) printf("%d -1\n",ans[i][0]); else printf("%d %d\n",ans[i][0],ans[i][1]);
}


int main() {
	run();
	return 0;
}