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

const int MAXISLAND=200000;
const int MAXBRIDGE=200000;
const int MAXGAP=MAXISLAND-1;
typedef struct Gap { int idx; ll l,r; } Gap;
bool operator<(const Gap &a,const Gap &b) { return a.l<b.l; }
typedef struct Bridge { int idx; ll val; } Bridge;
bool operator<(const Bridge &a,const Bridge &b) { return a.val<b.val; }

int nisland,nbridge;
ll x[MAXISLAND],y[MAXISLAND];
Gap g[MAXGAP]; int ngap;
Bridge b[MAXBRIDGE];

int ret[MAXGAP];

void run() {
	scanf("%d%d",&nisland,&nbridge);
	REP(i,nisland) cin>>x[i]>>y[i];
	REP(i,nbridge) b[i].idx=i,cin>>b[i].val;

	ngap=nisland-1; REP(i,ngap) g[i].idx=i,g[i].l=x[i+1]-y[i],g[i].r=y[i+1]-x[i];
	sort(g,g+ngap);
	sort(b,b+nbridge);
	//REP(i,nbridge) printf("%lld ",b[i].val); puts("");
	//REP(i,ngap) printf("(%lld..%lld)",g[i].l,g[i].r); puts("");

	priority_queue<pair<ll,int> > q;
	int atgap=0;
	REP(i,nbridge) {
		while(atgap<ngap&&b[i].val>=g[atgap].l) { q.push(MP(-g[atgap].r,g[atgap].idx)); ++atgap; }
		if(SZ(q)>0) {
			ll bound=-q.top().first; int idx=q.top().second; q.pop();
			if(b[i].val>bound) { printf("No\n"); return; }
			//printf("%lld (%d) -> ?..%lld (%d)\n",b[i].val,b[i].idx,bound,idx);
			ret[idx]=b[i].idx;
		}
	}
	if(atgap<ngap||SZ(q)>0) { printf("No\n"); return; }
	printf("Yes\n");
	REP(i,ngap) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}