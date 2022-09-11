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

const int MAXN=49;

int n;
int g[MAXN][MAXN];

bool local=false;
int loc[MAXN][MAXN];

int sloc[2*MAXN-1];
bool dfslocal(int x,int y,int tx,int ty,int len) {
	sloc[len++]=loc[x][y];
	if(tx==x&&ty==y) { bool ok=true; REP(i,len) if(sloc[i]!=sloc[len-i-1]) ok=false; return ok; }
	if(x+1<=tx&&dfslocal(x+1,y,tx,ty,len)) return true;
	if(y+1<=ty&&dfslocal(x,y+1,tx,ty,len)) return true;
	return false;
}

int query(int lx,int ly,int hx,int hy) {
	assert(lx<=hx&&ly<=hy&&lx+ly+2<=hx+hy);
	if(local) {
		return dfslocal(lx,ly,hx,hy,0)?1:0;
	} else {
		printf("? %d %d %d %d\n",lx+1,ly+1,hx+1,hy+1); fflush(stdout); int ret; scanf("%d",&ret); if(ret==-1) exit(0); return ret;
	}
}

void genpaths(int x,int y,int tx,int ty,vector<pair<int,int>> &path,vector<vector<pair<int,int>>> &paths) {
	path.PB(MP(x,y));
	if(x==tx&&y==ty) paths.PB(path);
	if(x+1<=tx) genpaths(x+1,y,tx,ty,path,paths);
	if(y+1<=ty) genpaths(x,y+1,tx,ty,path,paths);
	path.pop_back();
}

void solve() {
	REP(x,n) REP(y,n) g[x][y]=-1;
	g[0][0]=1,g[n-1][n-1]=0,g[0][1]=2;
	REP(x,n) REP(y,n) {
		if(g[x][y]==-1&&y-2>=0&&g[x][y-2]!=-1) g[x][y]=g[x][y-2]^1^query(x,y-2,x,y);
		if(g[x][y]==-1&&x-2>=0&&g[x-2][y]!=-1) g[x][y]=g[x-2][y]^1^query(x-2,y,x,y);
		if(g[x][y]==-1&&x-1>=0&&y-1>=0&&g[x-1][y-1]!=-1) g[x][y]=g[x-1][y-1]^1^query(x-1,y-1,x,y);
	}
	REP(x,n) REP(y,n) {
		if(g[x][y]==-1&&y+2<n&&g[x][y+2]!=-1) g[x][y]=g[x][y+2]^1^query(x,y,x,y+2);
	}
	REP(x,n) REP(y,n) assert(g[x][y]!=-1);

	bool found=false;
	REP(sx,n) REP(sy,n) REPE(dx,3) if(!found) {
		int dy=3-dx,tx=sx+dx,ty=sy+dy; if(tx>=n||ty>=n) continue;
		vector<vector<pair<int,int>>> paths; vector<pair<int,int>> path; genpaths(sx,sy,tx,ty,path,paths);
		//printf("%d\n",SZ(paths));
		bool ok=false; 
		REPSZ(i,paths) { 
			path=paths[i]; assert(SZ(path)==4); 
			bool same02=g[path[0].first][path[0].second]==g[path[2].first][path[2].second],same13=g[path[1].first][path[1].second]==g[path[3].first][path[3].second];
			if(same02==same13) ok=true;
		}
		if(!ok) continue;
		found=true;
		int res=query(sx,sy,tx,ty);
		int mod=g[sx][sy]^g[tx][ty]^res^1;
		REP(x,n) REP(y,n) if((x+y)%2==1) g[x][y]^=mod;
	}
	assert(found);
}

void run() {
	scanf("%d",&n);
	solve();
	printf("!\n"); REP(x,n) { REP(y,n) printf("%d",g[x][y]); puts(""); } fflush(stdout);
}

void stress() {
	local=true;
	REP(rep,100000) {
		//n=5;
		while(true) { n=rand()%MAXN+1; if(n%2==1&&n>=3) break; }
		REP(i,n) REP(j,n) loc[i][j]=rand()%2; loc[0][0]=1,loc[n-1][n-1]=0;
		solve();
		bool ok=true; REP(x,n) REP(y,n) if(g[x][y]!=loc[x][y]) ok=false;
		if(ok) { if(rep%100==0) printf("."); continue; }
		printf("err\n");
		printf("have:\n"); REP(x,n) { REP(y,n) { if(y!=0) printf(" "); printf("%d",g[x][y]); } puts(""); }
		printf("want:\n"); REP(x,n) { REP(y,n) { if(y!=0) printf(" "); printf("%d",loc[x][y]); } puts(""); }
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}