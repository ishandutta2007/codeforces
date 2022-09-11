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

const int MAXV=1000000;
const int MAXN=200000;
const int MOD=1000000007;

int n;
int cnt[MAXV+1];
int grpcnt[MAXV+1];
int p2[MAXN+1];

void run() {
	scanf("%d",&n);
	memset(cnt,0,sizeof(cnt));
	memset(grpcnt,0,sizeof(grpcnt));
	REP(i,n) { int x; scanf("%d",&x); ++cnt[x]; }
	p2[0]=1; REP(i,n) p2[i+1]=(ll)2*p2[i]%MOD;
	int ret=0;
	for(int i=MAXV;i>=2;--i) {
		int sum=0,grpsum=0; for(int j=i;j<=MAXV;j+=i) { sum+=cnt[j]; grpsum+=grpcnt[j]; if(grpsum>=MOD) grpsum-=MOD; }
		int here=sum==0?0:(ll)p2[sum-1]*sum%MOD;
		grpcnt[i]=(here+MOD-grpsum)%MOD;
		//if(sum>0) printf("%d: sum=%d grpsum=%d -> here=%d grpcnt=%d (%d*%d)\n",i,sum,grpsum,here,grpcnt[i],p2[sum],sum/2);
		ret=(ret+(ll)grpcnt[i]*i)%MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}