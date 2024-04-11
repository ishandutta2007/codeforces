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

const int MAXHERO=100000;

int nhero,lim,nops;
int a[MAXHERO];

ll sum[MAXHERO+1];

double solve() {
	sort(a,a+nhero); reverse(a,a+nhero);
	sum[0]=0; REP(i,nhero) sum[i+1]=sum[i]+a[i];

	double ret=0;
	FORE(nkeep,1,nhero) {
		int nrem=nhero-nkeep; if(nrem>nops) continue;
		ll ninc=min((ll)nops-nrem,(ll)nkeep*lim);
		double cur=1.0*(sum[nkeep]+ninc)/nkeep;
		ret=max(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&nhero,&lim,&nops);
	REP(i,nhero) scanf("%d",&a[i]);
	printf("%.15lf\n",solve());
}

int main() {
	run();
	return 0;
}