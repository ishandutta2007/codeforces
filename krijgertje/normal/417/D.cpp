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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

typedef struct X { int cost,need,can; } X;
bool operator<(const X &a,const X &b) { return a.need<b.need; }

int nfriend,nprob,moncost;
X x[100];

ll dp[1<<20];

void run() {
	scanf("%d%d%d",&nfriend,&nprob,&moncost);
	REP(i,nfriend) { int cnt; scanf("%d%d%d",&x[i].cost,&x[i].need,&cnt); x[i].can=0; REP(j,cnt) { int id; scanf("%d",&id); --id; x[i].can|=1<<id; } }
	sort(x,x+nfriend);

	ll ret=LLONG_MAX;
	dp[0]=0;
	FOR(j,1,1<<nprob) dp[j]=LLONG_MAX;
	REP(i,nfriend) {
		//printf("%d: %d %d %x\n",i,x[i].cost,x[i].need,x[i].can);
		REP(j,1<<nprob) if(dp[j]!=LLONG_MAX&&(j&x[i].can)!=x[i].can) {
			int nj=j|x[i].can; ll nc=dp[j]+x[i].cost;
			if(nc<dp[nj]) dp[nj]=nc;
		}
		//REP(j,1<<nprob) printf("%lld ",dp[j]); puts("");
		if(dp[(1<<nprob)-1]!=LLONG_MAX) {
			ll cur=dp[(1<<nprob)-1]+(ll)x[i].need*moncost;
			//printf("->%lld\n",cur);
			if(cur<ret) ret=cur;
		}
	}
	cout<<(ret==LLONG_MAX?-1:ret)<<endl;
}

int main() {
	run();
	return 0;
}