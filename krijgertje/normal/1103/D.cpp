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

const int MAXN=1000000;

int n; ll skill;
ll a[MAXN];
int cost[MAXN];

vector<ll> p;
ll b[MAXN];

ll c[MAXN]; int nc;
vector<int> copt[MAXN];

pair<int,int> ord[MAXN];
vector<int> freq;
vector<pair<int,vector<int>>> opt;

vector<vector<ll>> dp;

void addopt(vector<int> &myopt,vector<ll> &myneed,ll prod,int mask,int at) {
	if(at>=SZ(myneed)) { bool ok=true; REPSZ(i,myneed) if((mask&(1<<i))==0&&prod*myneed[i]<=skill) ok=false; if(ok&&mask!=0) myopt.PB(mask); return; }
	addopt(myopt,myneed,prod,mask,at+1);
	if(prod*myneed[at]<=skill) addopt(myopt,myneed,prod*myneed[at],mask|(1<<at),at+1);
}

ll solve() {
	ll g=0; REP(i,n) g=gcd(g,a[i]);
	//printf("g: %lld\n",g);

	{ p.clear(); ll x=g; for(int i=2;(ll)i*i<=x;++i) if(x%i==0) { p.PB(i); while(x%i==0) x/=i; } if(x!=1) p.PB(x); }
	//printf("p:"); REPSZ(i,p) printf(" %lld",p[i]); puts("");

	REP(i,n) { ll x=a[i]; REPSZ(j,p) while(x%p[j]==0) x/=p[j]; b[i]=a[i]/x; }
	//printf("b:"); REP(i,n) printf(" %lld",b[i]); puts("");

	nc=0; REP(i,n) c[nc++]=b[i]; sort(c,c+nc); nc=unique(c,c+nc)-c;
	REP(i,nc) { vector<ll> need(SZ(p)); REPSZ(j,p) { ll x=c[i]; while(x%p[j]==0) x/=p[j]; need[j]=c[i]/x; } copt[i].clear(); addopt(copt[i],need,1,0,0); }
	//REP(i,nc) { printf("%lld:",c[i]); REPSZ(j,copt[i]) printf(" %x",copt[i][j]); puts(""); }

	freq=vector<int>(1<<SZ(p),0);
	opt.clear();
	REP(i,n) ord[i]=MP(cost[i],i); sort(ord,ord+n);
	REP(i,n) {
		int at=ord[i].second;
		int idx=lower_bound(c,c+nc,b[at])-c;
		bool any=false; REPSZ(j,copt[idx]) if(freq[copt[idx][j]]<SZ(p)) any=true; if(!any) continue;
		vector<int> masks; REPSZ(j,copt[idx]) if(freq[copt[idx][j]]<SZ(p)) { masks.PB(copt[idx][j]); ++freq[copt[idx][j]]; } opt.PB(MP(cost[at],masks));
	}
	//REPSZ(i,opt) { printf("opt%d=%d:",i,opt[i].first); REPSZ(j,opt[i].second) printf(" %x",opt[i].second[j]); puts(""); }

	dp=vector<vector<ll>>(SZ(p)+1,vector<ll>(1<<SZ(p),LLONG_MAX)); dp[0][0]=0;
	REPSZ(i,opt) {
		for(int cnt=SZ(p)-1;cnt>=0;--cnt) REP(mask,1<<SZ(p)) if(dp[cnt][mask]!=LLONG_MAX) {
			REPSZ(j,opt[i].second) {
				int ncnt=cnt+1,nmask=mask|opt[i].second[j]; ll ncost=dp[cnt][mask]+opt[i].first;
				dp[ncnt][nmask]=min(dp[ncnt][nmask],ncost);
			}
		}
	}
	//REPE(cnt,SZ(p)) REP(mask,1<<SZ(p)) if(dp[cnt][mask]!=LLONG_MAX) printf("dp[%d][%x]=%lld\n",cnt,mask,dp[cnt][mask]);
	ll ret=LLONG_MAX; REPE(cnt,SZ(p)) if(dp[cnt][(1<<SZ(p))-1]!=LLONG_MAX) ret=min(ret,cnt*dp[cnt][(1<<SZ(p))-1]); return ret==LLONG_MAX?-1:ret;
}

void run() {
	scanf("%d%lld",&n,&skill);
	REP(i,n) scanf("%lld",&a[i]);
	REP(i,n) scanf("%d",&cost[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}