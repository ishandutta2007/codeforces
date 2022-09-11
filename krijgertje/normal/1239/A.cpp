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

const int MAXH=100000;
const int MAXW=100000;
const int MAXN=100000;
const int MOD=1000000007;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int h,w;

int dp[MAXN+1];

int calc(int n) {
	REPE(i,n) dp[i]=0;
	dp[0]=2; FORE(i,1,n) { inc(dp[i],dp[i-1]); if(i-2>=0) inc(dp[i],dp[i-2]); }
	return dp[n];
}

int solve() {
	int a=calc(h);
	int b=calc(w);
	return ((ll)a+b+MOD-2)%MOD;
}

void run() {
	scanf("%d%d",&h,&w);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}