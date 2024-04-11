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

const int MAXN=300000;

int n;
int op[MAXN];
int par[MAXN];

vector<int> ch[MAXN];
int dp[MAXN];

int solve() {
	REP(i,n) ch[i].clear(); REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	int nleaf=0;
	for(int i=n-1;i>=0;--i) {
		if(SZ(ch[i])==0) {
			++nleaf;
			dp[i]=1;
		} else {
			if(op[i]==0) {
				dp[i]=0; REPSZ(j,ch[i]) dp[i]+=dp[ch[i][j]];
			} else {
				dp[i]=INT_MAX; REPSZ(j,ch[i]) dp[i]=min(dp[i],dp[ch[i][j]]);
			}
		}
	}
	return nleaf-dp[0]+1;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&op[i]);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}