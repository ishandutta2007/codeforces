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

const int MAXN=200000;

int n;
int a[MAXN][2];
int ans[MAXN];

bool have[MAXN];
int cur[MAXN];

bool solve() {
	REP(x,2) {
		cur[0]=0,cur[1]=a[0][x]; bool ok=true; REP(i,n) have[i]=false; have[cur[0]]=have[cur[1]]=true;
		REP(i,n) {
			int nxt=a[cur[i]][0]+a[cur[i]][1]-cur[(i+1)%n];
			if(i+2<n) { if(nxt<0||nxt>=n||have[nxt]) { ok=false; break; } cur[i+2]=nxt; have[nxt]=true; } else if(cur[i+2-n]!=nxt) ok=false;
		}
		//printf("cur:"); REP(i,n) printf(" %d",cur[i]+1); puts("");
		if(!ok) continue;
		REP(i,n) ans[i]=cur[i];
		return true;
	}
	return false;
}

void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,2) scanf("%d",&a[i][j]),--a[i][j];
	assert(solve());
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}