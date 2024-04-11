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

const int MAXH=200000;
const int MAXW=200000;
const int MAXSAFE=MAXW;

int h,w,ntreasure,nsafe;
vector<int> rowtreasures[MAXH];
int safecols[MAXSAFE];

ll dp[MAXH][2];

ll solve() {
	rowtreasures[0].PB(0);
	REP(x,h) if(SZ(rowtreasures[x])>=2) { int mn=INT_MAX,mx=INT_MIN; REPSZ(i,rowtreasures[x]) { int y=rowtreasures[x][i]; mn=min(mn,y); mx=max(mx,y); } rowtreasures[x].clear(); rowtreasures[x].PB(mn); if(mx>mn) rowtreasures[x].PB(mx); }
	sort(safecols,safecols+nsafe);

	REP(x,h) REP(i,2) dp[x][i]=LLONG_MAX;
	REPSZ(i,rowtreasures[0]) dp[0][i]=abs(rowtreasures[0][SZ(rowtreasures[0])-i-1]-0)+abs(rowtreasures[0][i]-rowtreasures[0][SZ(rowtreasures[0])-i-1]);
	for(int px=0,nx=px;true;px=nx) {
		while(nx<h&&(nx==px||SZ(rowtreasures[nx])==0)) ++nx;
		//printf("px=%d nx=%d\n",px,nx);
		if(nx>=h) { ll ret=LLONG_MAX; REPSZ(i,rowtreasures[px]) ret=min(ret,dp[px][i]); return ret; }
		REPSZ(i,rowtreasures[px]) REPSZ(j,rowtreasures[nx]) {
			int sy=rowtreasures[px][i],my=rowtreasures[nx][SZ(rowtreasures[nx])-j-1],ty=rowtreasures[nx][j];
			assert(dp[px][i]!=LLONG_MAX);
			int ly=min(sy,my),hy=max(sy,my); int idx=lower_bound(safecols,safecols+nsafe,ly)-safecols;
			ll delta=LLONG_MAX; FORE(k,idx-1,idx) if(k>=0&&k<nsafe) delta=min(delta,(ll)abs(ly-safecols[k])+abs(hy-safecols[k]));
			ll cur=dp[px][i]+delta+abs(my-ty)+abs(nx-px);
			//printf("(%d,%d)->(%d,%d) = %lld -> %lld\n",px,sy,nx,ty,dp[px][i],cur);
			dp[nx][j]=min(dp[nx][j],cur);
		}
	}
	return -1;
}

void run() {
	scanf("%d%d%d%d",&h,&w,&ntreasure,&nsafe);
	REP(i,ntreasure) { int x,y; scanf("%d%d",&x,&y); --x,--y; rowtreasures[x].PB(y); }
	REP(i,nsafe) scanf("%d",&safecols[i]),--safecols[i];
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}