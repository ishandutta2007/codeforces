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

const int MAXX=2000;
const int MAXSEG=2000;
const int MAXUMB=2000;

int nx,nseg,numb;
bool rains[MAXX];
int mnumb[MAXX+1];

int allumb[MAXUMB],nallumb;

int dp[MAXX+1][MAXUMB+1];

void upd(int &a,int b) { a=min(a,b); }
void run() {
	scanf("%d%d%d",&nx,&nseg,&numb); assert(nx<=MAXX&&nseg<=MAXSEG&&numb<=MAXUMB);
	REP(i,nx) rains[i]=false; REP(i,nseg) { int l,r; scanf("%d%d",&l,&r); assert(r<=nx); FOR(x,l,r) rains[x]=true; }
	REPE(i,nx) mnumb[i]=-1; REP(i,numb) { int x,val; scanf("%d%d",&x,&val); assert(x<=nx); if(mnumb[x]==-1||val<mnumb[x]) mnumb[x]=val; }

	nallumb=0; REPE(i,nx) if(mnumb[i]!=-1) allumb[nallumb++]=mnumb[i];
	sort(allumb,allumb+nallumb); nallumb=unique(allumb,allumb+nallumb)-allumb;
	REPE(i,nx) if(mnumb[i]!=-1) mnumb[i]=lower_bound(allumb,allumb+nallumb,mnumb[i])-allumb;

	REPE(i,nx) REPE(j,nallumb) dp[i][j]=INT_MAX; dp[0][nallumb]=0;
	REP(i,nx) REPE(j,nallumb) if(dp[i][j]!=INT_MAX) {
		// without
		if(!rains[i]) {
			upd(dp[i+1][nallumb],dp[i][j]);
		}
		// with
		if(j!=nallumb||mnumb[i]!=-1) {
			int nj=min(j,mnumb[i]==-1?nallumb:mnumb[i]); assert(nj<nallumb);
			upd(dp[i+1][nj],dp[i][j]+allumb[nj]);
		}
	}
	int ans=INT_MAX; REPE(j,nallumb) upd(ans,dp[nx][j]);
	printf("%d\n",ans==INT_MAX?-1:ans);
}

int main() {
	run();
	return 0;
}