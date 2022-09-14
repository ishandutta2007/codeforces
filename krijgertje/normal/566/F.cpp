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

const int MAXN=1000000;
const int MAXVAL=1000000;

int n;
int a[MAXN];
int cnt[MAXVAL+1];
int dp[MAXVAL+1];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	memset(cnt,0,sizeof(cnt));
	REP(i,n) ++cnt[a[i]];
	memset(dp,0,sizeof(dp));
	FORE(i,1,MAXVAL) {
		dp[i]+=cnt[i];
		for(int j=i+i;j<=MAXVAL;j+=i) if(dp[i]>dp[j]) dp[j]=dp[i];
	}
	int ret=0; FORE(i,1,MAXVAL) if(dp[i]>ret) ret=dp[i]; printf("%d\n",ret);

}

int main() {
	run();
	return 0;
}