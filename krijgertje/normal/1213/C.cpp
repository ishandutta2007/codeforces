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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

ll npages,step;

ll seen[10];
int seensum[10];

ll solve() {
	ll ntimes=npages/step;
	REP(i,10) seen[i]=-1;
	ll ret=0; int sum=0;
	ll idx=0;
	int at=step%10;
	//printf("ntimes=%lld\n",ntimes);
	while(idx<ntimes) {
		//printf("idx=%lld at=%d\n",idx,at);
		if(seen[at]==-1) {
			seen[at]=idx;
			seensum[at]=sum;
			ret+=at;
			sum+=at;
			at=(at+step)%10,++idx;
		} else {
			int period=idx-seen[at];
			ll nperiods=(ntimes-idx)/period;
			//printf("nperiods=%lld each=%d\n",nperiods,sum-seensum[at]);
			ret+=nperiods*(sum-seensum[at]);
			idx+=nperiods*period;
			while(idx<ntimes) {
				ret+=at;
				at=(at+step)%10,++idx;
			}
			break;
		}
	}
	return ret;
}

void run() {
	scanf("%lld%lld",&npages,&step);
	printf("%lld\n",solve());

}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}