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

const int MAXD=49;

ll want;

ll dp[MAXD+3][2*MAXD+1][2];

void run() {
	scanf("%lld",&want);
	ll ret=0;
	for(int da=0;;++da) {
		ll xa=(1LL<<(da+1))-2;
		if(1+xa>want) break;
		for(int db=0;;++db) {
			ll xb=(1LL<<(db+1))-2;
			if(1+xa+xb>want) break;
			ll x=want/(1+xa+xb);
			ll rem=want%(1+xa+xb);
			REPE(bits,da+db) {
				ll need=rem+bits; int d=max(da,db); if(need>((1LL<<(da+1))-2)+((1LL<<(db+1))-2)) continue;
				memset(dp,0,sizeof(dp));
				dp[0][0][0]=1;
				REPE(i,d+1) REPE(j,2*i) REP(k,2) if(dp[i][j][k]) {
					int amn=0,amx=1<=i&&i<=da?1:0,bmn=0,bmx=1<=i&&i<=db?1:0; if(i!=0&&i==da) amx=0; if(i!=0&&i==db) bmn=1;
					//printf("\t%d %d %d a=%d..%d b=%d..%d (%lld)\n",i,j,k,amn,amx,bmn,bmx,(need>>i)&1);
					FORE(aa,amn,amx) FORE(bb,bmn,bmx) { int sum=k+aa+bb; if((sum%2)!=((need>>i)&1)) continue; dp[i+1][j+aa+bb][sum/2]+=dp[i][j][k]; }
				}
				//printf("%d %d %d -> x=%lld need=%lld -> %lld\n",da,db,bits,x,need,dp[d+1][bits][0]);
				ret+=dp[d+2][bits][0];
				//if(dp[d+2][bits][0]||da==3&&db==3)  printf("!!!! %d %d %d -> x=%lld need=%lld -> %lld\n",da,db,bits,x,need,dp[d+2][bits][0]);
			}
		}
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}