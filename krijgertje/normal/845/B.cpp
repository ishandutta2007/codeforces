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

int dp[1000][27+1];
char s[7];

void run() {
	REP(i,1000) REPE(sum,27) dp[i][sum]=INT_MAX;
	REP(i,1000) REP(j,1000) {
		int cost=0,sum=0;
		for(int ii=i,jj=j,k=0;k<3;ii/=10,jj/=10,++k) { if(ii%10!=jj%10) ++cost; sum+=jj%10; }
		dp[i][sum]=min(dp[i][sum],cost);
	}
	scanf("%s",s);
	int a=0; REP(i,3) a=10*a+s[i]-'0';
	int b=0; REP(i,3) b=10*b+s[3+i]-'0';
	int ret=INT_MAX;
	REPE(sum,27) ret=min(ret,dp[a][sum]+dp[b][sum]);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}