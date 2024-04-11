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

const int MAXN=100;
const int MAXM=100;
const int GMAXN=MAXN+2;
const int GMAXM=1+MAXN+3*MAXM;

typedef struct G {
	int n,m;
	int nhead[GMAXN],enxt[2*GMAXM],eto[2*GMAXM],ecap[2*GMAXM],ecst[2*GMAXM];
	int bst[GMAXN],cur[GMAXN],back[GMAXN];

	void init(int _n) { n=_n,m=0; }
	void addedge(int a,int b,int c,int d) {
		enxt[m]=nhead[a],nhead[a]=m,eto[m]=b,ecap[m]=c,ecst[m]=d,++m;
		enxt[m]=nhead[b],nhead[b]=m,eto[m]=a,ecap[m]=0,ecst[m]=-d,++m;
	}
	ll mincost(int s,int t) {
		ll ret=0;
		while(true) {
			REP(i,n) bst[i]=INT_MAX,cur[i],back[i]=-1; bst[s]=0,cur[s]=INT_MAX;
			while(true) {
				bool change=false;
				REP(x,m) if(ecap[x]>0) {
					int a=eto[x^1],b=eto[x];
					if(bst[a]==INT_MAX||bst[a]+ecst[x]>=bst[b]) continue;
					bst[b]=bst[a]+ecst[x]; cur[b]=min(cur[a],ecap[x]); back[b]=x^1; change=true;
				}
				if(!change) break;
			}
			if(back[t]==-1) return ret;
			ret+=(ll)cur[t]*bst[t];
			for(int i=t;i!=s;i=eto[back[i]]) {
				ecap[back[i]]+=cur[t];
				ecap[back[i]^1]-=cur[t];
			}
		}
	}
} G;


int n,m;
int u[MAXM],v[MAXM],c[MAXM],f[MAXM];
int sum[MAXN];
G g;

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) scanf("%d%d%d%d",&u[i],&v[i],&c[i],&f[i]),--u[i],--v[i];
	REP(i,n) sum[i]=0; REP(i,m) { int mn=min(c[i],f[i]); sum[u[i]]-=mn; sum[v[i]]+=mn; }

	int ss=n,tt=n+1; ll ret=0;
	g.init(n+2);
	g.addedge(n-1,0,INT_MAX,0);
	REP(i,n) if(sum[i]>0) g.addedge(ss,i,sum[i],0); else if(sum[i]<0) g.addedge(i,tt,-sum[i],0);
	REP(i,m) {
		int mn=min(c[i],f[i]),mx=max(c[i],f[i]); ret+=f[i]-mn;
		g.addedge(v[i],u[i],mn,1);
		if(mx!=mn) g.addedge(u[i],v[i],mx-mn,f[i]<c[i]?1:0);
		g.addedge(u[i],v[i],INT_MAX,2);
	}
	ret+=g.mincost(ss,tt);
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}