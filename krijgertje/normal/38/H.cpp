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
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

ll dp[51][51][51];

void run() {
	int n,m; scanf("%d%d",&n,&m);
	vector<vector<int> > d(n,vector<int>(n,INT_MAX));
	REP(i,n) d[i][i]=0;
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; d[a][b]=min(d[a][b],c); d[b][a]=min(d[b][a],c); }
	REP(k,n) REP(i,n) REP(j,n) if(d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX&&d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];
	int g1,g2,s1,s2; scanf("%d%d%d%d",&g1,&g2,&s1,&s2);
	
	vector<vector<int> > scores(n);
	REP(i,n) REP(j,n) if(i!=j) scores[i].PB(d[i][j]*n+i);
	REP(i,n) { sort(scores[i].begin(),scores[i].end()); scores[i].erase(unique(scores[i].begin(),scores[i].end()),scores[i].end()); }
	vector<int> best(n),worst(n); REP(i,n) best[i]=scores[i][0],worst[i]=scores[i].back();
	
	ll ret=0;
	REP(worstgold,n) REP(bestbronze,n) if(worstgold!=bestbronze) {
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;
		REP(i,n) {
			bool cangold=false,cansilver=false,canbronze=false;
			if(i==worstgold) cangold=true;
			else if(i==bestbronze) canbronze=true;
			else {
				if(best[i]<best[worstgold]) cangold=true;
				if(worst[i]>worst[bestbronze]) canbronze=true;
				REPSZ(j,scores[i]) if(best[worstgold]<scores[i][j]&&scores[i][j]<worst[bestbronze]) cansilver=true;
			}
			REPE(pg,i) REPE(ps,i-pg) if(dp[i][pg][ps]>0) {
				if(cangold) dp[i+1][pg+1][ps]+=dp[i][pg][ps];
				if(cansilver) dp[i+1][pg][ps+1]+=dp[i][pg][ps];
				if(canbronze) dp[i+1][pg][ps]+=dp[i][pg][ps];
			}
		}
		FORE(g,g1,g2) FORE(s,s1,s2) ret+=dp[n][g][s];
	}
	cout<<ret<<endl;
}

int main() {
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run(); return 0;
}