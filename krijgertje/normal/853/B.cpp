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
const int MAXM=100000;
typedef struct F { int t,c; } F;
bool operator<(const F &a,const F &b) { return a.t<b.t; }
typedef struct E { int t,kind,a,idx; } E;
bool operator<(const E &a,const E &b) { return a.t<b.t; }

int n,m,ndays;

vector<F> fr[MAXN],to[MAXN];
E e[MAXM]; int ne;
int bestfr[MAXN],bestto[MAXN];

ll solve() {
	ne=0;
	REP(i,n) {
		sort(fr[i].begin(),fr[i].end());
		FORSZ(j,1,fr[i]) fr[i][j].c=min(fr[i][j].c,fr[i][j-1].c);
		sort(to[i].begin(),to[i].end());
		for(int j=SZ(to[i])-2;j>=0;--j) to[i][j].c=min(to[i][j].c,to[i][j+1].c);
		REPSZ(j,fr[i]) e[ne].t=fr[i][j].t+1,e[ne].kind=0,e[ne].a=i,e[ne].idx=j,++ne;
		REPSZ(j,to[i]) e[ne].t=to[i][j].t-ndays+1,e[ne].kind=1,e[ne].a=i,e[ne].idx=j,++ne;
	}
	sort(e,e+ne);
	REP(i,n) bestfr[i]=INT_MAX,bestto[i]=SZ(to[i])==0?INT_MAX:to[i][0].c;
	int ninv=0; ll bestsum=0; REP(i,n) if(bestfr[i]==INT_MAX) ++ninv; else bestsum+=bestfr[i]; REP(i,n) if(bestto[i]==INT_MAX) ++ninv; else bestsum+=bestto[i];
	ll ret=ninv>0?LLONG_MAX:bestsum;
	for(int l=0,r=l;l<ne;l=r) {
		while(r<ne&&e[l].t==e[r].t) ++r;
		FOR(i,l,r) {
			int kind=e[i].kind,a=e[i].a,idx=e[i].idx;
			if(kind==0) {
				//printf("add(%d,%d)=%d\n",a+1,fr[a][idx].t,fr[a][idx].c);
				int cur=fr[a][idx].c; if(bestfr[a]==INT_MAX) --ninv; else bestsum-=bestfr[a]; bestfr[a]=cur; bestsum+=cur;
			}
			if(kind==1) {
				//printf("rem(%d,%d)=%d\n",a+1,to[a][idx].t,to[a][idx].c);
				int cur=idx+1<SZ(to[a])?to[a][idx+1].c:INT_MAX; bestsum-=bestto[a]; bestto[a]=cur; if(cur==INT_MAX) ++ninv; else bestsum+=cur;
			}
		}
		//printf("t=%d inv=%d sum=%lld\n",e[l].t,ninv,bestsum);
		if(ninv==0) ret=min(ret,bestsum);
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&n,&m,&ndays);
	REP(i,m) { int a,b; F f; scanf("%d%d%d%d",&f.t,&a,&b,&f.c); --a,--b; if(a==-1) to[b].PB(f); if(b==-1) fr[a].PB(f); }
	ll ret=solve();
	printf("%lld\n",ret==LLONG_MAX?-1:ret);
}

int main() {
	run();
	return 0;
}