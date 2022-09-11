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

const int MAXN=3000;
const int MAXV=100000;
const int MAXGN=4*MAXN+2;
const int MAXGM=10*MAXN;

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

int n;
int a[MAXN];
int v[MAXN],nv;
int lid[MAXN],rid[MAXN],sid,ssid,tid,eqid[MAXN],modid[MAXN],nid;

int fst[MAXV+1],fstmod[7];


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	nid=0; sid=nid++,tid=nid++; REP(i,n) lid[i]=nid++,rid[i]=nid++,eqid[i]=nid++,modid[i]=nid++; 

	g.init(nid);
	REP(i,n) g.addedge(lid[i],rid[i],1,-1);
	REP(i,n) g.addedge(sid,lid[i],1,0);
	REP(i,n) g.addedge(eqid[i],lid[i],1,0);
	REP(i,n) g.addedge(modid[i],lid[i],1,0);
	REP(i,n) g.addedge(rid[i],tid,1,0);

	memset(fst,-1,sizeof(fst)); memset(fstmod,-1,sizeof(fstmod));
	for(int i=n-1;i>=0;--i) {
		int am=a[i]%7;
		if(fstmod[am]!=-1) {
			g.addedge(rid[i],modid[fstmod[am]],1,0);
			g.addedge(modid[i],modid[fstmod[am]],4,0);
		}
		if(fst[a[i]]!=-1) {
			g.addedge(eqid[i],eqid[fst[a[i]]],4,0);
		}
		for(int da=-1;da<=+1;da+=2) {
			int na=a[i]+da; if(na<1||na>MAXV||fst[na]==-1) continue;
			g.addedge(rid[i],eqid[fst[na]],1,0);
		}
		fst[a[i]]=i; fstmod[am]=i;
	}

	pair<int,ll> res=g.solve(sid,tid,4);
	printf("%lld\n",-res.second);
}

int main() {
	run();
	return 0;
}