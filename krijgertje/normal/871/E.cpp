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

const int MAXN=30000;
const int MAXK=200;

int n,k;
int d[MAXK][MAXN],drt[MAXK];

int rt;
int depth[MAXN];
vector<int> childs[MAXN]; int parent[MAXN];
vector<int> todo[MAXN];
int intodo[MAXN];
int mark[MAXN];

void dfsmark(int at,int val) {
	if(mark[at]!=-1) return; else mark[at]=val;
	REPSZ(i,todo[at]) mark[todo[at][i]]=val;
	REPSZ(i,childs[at]) dfsmark(childs[at][i],val);
}
void updatetodo(int x) {
	vector<int> ntodo; REPSZ(i,todo[x]) if(intodo[todo[x][i]]==x) ntodo.PB(todo[x][i]); todo[x]=ntodo;
}

bool solve() {
	REP(i,k) { drt[i]=-1; REP(j,n) if(d[i][j]==0) if(drt[i]!=-1) return false; else drt[i]=j; if(drt[i]==-1) return false; }
	rt=drt[0]; REP(j,n) depth[j]=d[0][j],childs[j].clear(),parent[j]=-2,todo[j].clear();
	REP(j,n) if(j!=rt) todo[rt].PB(j),intodo[j]=rt; intodo[rt]=-1,parent[rt]=-1;
	//printf("init succeeded rt=%d\n",rt+1);
	FOR(i,1,k) {
		int crt=drt[i];
		vector<int> path(depth[crt]+1,-1);
		//printf("processing %d with path length %d\n",crt+1,SZ(path));
		REP(j,n) if(d[i][j]+depth[j]==depth[crt]) if(path[depth[j]]!=-1) return false; else path[depth[j]]=j; REPSZ(k,path) if(path[k]==-1) return false;
		//printf("path:"); REPSZ(k,path) printf(" %d",path[k]+1); puts("");
		vector<vector<int> > subtree(depth[crt]+1);
		REP(j,n) {
			//2*depth[lca]=depth[j]+depth[crt]-d[i][j]
			if((depth[j]+depth[crt]-d[i][j])%2!=0) return false;
			int dlca=(depth[j]+depth[crt]-d[i][j])/2; if(dlca<0||dlca>depth[crt]) return false;
			if(j!=path[dlca]) subtree[dlca].PB(j);
		}
		//printf("subtrees:"); REPSZ(k,path) { printf(" ("); REPSZ(l,subtree[k]) { if(l!=0) printf(","); printf("%d",subtree[k][l]+1); } printf(")"); } puts("");
		int pos=depth[crt]; while(pos>=0&&intodo[path[pos]]!=-1) --pos; if(pos<0) return false;
		int mrt=path[pos];
		//printf("mrt=%d at %d\n",mrt+1,pos);
		REP(j,n) mark[j]=-1;
		for(int k=pos;k>=0;--k) {
			if(intodo[path[k]]!=-1) return false;
			if(k!=0&&parent[path[k]]!=path[k-1]||k==0&&parent[path[k]]!=-1) return false;
			dfsmark(path[k],path[k]);
		}
		//printf("mark:"); REP(j,n) printf(" %d",mark[j]+1); puts("");
		REPE(k,pos) {
			if(mark[path[k]]!=path[k]) return false;
			REPSZ(l,subtree[k]) {
				if(mark[subtree[k][l]]!=path[k]) return false;
			}
		}
		//printf("here\n");
		FORSZ(k,pos+1,path) {
			if(intodo[path[k]]!=mrt) return false;
			intodo[path[k]]=-1; parent[path[k]]=path[k-1]; childs[path[k-1]].PB(path[k]);
			REPSZ(l,subtree[k]) {
				if(intodo[subtree[k][l]]!=mrt) return false;
				intodo[subtree[k][l]]=path[k]; todo[path[k]].PB(subtree[k][l]);
			}
		}
		updatetodo(mrt);
		//REP(j,n) if(intodo[j]==-1) { printf("%d: parent=%d todo:",j+1,parent[j]+1); REPSZ(k,todo[j]) printf(" %d",todo[j][k]+1); puts(""); }
	}
	REP(j,n) if(SZ(todo[j])>0) {
		int dmx=depth[j]; REPSZ(k,todo[j]) if(depth[todo[j][k]]>dmx) dmx=depth[todo[j][k]];
		vector<int> fst(dmx-depth[j]+1,-1); fst[0]=j; REPSZ(k,todo[j]) { int cur=depth[todo[j][k]]-depth[j]; if(cur<=0) return false; else if(fst[cur]==-1) fst[cur]=todo[j][k]; }
		REPSZ(k,fst) if(fst[k]==-1) return false;
		REPSZ(k,todo[j]) { int cur=depth[todo[j][k]]-depth[j]; parent[todo[j][k]]=fst[cur-1]; childs[fst[cur-1]].PB(todo[j][k]); }
	}
	return true;
}

void run() {
	scanf("%d%d",&n,&k);
	REP(i,k) REP(j,n) scanf("%d",&d[i][j]);

	if(!solve()) { printf("-1\n"); return; }
	REP(i,n) if(parent[i]!=-1) printf("%d %d\n",i+1,parent[i]+1);
}

int main() {
	run();
	return 0;
}