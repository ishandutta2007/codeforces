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
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

typedef struct E { int to,ind; } E;

int n,m;
vector<vector<E> > adj;

vector<int> go(int s,int t) {
//	printf("trying %d-%d\n",s,t);
	vector<bool> used(m+1,false);
	
	stack<pair<int,int> > stck;
	vector<int> pos(n,0);
	stck.push(MP(s,-1));
	vector<int> ret;
		
	while(!stck.empty()) {
		int at=stck.top().first;
		while(pos[at]<SZ(adj[at])&&used[adj[at][pos[at]].ind]) ++pos[at];
		if(pos[at]<SZ(adj[at])) {
			int to=adj[at][pos[at]].to,ind=adj[at][pos[at]].ind;
			stck.push(MP(to,ind));
			used[ind]=true;
		} else {
			ret.PB(stck.top().second);
			stck.pop();
		}
	}
	ret.pop_back();
	return ret;
}

// nodes should all be connected
vector<int> get(vector<int> nodes,bool alwaysok) {
	vector<int> odd;
	REPSZ(i,nodes) if(SZ(adj[nodes[i]])%2!=0) odd.PB(nodes[i]);
	if(SZ(odd)==0) {
		VI ret=go(nodes[0],nodes[1]);
		if(alwaysok) assert(SZ(ret)==m);
		return ret;
	}
	if(SZ(odd)==2) {
		VI ret=go(odd[0],odd[1]);
		if(alwaysok) assert(SZ(ret)==m);
		return ret;
	}
	if(alwaysok) assert(false);
	return VI();
}

void run() {
	n=10001; adj=vector<vector<E> >(n);
	scanf("%d",&m);
	vector<int> aa(m+1),bb(m+1); aa[0]=bb[0]=-1;
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); adj[a].PB((E){b,i+1}); adj[b].PB((E){a,i+1}); aa[i+1]=a; bb[i+1]=b; }
	
	vector<vector<int> > comps;
	vector<bool> been(n,false);
	REP(i,n) if(!been[i]&&SZ(adj[i])>0) {
		vector<int> comp;
		queue<int> q;
		q.push(i); been[i]=true;
		while(!q.empty()) {
			int at=q.front(); q.pop(); comp.PB(at);
			REPSZ(j,adj[at]) { int to=adj[at][j].to; if(!been[to]) been[to]=true,q.push(to); }
		}		
		comps.PB(comp);
	}
	
	if(SZ(comps)>2) { printf("-1\n"); return;	}

	vector<int> odd; REP(i,n) if(SZ(adj[i])%2==1) odd.PB(i);
	if(SZ(odd)>4) { printf("-1\n"); return; }
	
	VI p1,p2;
	
	if(SZ(comps)==1) {
		if(SZ(odd)!=4) {
			VI p=get(comps[0],true);
			if(SZ(p)>=2) { p1.PB(p[0]); FORSZ(j,1,p) p2.PB(p[j]); }
		} else {
			FOR(i,1,4) {
				int j=i==1?2:1;
				int a=odd[0],b=odd[i],c=odd[j],d=odd[6-i-j];
				adj[b].PB((E){c,0}); adj[c].PB((E){b,0});
				VI p=get(comps[0],false);
				if(SZ(p)==m+1) {
					REPSZ(j,p) if(p[j]==0) { REP(k,j) p1.PB(p[k]); FORSZ(k,j+1,p) p2.PB(p[k]); break; }
					break;
				}
				adj[b].pop_back(); adj[c].pop_back();
			}
		}
	} else {
		p1=get(comps[0],false);
		p2=get(comps[1],false);
	}
	
	if(SZ(p1)>0&&SZ(p2)>0&&SZ(p1)+SZ(p2)==m) {
		printf("%d\n",SZ(p1)); REPSZ(i,p1) { if(i!=0) printf(" "); printf("%d",p1[i]); } puts("");
		printf("%d\n",SZ(p2)); REPSZ(i,p2) { if(i!=0) printf(" "); printf("%d",p2[i]); } puts("");
	} else {
		printf("-1\n");
	}
		
//	printf("%d\n",SZ(odd)); REPSZ(i,odd) printf("%d ",odd[i]); puts("");
//	REPSZ(i,path) printf("%d (%d %d)\n",path[i],aa[path[i]],bb[path[i]]);
}

int main() {
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}