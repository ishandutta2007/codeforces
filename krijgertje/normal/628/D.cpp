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

const int MAXLEN=2000;
const int MAXDV=2000;
const int MOD=1000000007;

int dv,d,len;
char a[MAXLEN+1];
char b[MAXLEN+1];

int dp[MAXLEN+1][2][2][MAXDV]; // dp[i][eqa][eqb][j] = # d-magic numbers with i digits, eqa/eqb indicates if prefix is equal to a/b, and j the remainder of division by dv

void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void run() {
	scanf("%d%d",&dv,&d);
	scanf("%s%s",a,b); len=strlen(a);

	memset(dp,0,sizeof(dp));
	dp[0][1][1][0]=1;
	REPE(i,len) REP(eqa,2) REP(eqb,2) REP(j,dv) if(dp[i][eqa][eqb][j]) {
		//printf("len=%d [%d,%d] rem=%d -> %d\n",i,eqa,eqb,j,dp[i][eqa][eqb][j]);
		if(i==len) continue;
		REP(x,10) {
			if(i%2==0&&x==d||i%2==1&&x!=d) continue;
			if(eqa&&x<a[i]-'0'||eqb&&x>b[i]-'0') continue;
			inc(dp[i+1][eqa&&x==a[i]-'0'?1:0][eqb&&x==b[i]-'0'?1:0][(10*j+x)%dv],dp[i][eqa][eqb][j]);
		}
	}
	int ret=0;
	REP(eqa,2) REP(eqb,2) inc(ret,dp[len][eqa][eqb][0]);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}