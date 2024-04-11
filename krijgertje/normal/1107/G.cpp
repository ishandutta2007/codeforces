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

const int MAXN=300000;

int n,probgain;
int diff[MAXN],cost[MAXN];

ll sumcost[MAXN+1];
int fst[MAXN],lst[MAXN];
ll lbest[MAXN],rbest[MAXN];
pair<int,int> o[MAXN-1]; int no;

ll solve() {
	sumcost[0]=0; REP(i,n) sumcost[i+1]=sumcost[i]+cost[i];
	REP(i,n) fst[i]=lst[i]=i,lbest[i]=sumcost[i]-(ll)i*probgain,rbest[i]=(ll)(i+1)*probgain-sumcost[i+1];
	no=0; REP(i,n-1) o[no++]=MP(diff[i+1]-diff[i],i); sort(o,o+no);
	//REP(i,n) printf("%d: %lld %lld\n",i,lbest[i],rbest[i]);

	ll ret=0;
	REP(i,n) ret=max(ret,lbest[i]+rbest[i]);
	REP(i,no) {
		int idx=o[i].second,dst=o[i].first;
		assert(lst[idx]==idx&&idx+1<n&&fst[idx+1]==idx+1);
		ret=max(ret,lbest[fst[idx]]+rbest[idx+1]-(ll)dst*dst);
		lbest[fst[idx]]=max(lbest[fst[idx]],lbest[idx+1]);
		rbest[fst[idx]]=max(rbest[fst[idx]],rbest[idx+1]);
		fst[lst[idx+1]]=fst[idx];
		lst[fst[idx]]=lst[idx+1];
	}

	return ret;
}

void run() {
	scanf("%d%d",&n,&probgain);
	REP(i,n) scanf("%d%d",&diff[i],&cost[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}