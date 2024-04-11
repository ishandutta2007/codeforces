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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=1000000;
const int MAXBIT=61;

int n; ll want;
int par[MAXN]; ll parw[MAXN];

ll val[MAXN];

pair<pair<int,int>,pair<int,int>> cur[MAXN]; int ncur;

pair<pair<int,int>,pair<int,int>> a[MAXN]; int na;
pair<pair<int,int>,pair<int,int>> b[MAXN]; int nb;


ll solve() {
	val[0]=0; FOR(i,1,n) val[i]=val[par[i]]^parw[i];
	sort(val,val+n);
	//printf("val:"); REP(i,n) printf(" %llx",val[i]); puts("");

	ncur=0; cur[ncur++]=MP(MP(0,n),MP(0,n)); ll rem=want,ret=0;
	for(int bit=MAXBIT;bit>=0;--bit) {
		na=nb=0;ll asum=0,bsum=0;
		REP(i,ncur) {
			int l1=cur[i].first.first,r1=cur[i].first.second,l2=cur[i].second.first,r2=cur[i].second.second;
			int m1=l1; while(m1<r1&&(val[m1]&(1LL<<bit))==0) ++m1;
			int m2=l2; while(m2<r2&&(val[m2]&(1LL<<bit))==0) ++m2;
			if(l1<m1&&l2<m2) a[na++]=MP(MP(l1,m1),MP(l2,m2)),asum+=(ll)(m1-l1)*(m2-l2);
			if(m1<r1&&m2<r2) a[na++]=MP(MP(m1,r1),MP(m2,r2)),asum+=(ll)(r1-m1)*(r2-m2);
			if(l1<m1&&m2<r2) b[nb++]=MP(MP(l1,m1),MP(m2,r2)),bsum+=(ll)(m1-l1)*(r2-m2);
			if(m1<r1&&l2<m2) b[nb++]=MP(MP(m1,r1),MP(l2,m2)),bsum+=(ll)(r1-m1)*(m2-l2);
		}
		//printf("%d: asum=%lld bsum=%lld\n",bit,asum,bsum);
		if(rem<asum) {
			ncur=na; REP(i,na) cur[i]=a[i];
		} else {
			rem-=asum,ret|=1LL<<bit;
			ncur=nb; REP(i,nb) cur[i]=b[i];
		}
	}

	return ret;
}

void run() {
	scanf("%d%lld",&n,&want),--want;
	par[0]=-1,parw[0]=0; FOR(i,1,n) scanf("%d%lld",&par[i],&parw[i]),--par[i];
	printf("%lld\n",solve());
}

void stress() {
	n=MAXN; want=((ll)rand()%1000*1000000000000000+(ll)rand()%1000*1000000000000+(ll)rand()%1000*1000000000+(ll)rand()%1000*1000000+(ll)rand()%1000*1000+(ll)rand()%1000)%((ll)n*n);
	par[0]=-1,parw[0]=0; FOR(i,1,n) { par[i]=i-1; parw[i]=0; REPE(j,MAXBIT) parw[i]|=(ll)(rand()%2)<<j; }
	solve();
	printf("done\n");
}

int main() {
	run();
	//stress();
	return 0;
}