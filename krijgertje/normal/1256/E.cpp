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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXN=200000;

int n;
int a[MAXN];
int nteam;
int ans[MAXN];

pair<int,int> o[MAXN];

int dp[MAXN+1];
int act[MAXN+1];

int solve() {
	REP(i,n) o[i]=MP(a[i],i);
	sort(o,o+n);
	
	REPE(i,n) dp[i]=INT_MAX,act[i]=-2; dp[0]=0,act[0]=-1;
	int opt=INT_MAX,optidx=-2;
	FORE(i,1,n) {
		if(i-3>=0&&dp[i-3]!=INT_MAX) {
			int cur=dp[i-3]-o[i-3].first;
			if(cur<opt) opt=cur,optidx=i-3;
		}
		dp[i]=opt+o[i-1].first,act[i]=optidx;
	}
	{
		REP(i,n) ans[i]=-1;
		int at=n;
		nteam=0;
		while(at!=0) {
			int to=act[at];
			FOR(i,to,at) ans[o[i].second]=nteam;
			++nteam;
			at=to;
		}
	}
	return dp[n];
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	int sum=solve();
	printf("%d %d\n",sum,nteam);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}