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

const int MAXN=50;

int n; ll k;
ll dp[MAXN+1];

int ret[MAXN];

void run() {
	cin>>n>>k; --k;

	dp[0]=dp[1]=1;
	FORE(i,2,n) dp[i]=dp[i-1]+dp[i-2];

	int at=0;
	while(at<n) {
		int left=n-at;
		//printf("%d (%d) [%lld]\n",at,left,k);
		if(k<dp[left-1]) ret[at]=at,++at;
		else k-=dp[left-1],ret[at]=at+1,ret[at+1]=at,at+=2;
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}