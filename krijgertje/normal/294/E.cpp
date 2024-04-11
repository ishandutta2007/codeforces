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

int n;
vector<pair<int,int> > e[5000];


int q[5000];
int qfirst[5001];
int qnext[5000];

void run(int casenr) {
	scanf("%d",&n); 
	REP(i,n-1) { int a,b,w; scanf("%d%d%d",&a,&b,&w); --a; --b; e[a].PB(MP(b,w)); e[b].PB(MP(a,w)); }

	ll ret=LLONG_MAX;
	REP(i,n) REPSZ(ii,e[i]) if(e[i][ii].first>i) { // edge to remove
		int da=i,db=e[i][ii].first;
		vector<int> side(n,-1); side[da]=0; side[db]=1; int qhead=0,qtail=0; q[qhead++]=da; q[qhead++]=db;
		while(qtail<qhead) { int at=q[qtail++]; REPSZ(j,e[at]) { int to=e[at][j].first; if(side[to]==-1) { side[to]=side[at]; q[qhead++]=to; } } }
		vector<int> sidecnt(2,0); REP(j,n) ++sidecnt[side[j]];
		ll cur=0;
		vector<int> deg(n); REP(j,n) deg[j]=SZ(e[j]); --deg[da]; --deg[db];
		vector<int> size(n,1);
		vector<bool> dead(n,false);
		vector<ll> sumdist(n,0);
		memset(qfirst,-1,sizeof(qfirst));
		vector<vector<int> > q(n+1);
		REP(j,n) if(deg[j]==1) { qnext[j]=qfirst[size[j]]; qfirst[size[j]]=j; }
		REPE(qq,n) for(int at=qfirst[qq];at!=-1;at=qnext[at]) {
			if(deg[at]!=1) continue;
			int cnt=0;
			REPSZ(j,e[at]) {
				int to=e[at][j].first;
				if(at==da&&to==db||at==db&&to==da) continue;
				if(dead[to]) continue;
				sumdist[to]+=sumdist[at]+size[at]*e[at][j].second;
				cur+=(ll)size[at]*(sidecnt[side[at]]-size[at])*e[at][j].second;
				dead[at]=true; size[to]+=size[at]; if(--deg[to]==1) { qnext[to]=qfirst[size[to]]; qfirst[size[to]]=to; }  ++cnt; break;
			}
			assert(cnt==1);
		}
		vector<int> roots; REP(j,n) if(!dead[j]) { assert(deg[j]==0); roots.PB(j); } assert(SZ(roots)==2);
		ll ocur=cur;
		cur+=sumdist[roots[0]]*size[roots[1]];
		cur+=sumdist[roots[1]]*size[roots[0]];
		cur+=(ll)size[roots[0]]*size[roots[1]]*e[i][ii].second;
//		printf("(%d,%d) -> %lld (%d,%d)->[%lld+%lld*%d+%lld*%d+%d*%d*%d]\n",da,db,cur,roots[0],roots[1],ocur,sumdist[roots[0]],size[roots[1]],sumdist[roots[1]],size[roots[0]],size[roots[0]],size[roots[1]],e[i][ii].second);
		if(cur<ret) ret=cur;
	}
	cout<<ret<<endl;
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}