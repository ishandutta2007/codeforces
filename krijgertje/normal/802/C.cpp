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

const int MAXN=80;
const int MAXCAP=80;
const int MAXGN=10*(2*MAXN+2);
const int MAXGM=10*(MAXN+MAXN+MAXN*MAXN+MAXN);

int n,cap;
int x[MAXN];
int y[MAXN];

typedef struct MCMF {
	int n,m;
	int ghead[MAXGN],gnxt[2*MAXGM],gto[2*MAXGM],gcap[2*MAXGM],gcost[2*MAXGM];
	ll d[MAXGN]; int bck[MAXGN];
	ll pot[MAXGN];

	void init(int _n) { n=_n,m=0; REP(i,n) ghead[i]=-1,pot[i]=0; }
	void addedge(int a,int b,int c,int d) { gnxt[m]=ghead[a],ghead[a]=m,gto[m]=b,gcap[m]=c,gcost[m]=d,++m; gnxt[m]=ghead[b],ghead[b]=m,gto[m]=a,gcap[m]=0,gcost[m]=-d,++m; }
	pair<int,ll> solve(int s,int t,int lim) {
		REP(i,n) d[i]=LLONG_MAX,bck[i]=-1; d[s]=0,bck[s]=-2;
		while(true) {
			bool change=false;
			REP(at,n) if(d[at]!=LLONG_MAX) for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gcap[x]>0) {
				int to=gto[x]; if(d[at]+gcost[x]>=d[to]) continue;
				d[to]=d[at]+gcost[x]; bck[to]=x^1; change=true;
			}
			if(!change) break;
		}
		assert(d[t]!=LLONG_MAX);
		REP(i,n) pot[i]=d[i];


		pair<int,ll> ret=MP(0,0);
		while(ret.first<lim) {
			REP(i,n) d[i]=LLONG_MAX,bck[i]=-1; d[s]=0,bck[s]=-2;
			priority_queue<pair<ll,int> > q; q.push(MP(-d[s],s));
			while(!q.empty()) {
				ll cost=-q.top().first; int at=q.top().second; q.pop();
				if(cost>d[at]) continue;
				for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gcap[x]>0) {
					int to=gto[x]; ll rcost=gcost[x]-pot[at]+pot[to]; if(d[at]+rcost>=d[to]) continue;
					d[to]=d[at]+rcost; bck[to]=x^1; q.push(MP(-d[to],to));
				}
			}
			if(d[t]==LLONG_MAX) break;
			//printf("%lld\n",d[t]-pot[t]);
			if(d[t]-pot[t]>0) return ret;
			++ret.first,ret.second+=d[t]-pot[t];
			REP(i,n) if(d[i]!=LLONG_MAX) pot[i]-=d[i];

			for(int at=t;at!=s;at=gto[bck[at]]) {
				//printf("%d ",at);
				++gcap[bck[at]]; --gcap[bck[at]^1];
			}
			//printf("%d ",s);
			//puts("");
		}
		return ret;
	}
} MCMF;
MCMF g;


void run() {
	scanf("%d%d",&n,&cap); REP(i,n) scanf("%d",&x[i]),--x[i]; REP(i,n) scanf("%d",&y[i]);

	int INF=1000000000;

	g.init(2*n+2); int s=2*n,t=2*n+1;
	REP(i,n) g.addedge(s,2*i+0,1,0);
	REP(i,n) g.addedge(2*i+0,2*i+1,1,-INF);
	REP(i,n) g.addedge(2*i+1,t,1,0);
	REP(i,n) FOR(j,i+1,n) g.addedge(2*i+1,2*j+0,1,x[i]==x[j]?-y[x[i]]:0);
	pair<int,ll> res=g.solve(s,t,cap);
	//printf("res.first=%d res.second=%lld\n",res.first,res.second);
	ll save=-res.second-(ll)n*INF;
	//printf("save=%lld\n",save);
	ll sum=0; REP(i,n) sum+=y[x[i]];
	ll ret=sum-save;
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}