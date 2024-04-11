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
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100;

int n,want;
char s[MAXN+1];

int dp[MAXN+1][MAXN+1]; // dp[i][j]=number of ways to create a subsequence of i characters, the last character of normalized subsequence being at j-1
int nxt[MAXN][26];

void inc(int &a,int b) { a=min(a+b,want); }
int solve() {
	memset(dp,0,sizeof(dp)); inc(dp[0][0],1);
	for(int i=n-1;i>=0;--i) REP(k,26) nxt[i][k]=s[i]=='a'+k?i:i+1<n?nxt[i+1][k]:-1;
	REP(i,n) REP(j,n) if(dp[i][j]!=0) {
		REP(k,26) if(nxt[j][k]!=-1) inc(dp[i+1][nxt[j][k]+1],dp[i][j]);
	}
	int ret=0,have=0;
	for(int i=n;i>=0;--i) { int sum=0; REPE(j,n) inc(sum,dp[i][j]); int cur=min(want-have,sum); ret+=cur*(n-i); have+=cur; }
	return have==want?ret:-1;
}

void run() {
	scanf("%d%d",&n,&want);
	scanf("%s",s); assert(strlen(s)==n);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}