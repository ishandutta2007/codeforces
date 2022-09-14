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

int n,m;
vector<vector<int> > e;
vector<pair<int,int> > elst;

void run() {
	scanf("%d%d",&n,&m);
	e=vector<vector<int> >(n); elst.clear();
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; e[a].PB(b); e[b].PB(a); elst.PB(MP(a,b)); }
	
	bool foundcycle=false; vector<int> cycle;
	vector<int> color(n,-1);
	REP(i,n) if(color[i]==-1) {
		stack<pair<int,int> > stack;
		color[i]=0; stack.push(MP(i,0));
		while(SZ(stack)>0) {
			int at=stack.top().first,j=stack.top().second; stack.pop();
			if(foundcycle) {
				if(at==cycle[0]) {
					cycle.PB(at); reverse(cycle.begin(),cycle.end()); cycle.pop_back();
					break;
				}
				cycle.PB(at); continue;
			}
			if(j>=SZ(e[at])) continue; else stack.push(MP(at,j+1));
			int to=e[at][j];
			if(color[to]==-1) { color[to]=1-color[at]; stack.push(MP(to,0)); continue; }
			if(color[to]!=color[at]) continue;
			foundcycle=true; cycle.PB(to);
		}
		if(foundcycle) break;
	}
	
	if(!foundcycle) {
		printf("%d\n",m);
		FORE(i,1,m) { if(i!=1) printf(" "); printf("%d",i); } puts("");
		return;
	}
		
//	printf("cycle:"); REPSZ(i,cycle) printf(" %d",cycle[i]); puts("");
	
	int len=SZ(cycle);
	vector<bool> oncycle(n,false);
	REPSZ(i,cycle) oncycle[cycle[i]]=true;
	vector<int> cycleind(n,-1);
	REPSZ(i,cycle) cycleind[cycle[i]]=i;
	
	int need=0;
	vector<int> delta(len+1,0);
	color=vector<int>(n,-1);
	REP(i,n) if(!oncycle[i]&&color[i]==-1) {
		stack<pair<int,int> > stack;
		color[i]=0; stack.push(MP(i,0));
		vector<pair<int,int> > cyclecols;
		while(SZ(stack)>0) {
			int at=stack.top().first,j=stack.top().second; stack.pop();
			if(j>=SZ(e[at])) continue; else stack.push(MP(at,j+1));
			int to=e[at][j];
			if(oncycle[to]) {
				cyclecols.PB(MP(cycleind[to],1-color[at]));
				continue;
			}
			if(color[to]==-1) { color[to]=1-color[at]; stack.push(MP(to,0)); continue; }
			if(color[to]!=color[at]) continue;
			printf("0\n\n"); return;
		}
		sort(cyclecols.begin(),cyclecols.end());
//		REPSZ(j,cyclecols) printf("%d: %d\n",cyclecols[j].first,cyclecols[j].second); puts("");		
		FORSZ(j,1,cyclecols) {
			int a=cyclecols[j-1].first,b=cyclecols[j].first;
			bool same=cyclecols[j-1].second==cyclecols[j].second;
			++need;
			if((b-a)%2==0&&!same||(b-a)%2!=0&&same) {
				++delta[a],--delta[b];
			} else {
				++delta[0],--delta[a],++delta[b],--delta[len];
			}
		}
	}
	REP(at,n) if(oncycle[at]) {
		REPSZ(i,e[at]) {
			int to=e[at][i];
			if(!oncycle[to]) continue;
			int a=cycleind[at],b=cycleind[to];
			if(a>b) continue;
			if(a+1==b||a==0&&b==len-1) continue;
			bool same=false;
			++need;
			if((b-a)%2==0&&!same||(b-a)%2!=0&&same) {
				++delta[a],--delta[b];
			} else {
				++delta[0],--delta[a],++delta[b],--delta[len];
			}
		}
	}
	
	int have=0;
	vector<bool> oktonext(len,false);
	REP(i,len) {
//		printf("%d = %d\n",i,have);
		have+=delta[i];
		if(have==need) oktonext[i]=true;
	}
	
	vector<int> res;
	REPSZ(i,elst) {
		int A=elst[i].first,B=elst[i].second;
		if(!oncycle[A]||!oncycle[B]) continue;
		int a=cycleind[A],b=cycleind[B];
		if(a>b) swap(a,b);
		if(a+1==b&&oktonext[a]||a==0&&b==len-1&&oktonext[b]) res.PB(i+1);
	}
	
	printf("%d\n",SZ(res));
	REPSZ(i,res) { if(i!=0) printf(" "); printf("%d",res[i]); } puts("");
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}