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

const int MAXN=1000000;

int n;
int a[MAXN];
vector<int> adj[MAXN];

pair<int,int> o[MAXN];
int cur[MAXN],ncur;
bool alive[MAXN];

int ufpar[MAXN],ufsz[MAXN];
int uffind(int x) { if(ufpar[x]==x) return x; return ufpar[x]=uffind(ufpar[x]); }
bool ufunite(int x,int y) { x=uffind(x),y=uffind(y); if(x==y) return false; if(ufsz[y]>ufsz[x]) swap(x,y); ufpar[y]=x,ufsz[x]+=ufsz[y]; return true; }

ll solve() {
	REP(i,n) o[i]=MP(a[i],i); sort(o,o+n);
	REP(i,n) alive[i]=false,ufpar[i]=-1,ufsz[i]=0;
	ll ret=0;
	REP(i,n) {
		int at=o[i].second; alive[at]=true; ufpar[at]=at,ufsz[at]=1;
		ncur=0; cur[ncur++]=1;
		REPSZ(j,adj[at]) {
			int to=adj[at][j]; if(!alive[to]) continue;
			cur[ncur++]=ufsz[uffind(to)];
			ufunite(at,to);
		}
		//printf("%d (%d):",at,a[at]); REP(j,ncur) printf(" %d",cur[j]); puts("");
		int sum=0; REP(j,ncur) sum+=cur[j]; REP(j,ncur) ret+=(ll)a[at]*cur[j]*(sum-cur[j]);
	}
	return ret/2;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	ll summx=solve();
	REP(i,n) a[i]=-a[i];
	ll summn=-solve();
	printf("%lld\n",summx-summn);
	//printf("mx=%lld mn=%lld\n",summx,summn);
}

int main() {
	run();
	return 0;
}