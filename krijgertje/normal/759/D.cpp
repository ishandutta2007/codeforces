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

const int MAXN=5000;
const int MOD=1000000007;

int n;
char s[MAXN+1];
int nxt[MAXN][26];

ll dp[MAXN][MAXN]; // dp[i][j]=ways to fill the first i+1 characters,the last of which comes from s[j]

//void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void run() {
	scanf("%d%s",&n,s);
	//n=MAXN; REP(i,n) s[i]=rand()%26+'a'; s[n]='\0';

	memset(dp,0,sizeof(dp));
	for(int j=n-1;j>=0;--j) REP(k,26) nxt[j][k]=s[j]=='a'+k?j:j+1>=n?n:nxt[j+1][k];
	REP(k,26) if(nxt[0][k]!=n) dp[0][nxt[0][k]]++;
	REP(i,n-1) REP(j,n) if(dp[i][j]!=0) { dp[i][j]%=MOD; REP(k,26) if(nxt[j][k]!=n) dp[i+1][nxt[j][k]]+=dp[i][j]; }
	ll ret=0; REP(j,n) ret+=dp[n-1][j]; ret%=MOD; printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}