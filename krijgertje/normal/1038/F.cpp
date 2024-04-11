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

const int MAXN=40;

int n;
char s[MAXN+1]; int slen;

ll dp[MAXN][MAXN][MAXN+1]; // dp[fst][lst][i] = #ways to put s in i places, the first one being fst and the last one being lst
ll sum[MAXN+1]; // sum[i] = #ways to put s in i places

bool can[MAXN][MAXN];

ll solve() {
	REP(i,n) can[i][i]=true; REP(i,n) FOR(j,i+1,n) { can[i][j]=true; REP(k,slen) if(i+k>=j&&s[k]!=s[i+k-j]||j+k>=i+n&&s[k]!=s[j+k-i-n]) can[i][j]=false; can[j][i]=can[i][j]; }
	//REP(i,n) { REP(j,n) printf("%c",can[i][j]?'V':'.'); puts(""); }

	memset(dp,0,sizeof(dp));
	REP(i,n) dp[i][i][1]=1;
	REP(fst,n) FOR(lst,fst,n) FORE(i,1,lst-fst+1) if(dp[fst][lst][i]!=0) {
		//printf("dp[%d][%d][%d]=%lld\n",fst,lst,i,dp[fst][lst][i]);
		FOR(nxt,lst+1,n) if(can[fst][nxt]&&can[lst][nxt]) {
			int nfree=max(0,nxt-lst-slen);
			dp[fst][nxt][i+1]+=dp[fst][lst][i]<<nfree;
		}
	}
	memset(sum,0,sizeof(sum));
	REP(fst,n) FOR(lst,fst,n) FORE(i,1,lst-fst+1) if(dp[fst][lst][i]!=0) {
		int nfree=max(0,fst+n-lst-slen);
		sum[i]+=dp[fst][lst][i]<<nfree;
	}
	sum[0]=1LL<<n;
	//REPE(i,n) printf("%d: %lld\n",i,sum[i]);
	ll none=0;
	REPE(i,n) { ll cur=sum[i]; if(i%2==0) none+=cur; else none-=cur; }
	return (1LL<<n)-none;
}

void run() {
	scanf("%d",&n); scanf("%s",s); slen=strlen(s);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}