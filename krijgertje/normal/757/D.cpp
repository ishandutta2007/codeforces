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

const int MAXN=75;
const int MAXM=19;
const int MOD=1000000007;

int n;
char s[MAXN+1];
int dp[MAXN+1][1<<MAXM];

void run() {
	scanf("%d%s",&n,s); n=strlen(s);
	//n=MAXN; REP(i,n) s[i]='0'+rand()%2;
	memset(dp,0,sizeof(dp));
	REPE(i,n) dp[i][0]=1;
	REPE(i,n) REP(j,1<<MAXM) if(dp[i][j]>0) {
		//printf("%d %x = %d\n",i,j,dp[i][j]);
		int cur=0;
		FORE(ii,i+1,n) {
			cur=2*cur+(s[ii-1]-'0'); if(cur>MAXM) break; if(cur==0) continue;
			int jj=j|(1<<(cur-1));
			if((dp[ii][jj]+=dp[i][j])>=MOD) dp[ii][jj]-=MOD;
		}
	}
	int ret=0; REPE(i,n) FORE(k,1,MAXM) { int j=(1<<k)-1; if((ret+=dp[i][j])>=MOD) ret-=MOD; } printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}