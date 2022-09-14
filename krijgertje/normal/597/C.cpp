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

const int MAXN=100000;
const int MAXBIT=1<<17;

int n,len;
int a[MAXN];

ll dp[MAXN];
ll bit[MAXBIT];
void bmod(int idx,ll by) { for(;idx<MAXBIT;idx+=idx&-idx) bit[idx]+=by; }
ll bget(int idx) { ll ret=0; for(;idx>0;idx-=idx&-idx) ret+=bit[idx]; return ret; }

void run() {
	scanf("%d%d",&n,&len); REP(i,n) scanf("%d",&a[i]);

	REP(j,n) dp[j]=1;
	REP(i,len) {
		memset(bit,0,sizeof(bit));
		REP(j,n) bmod(a[j],dp[j]),dp[j]=bget(a[j]-1);
		//REP(j,n) printf("%lld ",dp[j]); puts("");
	}
	ll ret=0; REP(j,n) ret+=dp[j]; printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}