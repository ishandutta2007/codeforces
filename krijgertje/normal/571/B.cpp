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
const int MAXSTEP=5000;

int n,step;
int a[MAXN];

int dp[2][MAXSTEP];


void run() {
	scanf("%d%d",&n,&step);
	REP(i,n) scanf("%d",&a[i]);
	sort(a,a+n);
	int base=n/step,want=n%step;

	int at=0; REPE(j,want) dp[at][j]=INT_MAX; dp[at][0]=0;
	REP(i,step) {
		REPE(j,want) dp[1-at][j]=INT_MAX;
		REPE(j,want) if(dp[at][j]!=INT_MAX) REP(k,2) if(j+k<=want) {
			int nval=dp[at][j]+(a[(i+1)*base-1+j+k]-a[i*base+j]);
			if(nval<dp[1-at][j+k]) dp[1-at][j+k]=nval;
		}
		//printf("%d:",i); REPE(j,want) printf(" %d",dp[1-at][j]); puts("");
		at=1-at;
	}

	printf("%d\n",dp[at][want]);
}

int main() {
	run();
	return 0;
}