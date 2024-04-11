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
const int MOD=998244353;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n;
int par[MAXN];

vector<int> ch[MAXN];
int dproot[MAXN];
int dpvalid[MAXN];

int ways[3];
int nways[3];

int solve() {
	REP(i,n) ch[i].clear();
	REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	for(int at=n-1;at>=0;--at) {
		if(SZ(ch[at])==0) { dproot[at]=dpvalid[at]=1; continue; }
		ways[0]=1,ways[1]=ways[2]=0;
		REPSZ(i,ch[at]) {
			int to=ch[at][i];
			REP(j,3) nways[j]=0;
			REP(j,3) REP(k,2) {
				int nj=min(j+k,2);
				inc(nways[nj],(ll)ways[j]*(k==0?dpvalid[to]:dproot[to])%MOD);
			}
			REP(j,3) ways[j]=nways[j];
		}
		dproot[at]=dpvalid[at]=0; REP(j,3) { if(j!=0) inc(dproot[at],ways[j]); if(j!=1) inc(dpvalid[at],ways[j]); }
	}
	return dpvalid[0];
}

void run() {
	scanf("%d",&n);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}