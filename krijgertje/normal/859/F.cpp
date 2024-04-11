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

const int MAXN=200000;

int n; ll nprizes;
int one[MAXN],two[MAXN-1];
ll extra[MAXN];
ll twosum[MAXN],extrasum[MAXN+1];

pair<int,ll> q[MAXN]; int qhead,qtail;

void run() {
	scanf("%d%lld",&n,&nprizes);
	REP(i,n) { scanf("%d",&one[i]); if(i!=n-1) scanf("%d",&two[i]); }
	
	REP(i,n) one[i]=min((ll)one[i],nprizes);
	REP(i,n-1) two[i]=min((ll)two[i],nprizes);
	twosum[0]=0; REP(i,n-1) twosum[i+1]=twosum[i]+two[i];
	extrasum[0]=0;

	int idx=0; ll sum=one[0]; extra[0]=extrasum[1]=0; qhead=qtail=0; q[qhead++]=MP(0,extrasum[0]-twosum[0]);
	FOR(i,1,n) {
		sum+=two[i-1]+one[i];
		while(sum>nprizes) sum-=one[idx]+two[idx],++idx;
		while(qtail<qhead&&q[qtail].first<idx) ++qtail;
		while(qtail<qhead&&extrasum[i]-twosum[i]>=q[qhead-1].second) --qhead; q[qhead++]=MP(i,extrasum[i]-twosum[i]);
		// for all j in [idx..i] we want sum(k=j..i,extra[k])>=sum(k=j..i-1,two[k]) -> extra[i]>=twosum[i]-extrasum[i]+extrasum[j]-twosum[j]
		// if(idx!=0) we want sum(k=idx-1..i,extra[k])>=sum(k=idx-1..i-1,two[k])-(sum+one[idx-1]+two[idx-1]-nprizes) -> extra[i]>=twosum[i]-extrasum[i]+extrasum[idx-1]-twosum[idx-1]-sum-one[idx-1]-two[idx-1]+nprizes
		extra[i]=0;
		if(qtail<qhead) extra[i]=max(extra[i],twosum[i]-extrasum[i]+q[qtail].second);
		if(idx-1>=0) extra[i]=max(extra[i],twosum[i]-extrasum[i]+extrasum[idx-1]-twosum[idx-1]-sum-one[idx-1]-two[idx-1]+nprizes);
		extrasum[i+1]=extrasum[i]+extra[i];
		//printf("%d: sum=%lld idx=%d extra=%lld val=%lld\n",i,sum,idx,extra[i],extrasum[i]-twosum[i]);
		//printf("q:"); FOR(j,qtail,qhead) printf(" %d=%lld",q[j].first,q[j].second); puts("");
	}

	ll ret=0;
	REP(i,n) ret+=one[i]+extra[i];
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}