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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXWEAPON=5000;
const int MAXTARGET=5000;
const int MAXLG=12;

int nweapon,ntarget;
int wkind[MAXWEAPON]; vector<int> wpar[MAXWEAPON];


struct G {
	int n,m;
	vector<int> ghead,gnxt,gto,gcap,gflow;
	vector<int> gat;

	void init(int _n) { n=_n; m=0; ghead=vector<int>(n,-1); }
	void addedge(int a,int b,int c) { /*printf("add(%d,%d,%d)\n",a,b,c);*/ gnxt.PB(ghead[a]),ghead[a]=2*m+0,gto.PB(b),gcap.PB(c),gflow.PB(0); gnxt.PB(ghead[b]),ghead[b]=2*m+1,gto.PB(a),gcap.PB(0),gflow.PB(0); ++m; }

	/*vector<int> flow,back,q; int qhead,qtail;
	int mf(int s,int t) {
		int ret=0;
		flow=back=q=vector<int>(n);
		while(true) {
			REP(i,n) flow[i]=0,back[i]=-2; qhead=qtail=0; flow[s]=INT_MAX,back[s]=-1,q[qhead++]=s;
			while(qtail<qhead&&flow[t]==0) {
				int at=q[qtail++];
				//printf("%d = %d\n",at,flow[at]);
				for(int x=ghead[at];x!=-1;x=gnxt[x]) {
					int to=gto[x]; if(gcap[x]>0&&flow[to]==0) flow[to]=min(flow[at],gcap[x]),back[to]=x^1,q[qhead++]=to;
				}
			}
			if(flow[t]==0) return ret;
			ret+=flow[t];
			for(int at=t;at!=s;at=gto[back[at]]) {
				gcap[back[at]^1]-=flow[t]; gflow[back[at]^1]+=flow[t];
				gcap[back[at]]+=flow[t]; gflow[back[at]]-=flow[t];
			}
		}
	}*/

	vector<int> d,q,cur; int qhead,qtail;
	int mf(int s,int t) {
		d=q=cur=vector<int>(n);
		int ret=0; int niter=0;
		while(true) {
			REP(i,n) d[i]=INT_MAX; qhead=qtail=0; d[s]=0,q[qhead++]=s;
			while(qtail<qhead&&d[t]==INT_MAX) { int at=q[qtail++];for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(gcap[x]==0||d[to]!=INT_MAX) continue; d[to]=d[at]+1; q[qhead++]=to; } }
			if(d[t]==INT_MAX) { return ret; }
			REP(i,n) cur[i]=ghead[i];
			ret+=dfs(s,t,INT_MAX); ++niter;
		}
	}
	int dfs(int at,int t,int rem) {
		int ret=0; if(at==t) return rem;
		if(d[at]>=d[t]) return 0;
		for(;cur[at]!=-1;cur[at]=gnxt[cur[at]]) {
			int to=gto[cur[at]],cap=gcap[cur[at]]; if(d[to]!=d[at]+1||cap==0) continue;
			int now=dfs(to,t,min(cap,rem));
			rem-=now; ret+=now; gcap[cur[at]]-=now; gcap[cur[at]^1]+=now; gflow[cur[at]]+=now; gflow[cur[at]^1]-=now; if(rem==0) return ret;
		}
		return ret;
	}

	vector<int> getpath(int s,int t) {
		if(SZ(gat)==0) gat=ghead;
		vector<int> ret(1,s);
		while(ret.back()!=t) {
			int at=ret.back(); bool found=false;
			for(;gat[at]!=-1;gat[at]=gnxt[gat[at]]) {
				int x=gat[at];
				if(x%2==0&&gflow[x]>0) {
					int to=gto[x];
					++gcap[x],--gcap[x^1],--gflow[x],++gflow[x^1];
					ret.PB(to); found=true; break;
				}
			}
			if(!found) return vector<int>();
		}
		return ret;
	}
};

int sid,tid,lid[MAXWEAPON],rid[MAXTARGET][MAXLG+1],nid;
G g;
vector<int> kill[MAXWEAPON]; int killedby[MAXTARGET];
vector<pair<int,int>> ans;

void solve() {
	nid=0; sid=nid++; tid=nid++; memset(rid,-1,sizeof(rid)); REP(i,nweapon) lid[i]=nid++; REPE(k,MAXLG) REP(i,ntarget) if(i+(1<<k)<=ntarget) rid[i][k]=nid++;
	//printf("nid=%d\n",nid);
	g.init(nid);
	REP(i,nweapon) g.addedge(sid,lid[i],wkind[i]==2?2:1);
	REP(i,nweapon) {
		if(wkind[i]==0) REPSZ(j,wpar[i]) g.addedge(lid[i],rid[wpar[i][j]][0],1);
		if(wkind[i]==1) { int l=wpar[i][0],r=wpar[i][1]; int k=0; while(l+(2<<k)-1<=r) ++k; g.addedge(lid[i],rid[l][k],1); if(r-(1<<k)+1!=l) g.addedge(lid[i],rid[r-(1<<k)+1][k],1); }
		if(wkind[i]==2) REPSZ(j,wpar[i]) g.addedge(lid[i],rid[wpar[i][j]][0],1);
	}
	REP(i,ntarget) FORE(k,1,MAXLG) if(rid[i][k]!=-1) g.addedge(rid[i][k],rid[i][k-1],1<<(k-1)),g.addedge(rid[i][k],rid[i+(1<<(k-1))][k-1],1<<(k-1));
	REP(i,ntarget) g.addedge(rid[i][0],tid,1);
	int flow=g.mf(sid,tid);
	//printf("flow=%d\n",flow);
	REP(i,nweapon) kill[i].clear(); REP(i,ntarget) killedby[i]=-1;
	REPE(i,flow) {
		vector<int> path=g.getpath(sid,tid);
		//printf("%d:",i); REPSZ(j,path) printf(" %d",path[j]); puts("");
		assert((SZ(path)==0)==(i==flow));
		if(i==flow) break;
		int a=path[1]-lid[0],b=path[SZ(path)-2]-rid[0][0];
		//printf("%d->%d\n",a+1,b+1);
		kill[a].PB(b); assert(killedby[b]==-1); killedby[b]=a;
	}
	REP(i,nweapon) if(wkind[i]==2&&SZ(kill[i])==1) {
		REPSZ(j,wpar[i]) {
			int oth=wpar[i][j];
			assert(killedby[oth]!=-1); if(killedby[oth]==i) continue;
			int ii=killedby[oth]; assert(wkind[ii]!=2&&SZ(kill[ii])==1); kill[ii].clear(); killedby[oth]=i; kill[i].PB(oth); break;
		}
		assert(SZ(kill[i])==2);
	}
	REP(i,nweapon) assert(SZ(kill[i])==0||SZ(kill[i])==(wkind[i]==2?2:1));
	ans.clear(); REP(i,nweapon) REPSZ(j,kill[i]) ans.PB(MP(i,kill[i][j]));
}

void run() {
	scanf("%d%d",&nweapon,&ntarget);
	REP(i,nweapon) {
		scanf("%d",&wkind[i]);
		if(wkind[i]==0) { int cnt; scanf("%d",&cnt); REP(j,cnt) { int x; scanf("%d",&x); --x; wpar[i].PB(x); } }
		if(wkind[i]==1) { int l,r; scanf("%d%d",&l,&r); --l,--r; wpar[i].PB(l),wpar[i].PB(r); }
		if(wkind[i]==2) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b,--c; wpar[i].PB(a),wpar[i].PB(b),wpar[i].PB(c); }
	}
	solve();
	printf("%d\n",SZ(ans)); REPSZ(i,ans) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
}

int main() {
	run();
	return 0;
}