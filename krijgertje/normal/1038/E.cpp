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

const int MAXN=4;
const int MAXM=100;

int n=MAXN,m;
int e[MAXM][2],val[MAXM];

int deg[MAXN],mask[MAXN]; ll sum[MAXN];

ll solve() {
	ll ret=0;
	FOR(skip,-1,m) {
		REP(i,n) deg[i]=mask[i]=sum[i]=0;
		REP(i,m) if(i!=skip) REP(j,2) ++deg[e[i][j]],mask[e[i][j]]|=1<<e[i][1-j],sum[e[i][j]]+=val[i];
		int done=0;
		REP(i,n) if((done&(1<<i))==0) {
			ll cur=0; queue<int> q; int cntodd=0;
			q.push(i); done|=1<<i;
			while(!q.empty()) { int at=q.front(); cur+=sum[at]; cntodd+=deg[at]%2; q.pop(); REP(to,4) if((mask[at]&(1<<to))!=0&&(done&(1<<to))==0) { q.push(to); done|=1<<to; } }
			//printf("skip=%d i=%d cur=%lld cntodd=%d\n",skip,i,cur/2,cntodd);
			if(cntodd>2) continue;
			assert(cur%2==0); ret=max(ret,cur/2);
		}
	}
	return ret;
}

void run() {
	scanf("%d",&m);
	REP(i,m) scanf("%d%d%d",&e[i][0],&val[i],&e[i][1]),--e[i][0],--e[i][1];
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}