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

const int MAXFOOD=100000;
const int MAXCUST=100000;

int nfood,ncust;
int foodhave[MAXFOOD],foodcost[MAXFOOD];
int custkind[MAXCUST],custcount[MAXCUST];
ll ans[MAXCUST];

priority_queue<pair<int,int>> pq;
int foodrem[MAXFOOD];

void solve() {
	pq=priority_queue<pair<int,int>>(); REP(i,nfood) pq.push(MP(-foodcost[i],-i));
	REP(i,nfood) foodrem[i]=foodhave[i];
	REP(i,ncust) {
		ans[i]=0;
		int custrem=custcount[i];
		int cntpref=min(custrem,foodrem[custkind[i]]);
		//printf("%d: %d times preferred\n",i,cntpref);
		ans[i]+=(ll)cntpref*foodcost[custkind[i]],foodrem[custkind[i]]-=cntpref,custrem-=cntpref;
		while(custrem>0) {
			if(pq.empty()) { ans[i]=0; break; }
			int at=-pq.top().second; if(foodrem[at]==0) { pq.pop(); continue; }
			int curcnt=min(custrem,foodrem[at]);
			//printf("%d: %d times %d\n",i,curcnt,at);
			ans[i]+=(ll)curcnt*foodcost[at],foodrem[at]-=curcnt,custrem-=curcnt;
		}
	}
}

void run() {
	scanf("%d%d",&nfood,&ncust);
	REP(i,nfood) scanf("%d",&foodhave[i]);
	REP(i,nfood) scanf("%d",&foodcost[i]);
	REP(i,ncust) scanf("%d%d",&custkind[i],&custcount[i]),--custkind[i];
	solve();
	REP(i,ncust) printf("%lld\n",ans[i]);
}

int main() {
	run();
	return 0;
}