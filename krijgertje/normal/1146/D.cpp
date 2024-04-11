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

const int MAXA=100000;
const int MAXB=100000;
const int MAXN=MAXA+MAXB;

int lim,a,b;

int n;
int d[MAXN]; priority_queue<pair<int,int>> pq;

ll sum(ll a,ll b) { return (a+b)*(b-a+1)/2; }
ll calc(int lim) { // sum(i=0..lim,#(k*a<=lim))
	if(lim<0) return 0;
	//printf("calc(%d) %d\n",lim,a);
	ll ret=(ll)a*sum(1,(lim+1)/a)+(ll)((lim+1)%a)*(lim/a+1);
	//ll chk=0; FORE(i,0,lim) chk+=i/a+1; if(ret!=chk) printf("%lld vs %lld\n",ret,chk);
	return ret;
}

ll solve() {
	n=a+b;
	pq=priority_queue<pair<int,int>>(); REP(i,n) d[i]=INT_MAX;
	d[0]=0; pq.push(MP(-d[0],0));
	while(!pq.empty()) {
		int cost=-pq.top().first,at=pq.top().second; pq.pop();
		if(cost!=d[at]) continue;
		if(at+a<a+b) { int to=at+a,ncost=max(cost,to); if(ncost<d[to]) d[to]=ncost,pq.push(MP(-d[to],to)); }
		if(at-b>=0) { int to=at-b,ncost=max(cost,to); if(ncost<d[to]) d[to]=ncost,pq.push(MP(-d[to],to)); }
	}
	//printf("d:"); REP(i,n) printf(" %d",d[i]); puts("");
	ll ret=0;
	REP(i,n) if(d[i]<=lim) ret+=lim-d[i]+1;
	REP(i,a) if(d[i]!=INT_MAX) {
		int fst=i+(n-i+a-1)/a*a;
		//printf("%d: %d >= %d\n",i,fst,n);
		ret+=calc(lim-fst);
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&lim,&a,&b);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}