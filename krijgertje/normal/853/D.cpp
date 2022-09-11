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

const int MAXN=300000;

int n;
int a[MAXN];
int dp[MAXN+1][31];

void upd(int &a,int b) { if(a==-1||b>a) a=b; }
void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	int sum=0; REP(i,n) sum+=a[i];
	memset(dp,-1,sizeof(dp)); dp[0][0]=0;
	REP(i,n) REPE(j,30) if(dp[i][j]!=-1) {
		int x=a[i]/1000;
		if(j+x<=30) upd(dp[i+1][j+x],dp[i][j]);
		int d=min(10*x,j);
		upd(dp[i+1][j-d],dp[i][j]+d);
	}
	int mx=-1; REPE(j,30) upd(mx,dp[n][j]);
	int ret=sum-100*mx;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}