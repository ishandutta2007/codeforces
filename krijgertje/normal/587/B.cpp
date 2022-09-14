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

const int MAXN=1000000;
const int MAXNK=1000000;
const int MAXBIT=1<<20;
const int MOD=1000000007;

int n,k; ll N;
int a[MAXN];
pair<int,int> b[MAXN];

int bit[MAXBIT]; // get(j*n+idx)==cum ways to select sequence of j+1 items ending at idx
void inc(int x,int by) { ++x; while(x<MAXBIT) { if((bit[x]+=by)>=MOD) bit[x]-=MOD; x+=x&-x; } }
int get(int x) { ++x; int ret=0; while(x>0) { if((ret+=bit[x])>=MOD) ret-=MOD; x-=x&-x; } return ret; }

void run() {
	scanf("%d%I64d%d",&n,&N,&k);
	REP(i,n) scanf("%d",&a[i]);
	memset(bit,0,sizeof(bit));
	REP(i,n) b[i]=MP(a[i],i); sort(b,b+n);
	int at=0;
	while(at<n) {
		int to=at; while(to<n&&b[at].first==b[to].first) ++to;
		FOR(i,at,to) inc(b[i].second,1);
		FOR(j,1,k) {
			int cur=get(j*n-1)-get(j*n-n-1);
			if(cur<0) cur+=MOD;
			FOR(i,at,to) inc(j*n+b[i].second,cur);
		}
		at=to;
	}
	//REP(i,k*n) printf("%d,%d: %d\n",i/n+1,i%n,(get(i)-get(i-1)+MOD)%MOD);

	ll nfull=N/n; int nrem=N%n;
	int ret=0;
	REP(i,k*n) {
		int j=i/n+1,idx=i%n;
		int times=get(i)-get(i-1); if(times<0) times+=MOD;
		ll ncur=nfull+(idx<nrem?1:0)-j+1;
		//printf("%d,%d -> %I64d*%d\n",j,idx,ncur,times);
		if(ncur>=1) ret=(ret+ncur%MOD*times)%MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}