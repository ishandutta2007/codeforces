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

const int MAXN=1000000;

int n,mxval;
int a[MAXN];

int val[MAXN],cnt[MAXN],nval;

int dp[MAXN+1][5][5];
void upd(int &x,int y) { x=max(x,y); }

int solve() {
	sort(a,a+n);
	nval=0; for(int l=0,r=l;l<n;l=r) { while(r<n&&a[l]==a[r]) ++r; val[nval]=a[l],cnt[nval]=r-l,++nval; }
	//printf("val:"); REP(i,nval) printf(" %d*%d",cnt[i],val[i]); puts("");

	REPE(i,nval) REP(a,5) REP(b,5) dp[i][a][b]=INT_MIN; dp[0][0][0]=0;
	REP(i,nval) REP(a,5) REP(b,5) if(dp[i][a][b]!=INT_MIN) {
		//printf("dp[%d][%d][%d]=%d\n",i,a,b,dp[i][a][b]);
		REP(c,5)  {
			if(cnt[i]<c) continue;
			int mxtrip=min(min(a,b),cnt[i]-c);
			REPE(j,mxtrip) {
				int extra=(cnt[i]-c-j)/3;
				if(i+1<nval&&val[i+1]==val[i]+1) upd(dp[i+1][b-j][c],dp[i][a][b]+j+extra);
				if(i+1<nval&&val[i+1]==val[i]+2) upd(dp[i+1][c][0],dp[i][a][b]+j+extra);
				if(i+1>=nval||val[i+1]>=val[i]+3) upd(dp[i+1][0][0],dp[i][a][b]+j+extra);
			}
		}
	}
	int ret=0; REP(a,5) REP(b,5) upd(ret,dp[nval][a][b]); return ret;
}

void run() {
	scanf("%d%d",&n,&mxval);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}