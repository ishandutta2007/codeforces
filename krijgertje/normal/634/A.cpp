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

const int MAXN=200000;
const int MAXM=MAXN-1;
typedef struct E { int u,v; } E;
bool operator<(const E &a,const E &b) { if(a.u!=b.u) return a.u<b.u; return a.v<b.v; }

int n;
int oa[MAXN],ob[MAXN];
int a[MAXN],ra[MAXN];
int b[MAXN],rb[MAXN];
bool been[MAXN];
bool d[MAXN];
E e[MAXM];
int adj[MAXN][2],nadj[MAXN];
int p[2][MAXN],np[2],nnp; bool onp[MAXN];
int c[MAXN],rc[MAXN],nc;
int head[MAXN],nxt[2*MAXM],to[2*MAXM];
int t[MAXN];

bool exists(int u,int v) {
	if(u>v) swap(u,v);
	int l=0,h=n-1;
	while(l<=h) {
		int m=l+(h-l)/2;
		if(e[m].u==u&&e[m].v==v) return true;
		if(e[m].u<u||e[m].u==u&&e[m].v<v) l=m+1; else h=m-1;
	}
	return false;
}
int dfs(int at,int par) {
	if(been[at]) return 0;
	int ret=INT_MAX;
	for(int x=head[at];x!=-1;x=nxt[x]) {
		if(onp[to[x]]||to[x]==par) continue;
		int cur=dfs(to[x],at);
		if(cur==INT_MAX) continue;
		if(cur+1<ret) ret=cur+1;
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]); REP(i,n) ra[a[i]]=i;
	REP(i,n) scanf("%d",&b[i]); REP(i,n) rb[b[i]]=i;
	REP(i,n-1) e[i].u=i,e[i].v=i+1;
	REP(i,n) been[i]=false,head[i]=-1,oa[i]=a[i],ob[i]=b[i];
	REP(i,n-1) {
		int u=e[i].u,v=e[i].v;
		nxt[2*i+0]=head[u]; head[u]=2*i+0; to[2*i+0]=v;
		nxt[2*i+1]=head[v]; head[v]=2*i+1; to[2*i+1]=u;
	}
	
	int ret=0;
	while(true) {
		int u=ra[0],v=ra[b[u]]; been[u]=true;
		if(!exists(u,v)) break;
		swap(a[u],a[v]); swap(ra[a[u]],ra[a[v]]); ++ret;
	}
	//printf("=%d\n",ret);
	while(true) {
		int u=rb[0],v=rb[a[u]];
		if(!exists(u,v)) break;
		swap(b[u],b[v]); swap(rb[b[u]],rb[b[v]]); ++ret;
	}
	//printf("=%d\n",ret);
	//REP(i,n) printf("%2d ",i+1); puts("");
	//REP(i,n) printf("%2d ",a[i]); puts("");
	//REP(i,n) printf("%2d ",b[i]); puts("");
	REP(i,n) d[i]=a[i]!=b[i],nadj[i]=0,onp[i]=false; nnp=0;
	REP(i,n-1) if(d[e[i].u]&&d[e[i].v]) {
		int u=e[i].u,v=e[i].v;
		if(nadj[u]==2) { printf("NO\n"); return; } else adj[u][nadj[u]++]=v;
		if(nadj[v]==2) { printf("NO\n"); return; } else adj[v][nadj[v]++]=u;
	}
	REP(i,n) if(d[i]&&nadj[i]<=1&&!onp[i]) {
		if(nnp==2) { printf("NO\n"); return; } else np[nnp]=0;
		for(int at=i,to=-1;at!=-1;at=to,to=-1) {
			p[nnp][np[nnp]++]=at; onp[at]=true;
			REP(j,nadj[at]) if(!onp[adj[at][j]]) to=adj[at][j];
		}
		++nnp;
	}
	if(nnp==0) { printf("YES\n",ret); return; }
	if(nnp==2) REP(i,n) if(!onp[i]&&(exists(i,p[0][0])||exists(i,p[0][np[0]-1]))&&(exists(i,p[1][0])||exists(i,p[1][np[1]-1]))) {
		if(!exists(i,p[0][np[0]-1])) reverse(p[0],p[0]+np[0]); if(!exists(i,p[1][0])) reverse(p[1],p[1]+np[1]);
		p[0][np[0]++]=i; onp[i]=true; REP(j,np[1]) p[0][np[0]++]=p[1][j]; nnp=1; break;
	}
	if(nnp==2) {
		if(np[0]==1&&np[1]==1&&min(p[0][0],p[1][0])==0&&max(p[0][0],p[1][0])==n-1) { printf("YES\n"); return; }
		printf("NO\n"); return;
	}
	nc=np[0]; REP(i,nc) c[i]=p[0][i]; memset(rc,-1,sizeof(rc)); REP(i,nc) rc[c[i]]=i;
	//printf("cycle:"); REP(i,nc) printf(" %d",c[i]); puts("");

	int ccwret=0,fixidx=-1;
	if(onp[ra[0]]&&onp[rb[0]]) {
		int idx=rc[ra[0]]; assert(idx!=-1);
		while(ra[0]!=rb[0]) {
			int nidx=idx==nc-1?0:idx+1,u=c[idx],v=c[nidx];
			//int nidx=idx==0?nc-1:idx-1,u=c[idx],v=c[nidx];
			swap(a[u],a[v]); swap(ra[a[u]],ra[a[v]]); ++ccwret; idx=nidx;
		}
		fixidx=idx;
	} else {
		int dst=INT_MAX;
		REP(i,nc) if(been[c[i]]&&a[c[i]]==b[c[i]]) dst=0,fixidx=i;
		REP(i,nc) for(int x=head[c[i]];dst==INT_MAX&&x!=-1;x=nxt[x]) if(!onp[to[x]]) {
			int cur=dfs(to[x],i); if(cur==INT_MAX) continue;
			//printf("%d: %d %d = %d\n",i,c[i],to[x],cur);
			if(a[c[i]]==b[c[i]]) { dst=cur+1,fixidx=i; }
			if(a[c[i]]!=b[c[i]]) {
				if(i!=0&&i!=nc-1) { printf("NO\n"); return; }
				if(i==0) reverse(c,c+nc);
				c[nc++]=to[x]; dst=cur,fixidx=nc-1;
			}
		}
		//printf("dst: %d to %d\n",dst,c[fixidx]);
		assert(dst!=INT_MAX); ret+=2*dst;
	}
	memset(rc,-1,sizeof(rc)); REP(i,nc) rc[c[i]]=i;
	if(a[c[fixidx]]!=b[c[fixidx]]) { printf("NO\n"); return; }
	//printf("cycle:"); REP(i,nc) printf(" %d",c[i]); puts("");
	//printf("=%d\n",ccwret);
	t[fixidx]=-1;
	REP(i,nc) if(i!=fixidx) {
		int to=rc[rb[a[c[i]]]]; if(to==-1) { printf("NO\n"); return; }
		if(to<i) to+=nc; t[i]=to-i; if(to>fixidx&&i<fixidx||i>fixidx&&to>nc+fixidx) --t[i];
	}
	//printf("t:"); REP(i,nc) printf(" %d",t[i]); puts("");
	int tall=-1; REP(i,nc) if(i!=fixidx) if(tall==-1) tall=t[i]; else if(t[i]!=tall) { printf("NO\n"); return; }

	ll ret1=ret+ccwret+(ll)nc*(nc-1-tall);
	ll ret2=ret+nc-ccwret+(ll)nc*(tall-1);
	if(min(c[0],c[nc-1])==0&&max(c[0],c[nc-1])==n-1) printf("YES\n"); else printf("NO\n");
}

int main() {
	run();
	return 0;
}