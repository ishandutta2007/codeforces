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

const int MAXN=50;
const int MAXGN=2+2*MAXN;
const int MAXGM=MAXN+MAXN*MAXN+MAXN*MAXN;

typedef struct MCMF {
	int n,m;
	int ghead[MAXGN],gnxt[2*MAXGM],gto[2*MAXGM],gcap[2*MAXGM],gcost[2*MAXGM];
	int d[MAXGN]; int bck[MAXGN];
	int pot[MAXGN];

	void init(int _n) { n=_n,m=0; REP(i,n) ghead[i]=-1,pot[i]=0; }
	void addedge(int a,int b,int c,int d) { gnxt[m]=ghead[a],ghead[a]=m,gto[m]=b,gcap[m]=c,gcost[m]=d,++m; gnxt[m]=ghead[b],ghead[b]=m,gto[m]=a,gcap[m]=0,gcost[m]=-d,++m; }
	pair<int,int> solve(int s,int t) {
		//REP(i,n) { printf("%d:",i); for(int x=ghead[i];x!=-1;x=gnxt[x]) printf(" %d",gto[x]); puts(""); }

		REP(i,n) d[i]=INT_MAX,bck[i]=-1; d[s]=0,bck[s]=-2;
		while(true) {
			bool change=false;
			REP(at,n) if(d[at]!=INT_MAX) for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gcap[x]>0) {
				int to=gto[x]; if(d[at]+gcost[x]>=d[to]) continue;
				d[to]=d[at]+gcost[x]; bck[to]=x^1; change=true;
			}
			if(!change) break;
		}
		assert(d[t]!=INT_MAX);
		REP(i,n) pot[i]=d[i];


		pair<int,int> ret=MP(0,0);
		while(true) {
			REP(i,n) d[i]=INT_MAX,bck[i]=-1; d[s]=0,bck[s]=-2;
			priority_queue<pair<int,int> > q; q.push(MP(-d[s],s));
			while(!q.empty()) {
				int cost=-q.top().first; int at=q.top().second; q.pop();
				if(cost>d[at]) continue;
				for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gcap[x]>0) {
					int to=gto[x]; int rcost=gcost[x]-pot[at]+pot[to]; if(d[at]+rcost>=d[to]) continue;
					d[to]=d[at]+rcost; bck[to]=x^1; q.push(MP(-d[to],to));
				}
			}
			if(d[t]==INT_MAX) break;
			//printf("%d\n",d[t]-pot[t]);
			++ret.first,ret.second+=d[t]-pot[t];
			REP(i,n) if(d[i]!=INT_MAX) pot[i]-=d[i];

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

int n,nq;
int mn[MAXN],mx[MAXN];

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) mn[i]=1,mx[i]=n;
	REP(i,nq) {
		int kind,l,r,val; scanf("%d%d%d%d",&kind,&l,&r,&val); --l,--r;
		FORE(j,l,r) if(kind==1) mn[j]=max(mn[j],val); else if(kind==2) mx[j]=min(mx[j],val);
	}
	REP(i,n) if(mn[i]>mx[i]) { printf("-1\n"); return; }
	g.init(2*n+2); int s=2*n,t=2*n+1;
	REP(i,n) g.addedge(s,i,1,0);
	REP(i,n) FORE(j,mn[i],mx[i]) g.addedge(i,n+j-1,1,0);
	REP(i,n) REP(j,n) g.addedge(n+i,t,1,2*j+1);
	pair<int,int> res=g.solve(s,t);
	//printf("res=(%d,%d)\n",res.first,res.second);
	printf("%d\n",res.second);
}

int main() {
	run();
	return 0;
}