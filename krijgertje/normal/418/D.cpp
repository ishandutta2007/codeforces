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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }


int n,m;
int fst[100000];	// node->edge
int nxt[200000];	// edge->edge
int to[200000];		// edge->node

int qh,qt;
int q[100000];

int par[100000];
int d[100000];
int md[100000][3];
int mdi[100000][3];

int up[100000][20];
int msum[100000][20];
int mdff[100000][20];

int lca(int x,int y) {
	if(d[x]>d[y]) swap(x,y);
	for(int i=19;i>=0;--i) if(d[y]-(1<<i)>=d[x]) y=up[y][i];
	if(x==y) return x;
	for(int i=19;i>=0;--i) if(up[x][i]!=up[y][i]) x=up[x][i],y=up[y][i];
	return par[x];
}

int calcup(int x,int d) {
	if(d<=0) return x;
	for(int i=19;i>=0;--i) if(d&(1<<i)) x=up[x][i]; return x;
}

int calcdff(int x,int d,int offset) {
	if(d<=0) return 0;
	int ret=0;
	for(int i=19;i>=0;--i) if(d&(1<<i)) { ret=max(ret,offset+mdff[x][i]); x=up[x][i]; }
	return ret;
}

int calcsum(int x,int d,int offset) {
	if(d<=0) return 0;
	int ret=0;
	for(int i=19;i>=0;--i) if(d&(1<<i)) { ret=max(ret,offset+msum[x][i]); x=up[x][i]; }
	return ret;
}

void run() {
	scanf("%d",&n); m=0;
	memset(fst,-1,sizeof(fst));
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		to[m]=b; nxt[m]=fst[a]; fst[a]=m; ++m;
		to[m]=a; nxt[m]=fst[b]; fst[b]=m; ++m;
	}
	qh=qt=0; q[qh++]=0; memset(d,-1,sizeof(d)); par[0]=-1; d[0]=0;
	while(qt<qh) {
		int at=q[qt++];
		for(int x=fst[at];x!=-1;x=nxt[x]) if(d[to[x]]==-1) { d[to[x]]=d[at]+1; par[to[x]]=at; q[qh++]=to[x]; }
	}
	memset(md,0,sizeof(md)); memset(mdi,-1,sizeof(mdi));
	for(int i=n-1;i>=0;--i) {
		int at=q[i];
		for(int x=fst[at];x!=-1;x=nxt[x]) if(to[x]!=par[at]) {
			int cd=md[to[x]][0]+1,cdi=to[x];
			if(cd>md[at][0]) { md[at][2]=md[at][1]; md[at][1]=md[at][0]; md[at][0]=cd; mdi[at][2]=mdi[at][1]; mdi[at][1]=mdi[at][0]; mdi[at][0]=cdi; }
			else if(cd>md[at][1]) { md[at][2]=md[at][1]; md[at][1]=cd; mdi[at][2]=mdi[at][1]; mdi[at][1]=cdi; }
			else if(cd>md[at][2]) { md[at][2]=cd; mdi[at][2]=cdi; }
		}
	}
	up[0][0]=0; msum[0][0]=INT_MIN; mdff[0][0]=INT_MIN;
	FOR(i,1,n) {
		up[i][0]=par[i];
		int mpd=i!=mdi[par[i]][0]?md[par[i]][0]:md[par[i]][1];
		msum[i][0]=mpd+d[par[i]];
		mdff[i][0]=mpd-d[par[i]];
	}
	FOR(j,1,20) REP(i,n) {
		up[i][j]=up[up[i][j-1]][j-1];
		msum[i][j]=max(msum[i][j-1],msum[up[i][j-1]][j-1]);
		mdff[i][j]=max(mdff[i][j-1],mdff[up[i][j-1]][j-1]);
	}
	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int x,y; scanf("%d%d",&x,&y); --x,--y;
		if(d[x]>d[y]) swap(x,y);
		int z=lca(x,y);
		int len=d[x]+d[y]-2*d[z];
		int w=calcup(y,(len-1)/2);
		int xx=calcup(x,d[x]-d[z]-1);
		int ww=calcup(w,d[w]-d[z]-1);

		int v1=md[y][0];
		int v2=x!=z?md[x][0]:0;
		int v3=calcdff(y,(len-1)/2,d[y]);
		int v4=calcdff(x,d[x]-d[z]-1,d[x]);
		int v5=calcsum(w,d[w]-d[z]-1,-d[z]+d[x]-d[z]);
		int v6=calcdff(z,d[z],d[x]);
		int v7=xx!=mdi[z][0]&&ww!=mdi[z][0]?md[z][0]+d[x]-d[z]:0;
		int v8=xx!=mdi[z][1]&&ww!=mdi[z][1]?md[z][1]+d[x]-d[z]:0;
		int v9=xx!=mdi[z][2]&&ww!=mdi[z][2]?md[z][2]+d[x]-d[z]:0;
		int v=max(max(max(max(max(max(max(max(v1,v2),v3),v4),v5),v6),v7),v8),v9);
		//printf("\t%d %d %d %d %d %d %d %d %d [x=%d,y=%d,z=%d,w=%d,xx=%d,ww=%d]\n",v1,v2,v3,v4,v5,v6,v7,v8,v9,x,y,z,w,xx,ww);
		printf("%d\n",v);
	}


}

int main() {
	run();
	return 0;
}