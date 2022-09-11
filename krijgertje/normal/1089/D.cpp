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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN=200000;

int n,m;
vector<int> adj[MAXN];

bool alive[MAXN];
int deg[MAXN];
int cnt[MAXN];
int q[MAXN],qhead,qtail;
int specialidx[MAXN];
int special[MAXN],nspecial;

vector<vector<int>> paths;
vector<vector<int>> dist;

int sum[MAXN+1];
ll prodsum[MAXN+1];

int divdown(int num,int den) { if(den<0) num=-num,den=-den; return num>=0?num/den:(num-den+1)/den; }
ll solve() {
	ll ret=0;
	REP(i,n) alive[i]=true,deg[i]=SZ(adj[i]),cnt[i]=1;
	qhead=qtail=0;
	REP(i,n) if(deg[i]==1) q[qhead++]=i;
	while(qtail<qhead) {
		int at=q[qtail++]; if(deg[at]!=1) continue;
		alive[at]=false; ret+=(ll)cnt[at]*(n-cnt[at]);
		REPSZ(i,adj[at]) { int to=adj[at][i]; if(alive[to]) cnt[to]+=cnt[at],cnt[at]=0; if(--deg[to]==1) q[qhead++]=to; }
	}
	nspecial=0; REP(i,n) specialidx[i]=-1;
	REP(i,n) if(deg[i]>=3) specialidx[i]=nspecial,special[nspecial]=i,++nspecial;
	if(nspecial==0) REP(i,n) if(alive[i]&&(deg[i]==0||deg[i]==2&&nspecial==0)) specialidx[i]=nspecial,special[nspecial]=i,++nspecial;
	//printf("special:"); REP(i,nspecial) printf(" %d",special[i]+1); puts("");
	//printf("alive:"); REP(i,n) if(alive[i]) { printf(" %d",i+1); if(cnt[i]>1) printf("[%d]",cnt[i]); } puts("");
	
	paths.clear();
	REP(i,nspecial) {
		int start=special[i];
		REPSZ(j,adj[start]) {
			int at=adj[start][j]; if(!alive[at]) continue;
			vector<int> path; path.PB(start); path.PB(at);
			while(specialidx[at]==-1) {
				int to=-1; REPSZ(k,adj[at]) { int cur=adj[at][k]; if(!alive[cur]||cur==path[SZ(path)-2]) continue; assert(to==-1); to=cur; } assert(to!=-1);
				at=to; path.PB(at);
			}
			if(path[SZ(path)-1]<path[0]||path[SZ(path)-1]==path[0]&&path[SZ(path)-2]<path[1]) continue;
			paths.PB(path);
		}
	}
	//REPSZ(i,paths) { printf("path%d:",i); REPSZ(j,paths[i]) printf(" %d",paths[i][j]+1); puts(""); }
	
	dist=vector<vector<int>>(nspecial,vector<int>(nspecial,INT_MAX));
	REP(i,nspecial) dist[i][i]=0; REPSZ(i,paths) { int a=specialidx[paths[i][0]],b=specialidx[paths[i][SZ(paths[i])-1]]; dist[a][b]=min(dist[a][b],SZ(paths[i])-1); dist[b][a]=min(dist[b][a],SZ(paths[i])-1); }
	REP(k,nspecial) REP(i,nspecial) REP(j,nspecial) if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	//REP(i,nspecial) { printf("dist%d:",i); REP(j,nspecial) printf(" %d",dist[i][j]); puts(""); }
	
	REP(i,nspecial) FOR(j,i+1,nspecial) ret+=(ll)cnt[special[i]]*cnt[special[j]]*dist[i][j];
	REPSZ(i,paths) {
		//printf("during path %d %lld\n",i,ret);
		vector<int> &path=paths[i]; int a=specialidx[path[0]],b=specialidx[path[SZ(path)-1]],pathlen=SZ(path)-1;
		sum[0]=0,prodsum[0]=0; REPE(x,pathlen) { int at=path[x]; sum[x+1]=sum[x]+cnt[at],prodsum[x+1]=prodsum[x]+(ll)x*cnt[at]; }
		FORE(x,1,pathlen-1) { int at=path[x]; REP(j,nspecial) ret+=(ll)cnt[at]*cnt[special[j]]*min(x+dist[a][j],pathlen-x+dist[b][j]); }
		//printf("during path %d %lld (pathlen=%d)\n",i,ret,pathlen);
		FORE(x,1,pathlen-1) {
			int at=path[x],l=x+1,m=x+(dist[a][b]+pathlen)/2,r=pathlen-1; m=max(l-1,min(r,m));
			if(l<=m) {
				ret+=(ll)cnt[at]*(prodsum[m+1]-prodsum[l])-(ll)cnt[at]*x*(sum[m+1]-sum[l]);
			}
			if(m+1<=r) {
				ret+=(ll)cnt[at]*(x+dist[a][b]+pathlen)*(sum[r+1]-sum[m+1])-(ll)cnt[at]*(prodsum[r+1]-prodsum[m+1]);
			}
		}
		//printf("during path %d %lld\n",i,ret);
		FORSZ(j,i+1,paths) {
			vector<int> &path2=paths[j]; int c=specialidx[path2[0]],d=specialidx[path2[SZ(path2)-1]],pathlen2=SZ(path2)-1;
			sum[0]=0,prodsum[0]=0; REPE(y,pathlen2) { int at=path2[y]; sum[y+1]=sum[y]+cnt[at],prodsum[y+1]=prodsum[y]+(ll)y*cnt[at]; }
			int y1=(dist[a][d]+pathlen2-dist[a][c])/2; y1=max(0,min(pathlen2-1,y1)); // when using a, c is better iff y<=y1
			int y2=(dist[b][d]+pathlen2-dist[b][c])/2; y2=max(0,min(pathlen2-1,y2)); // when using b, c is better iff y<=y2
			int x1=(dist[b][c]+pathlen-dist[a][c])/2; // when using c, a is better iff x<=x1
			int x2=(dist[b][d]+pathlen-dist[a][d])/2; // when using d, a is better iff x<=x2
			FORE(x,1,pathlen-1) {
				//printf("during path %d and %d, x=%d: %lld (y1=%d, y2=%d)\n",i,j,x,ret,y1,y2);
				int at=path[x];
				if(1<=min(y1,y2)) { // y<=min(y1,y2) -> use ac or bc
					int l=1,r=min(y1,y2);
					if(x<=x1) {
						ret+=(ll)cnt[at]*(x+dist[a][c])*(sum[r+1]-sum[l])+(ll)cnt[at]*(prodsum[r+1]-prodsum[l]);
					} else {
						ret+=(ll)cnt[at]*(pathlen-x+dist[b][c])*(sum[r+1]-sum[l])+(ll)cnt[at]*(prodsum[r+1]-prodsum[l]);
					}
				}
				//printf("during path %d and %d, x=%d: %lld (y1=%d, y2=%d)\n",i,j,x,ret,y1,y2);
				if(y1<y2) { // y1<y<=y2 -> use ad or bc
					int l=y1+1,m=divdown(dist[a][d]+pathlen2-pathlen-dist[b][c],2)+x,r=y2; m=max(l-1,min(r,m));
					if(l<=m) {
						ret+=(ll)cnt[at]*(pathlen-x+dist[b][c])*(sum[m+1]-sum[l])+(ll)cnt[at]*(prodsum[m+1]-prodsum[l]);
					}
					if(m+1<=r) {
						ret+=(ll)cnt[at]*(x+dist[a][d]+pathlen2)*(sum[r+1]-sum[m+1])-(ll)cnt[at]*(prodsum[r+1]-prodsum[m+1]);
					}
				}
				//printf("during path %d and %d, x=%d: %lld (y1=%d, y2=%d)\n",i,j,x,ret,y1,y2);
				if(y2<y1) { // y2<y<=y1 -> use ac or bd
					int l=y2+1,m=divdown(pathlen+dist[b][d]+pathlen2-dist[a][c],2)-x,r=y1; m=max(l-1,min(r,m));
					if(l<=m) {
						ret+=(ll)cnt[at]*(x+dist[a][c])*(sum[m+1]-sum[l])+(ll)cnt[at]*(prodsum[m+1]-prodsum[l]);
					}
					if(m+1<=r) {
						ret+=(ll)cnt[at]*(pathlen-x+dist[b][d]+pathlen2)*(sum[r+1]-sum[m+1])-(ll)cnt[at]*(prodsum[r+1]-prodsum[m+1]);
					}
				}
				//printf("during path %d and %d, x=%d: %lld (y1=%d, y2=%d)\n",i,j,x,ret,y1,y2);
				if(max(y1,y2)+1<=pathlen2-1) { // max(y1,y2)<y -> use ad or bd
					int l=max(y1,y2)+1,r=pathlen2-1;
					if(x<=x2) {
						ret+=(ll)cnt[at]*(x+dist[a][d]+pathlen2)*(sum[r+1]-sum[l])-(ll)cnt[at]*(prodsum[r+1]-prodsum[l]);
					} else {
						ret+=(ll)cnt[at]*(pathlen-x+dist[b][d]+pathlen2)*(sum[r+1]-sum[l])-(ll)cnt[at]*(prodsum[r+1]-prodsum[l]);
					}
				}
				//printf("during path %d and %d, x=%d: %lld (y1=%d, y2=%d)\n",i,j,x,ret,y1,y2);
			}
		}
		//printf("during path %d %lld\n",i,ret);
	}
	
	return ret;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%lld\n",solve());
}

ll solvestupid() {
	ll ret=0;
	REP(i,n) {
		REP(j,n) cnt[j]=INT_MAX;
		qhead=qtail=0; cnt[i]=0,q[qhead++]=i;
		while(qtail<qhead) {
			int at=q[qtail++]; if(at<i) ret+=cnt[at];
			REPSZ(k,adj[at]) { int to=adj[at][k]; if(cnt[to]==INT_MAX) cnt[to]=cnt[at]+1,q[qhead++]=to; }
		}
	}
	return ret;
}

void stress() {
	REP(rep,10000) {
		n=1000,m=n-1+rand()%min(n,44);
		vector<int> par(n); REP(i,n) par[i]=i,adj[i].clear(); int ncomp=n; set<pair<int,int>> seen;
		while(ncomp>1) { int a=rand()%n,b=rand()%n; if(par[a]==par[b]) continue; if(a>b) swap(a,b); adj[a].PB(b),adj[b].PB(a),seen.insert(MP(a,b)); REP(i,n) if(i!=b&&par[i]==par[b]) par[i]=par[a]; par[b]=par[a]; --ncomp; }
		REP(i,m-(n-1)) while(true) { int a=rand()%n,b=rand()%n; if(a>b) swap(a,b); if(a==b||seen.count(MP(a,b))) continue; adj[a].PB(b),adj[b].PB(a),seen.insert(MP(a,b)); break; }
		ll have=solve();
		ll want=solvestupid();
		if(have==want) { printf("."); continue; }
		printf("have=%lld want=%lld\n",have,want);
		printf("%d %d\n",n,m);
		REP(i,n) REPSZ(j,adj[i]) { int a=i,b=adj[i][j]; if(a<b) printf("%d %d\n",a+1,b+1); }
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}