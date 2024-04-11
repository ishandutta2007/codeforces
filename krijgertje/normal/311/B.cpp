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

int nhills,ncats,nfeeders;
int d[100000];
int t[100000];
ll sum[100000];
int q[100000];
ll dp[2][100001];

ll get(ll* dp,int x,int y) {
	ll ret=dp[y]+(ll)t[x]*(x-y+1)-(sum[x+1]-sum[y]);
//	printf("\t\tget(%d,%d) = %lld\n",x,y,ret);
	return ret;
}

bool ok(ll* dp,int y1,int y2,int y3) { // y1<y2<y3
//	dp[y1]-t*y1+sum[y1];
//	dp[y2]-t*y2+sum[y2];
//	dp[y3]-t*y3+sum[y3];
//	t1=(dp[y2]-dp[y1]+sum[y2]-sum[y1])/(y2-y1)
//	t2=(dp[y3]-dp[y2]+sum[y3]-sum[y2])/(y3-y2)
//	return t1<t2;
	return (dp[y2]-dp[y1]+sum[y2]-sum[y1])*(y3-y2)<(dp[y3]-dp[y2]+sum[y3]-sum[y2])*(y2-y1);
}

void run(int casenr) {
	scanf("%d%d%d",&nhills,&ncats,&nfeeders);
	d[0]=0; FOR(i,1,nhills) { scanf("%d",&d[i]); d[i]+=d[i-1]; }
	REP(i,ncats) { int at; scanf("%d%d",&at,&t[i]); --at; t[i]-=d[at]; }
	sort(t,t+ncats);
	sum[0]=0; REP(i,ncats) sum[i+1]=sum[i]+t[i];
	
//	REP(i,ncats) printf("%d: %d %lld\n",i,t[i],sum[i+1]);
	
	// dp[i][x+1]=min(dp[i-1][y]+t[x]*(x-y+1)-(sum[x+1]-sum[y]))
	int a=0; dp[a][0]=0; REP(x,ncats) dp[a][x+1]=(ll)t[x]*(x+1)-sum[x+1];
//	REPE(x,ncats) printf("1 -> %d = %lld\n",x,dp[a][x]);
	FORE(i,2,nfeeders) {
		int head=0,tail=0; a=1-a;
		REPE(x,ncats) dp[a][x]=dp[1-a][x];
		REP(x,ncats) {
			while(head-tail>=2&&!ok(dp[1-a],q[head-2],q[head-1],x)) --head;
			q[head++]=x;
			while(head-tail>=2&&get(dp[1-a],x,q[tail+1])<=get(dp[1-a],x,q[tail])) ++tail;
//			printf("\t%d:",x); FOR(j,tail,head) printf(" %d",q[j]); puts("");
			ll cur=get(dp[1-a],x,q[tail]);
			if(cur<dp[a][x+1]) dp[a][x+1]=cur;
		}
//		REPE(x,ncats) printf("%d -> %d = %lld\n",i,x,dp[a][x]);
	}
	cout<<dp[a][ncats]<<endl;
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}