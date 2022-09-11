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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MOD=1000000007;

int n,k;
vector<int> red[MAXN];
vector<int> black[MAXN];

bool done[MAXN];
int q[MAXN],qhead,qtail;

int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int solve() {
	REP(i,n) done[i]=false;
	int ret=pw(n,k);
	REP(i,n) if(!done[i]) {
		qhead=qtail=0; q[qhead++]=i,done[i]=true; int cnt=0;
		while(qtail<qhead) { int at=q[qtail++]; ++cnt; REPSZ(j,red[at]) { int to=red[at][j]; if(!done[to]) done[to]=true,q[qhead++]=to; } }
		int cur=pw(cnt,k);
		ret=(ret+MOD-cur)%MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&k);
	REP(i,n-1) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; if(c==0) red[a].PB(b),red[b].PB(a); if(c==1) black[a].PB(b),black[b].PB(a); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}