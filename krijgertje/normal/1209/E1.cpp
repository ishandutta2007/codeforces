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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXH=12;
const int MAXW=2000;

int h,w;
int a[MAXH][MAXW];

pair<int,int> o[MAXW];

int dp[1<<MAXH][MAXH+1];

void upd(int &a,int b) { a=max(a,b); }
int solve() {
	REP(y,w) { int mx=a[0][y]; FOR(x,1,h) mx=max(mx,a[x][y]); o[y]=MP(-mx,y); }
	sort(o,o+w);
	int lim=min(h,w);
	REP(mask,1<<h) REPE(at,lim) dp[mask][at]=INT_MIN;
	dp[0][0]=0;
	int allmask=(1<<h)-1;
	REP(mask,1<<h) REP(at,lim) if(dp[mask][at]!=INT_MIN) {
		int y=o[at].second;
		REP(shift,h) {
			int rem=allmask-mask;
			int sub=0;
			while(true) {
				if(sub!=0) {
					int cur=dp[mask][at]; REP(x,h) if(sub&(1<<x)) cur+=a[(x+shift)%h][y];
					upd(dp[mask|sub][at+1],cur);
				}
				if(sub==rem) break; else sub=(sub+mask+1)&rem;
			}
		}
	}
	int ret=INT_MIN; REPE(at,lim) if(dp[allmask][at]!=INT_MIN) upd(ret,dp[allmask][at]); return ret;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf("%d",&a[x][y]);
	printf("%d\n",solve());
}

void stress() {
	REP(rep,100) {
		h=MAXH,w=MAXW;
		REP(x,h) REP(y,w) a[x][y]=rand()%1000;
		solve();
		printf(".");
	}
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	//stress();
	return 0;
}