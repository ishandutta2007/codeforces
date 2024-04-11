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

struct State {
	int delta;
	map<int,int> pos;
	map<int,int> neg;
	set<pair<int,pair<int,int>>> matches;

	void init() {
		delta=0; pos.clear(); neg.clear(); matches.clear();
	}

	int findmatchforpos(int x) {
		auto it=neg.lower_bound(x+delta);
		return it==neg.end()?INT_MAX:it->first-delta;
	}
	int findmatchforneg(int y) {
		auto it=pos.upper_bound(y-delta);
		return it==pos.begin()?INT_MIN:prev(it)->first+delta;
	}
	void erasepos(int x) {
		//printf("erasepos(%d)\n",x);
		assert(pos.erase(x-delta));
		int y=findmatchforpos(x);
		if(y!=INT_MAX) {
			int xx=findmatchforneg(y);
			if(xx==INT_MIN||xx<=x) assert(matches.erase(MP(y-x+2*delta,MP(x-delta,y+delta))));
			if(xx!=INT_MIN&&xx<=x&&findmatchforpos(xx)==y) matches.insert(MP(y-xx+2*delta,MP(xx-delta,y+delta)));
		}
		//print();
	}
	void eraseneg(int y) {
		//printf("eraseneg(%d)\n",y);
		assert(neg.erase(y+delta));
		int x=findmatchforneg(y);
		if(x!=INT_MIN) {
			int yy=findmatchforpos(x);
			if(yy==INT_MAX||yy>=y) assert(matches.erase(MP(y-x+2*delta,MP(x-delta,y+delta))));
			if(yy!=INT_MAX&&yy>=y&&findmatchforneg(yy)==x) matches.insert(MP(yy-x+2*delta,MP(x-delta,yy+delta)));
		}
		//print();
	}
	void insertpos(int x,int val) {
		//printf("insertpos(%d,%d)\n",x,val);
		if(pos.count(x-delta)) { pos[x-delta]+=val; return; }
		//if(neg.count(x+delta)) { int cur=neg[x+delta]; if(val<cur) { neg[x+delta]-=val; return; } eraseneg(x); val-=cur; if(val==0) return; }
		int y=findmatchforpos(x);
		if(y!=INT_MAX) {
			int xx=findmatchforneg(y);
			if(xx!=INT_MIN&&xx<x&&findmatchforpos(xx)==y) assert(matches.erase(MP(y-xx+2*delta,MP(xx-delta,y+delta))));
			if(xx==INT_MIN||xx<x) matches.insert(MP(y-x+2*delta,MP(x-delta,y+delta)));
		}
		pos[x-delta]=val;
		//print();
	}
	void insertneg(int y,int val) {
		//printf("insertneg(%d,%d)\n",y,val);
		if(neg.count(y+delta)) { neg[y+delta]+=val; return; }
		//if(pos.count(y-delta)) { int cur=pos[y-delta]; if(val<cur) { pos[y-delta]-=val; return; } erasepos(y); val-=cur; if(val==0) return; }
		int x=findmatchforneg(y);
		if(x!=INT_MIN) {
			int yy=findmatchforpos(x);
			if(yy!=INT_MAX&&yy>y&&findmatchforneg(yy)==x) assert(matches.erase(MP(yy-x+2*delta,MP(x-delta,yy+delta))));
			if(yy==INT_MAX||yy>y) matches.insert(MP(y-x+2*delta,MP(x-delta,y+delta)));
		}
		neg[y+delta]=val;
		//print();
	}
	void grow(int by) {
		//printf("growing(%d)\n",by); print();
		while(SZ(matches)!=0&&matches.begin()->first-2*delta<2*by) {
			int x=matches.begin()->second.first+delta,y=matches.begin()->second.second-delta;
			//printf("x=%d y=%d\n",x,y); print();
			assert(pos.count(x-delta)); int xval=pos[x-delta]; assert(neg.count(y+delta)); int yval=neg[y+delta];
			if(xval<yval) { neg[y+delta]-=xval; erasepos(x); } else if(xval>yval) { pos[x-delta]-=yval; eraseneg(y); } else { erasepos(x); eraseneg(y); }
		}
		delta+=by;
	}
	void print() {
		printf("\tneg:"); for(auto it=neg.begin();it!=neg.end();++it) printf(" %d=%d",it->first-delta,it->second); puts("");
		printf("\tpos:"); for(auto it=pos.begin();it!=pos.end();++it) printf(" %d=%d",it->first+delta,it->second); puts("");
		printf("\tmatches:"); for(auto it=matches.begin();it!=matches.end();++it) printf(" %d:%d-%d",it->first-2*delta,it->second.first+delta,it->second.second-delta); puts("");
	}
};

const int MAXN=100000;

int n;
vector<pair<int,int>> e[MAXN];
int nq;
vector<pair<int,int>> obs[MAXN];

State state[MAXN];

int merge(int a,int b) {
	int asz=SZ(state[a].pos)+SZ(state[a].neg),bsz=SZ(state[b].pos)+SZ(state[b].neg);
	if(asz<bsz) swap(a,b),swap(asz,bsz);
	for(auto it=state[b].pos.begin();it!=state[b].pos.end();++it) state[a].insertpos(it->first+state[b].delta,it->second);
	for(auto it=state[b].neg.begin();it!=state[b].neg.end();++it) state[a].insertneg(it->first-state[b].delta,it->second);
	return a;
}

int dfs(int at,int par,int parlen) {
	int ret=at; state[ret].init();
	REPSZ(i,e[at]) {
		int to=e[at][i].first; if(to==par) continue;
		int cur=dfs(to,at,e[at][i].second);
		ret=merge(ret,cur);
	}
	vector<pair<int,int>> extra;
	REPSZ(i,obs[at]) {
		int t=obs[at][i].first,cnt=obs[at][i].second,rem=cnt;
		{ int cur=(state[ret].pos.count(t-state[ret].delta)?state[ret].pos[t-state[ret].delta]:0)+(state[ret].pos.count(t-state[ret].delta-1)?state[ret].pos[t-state[ret].delta-1]:0); rem=min(rem,max(0,cnt-cur)); }
		{ int cur=(state[ret].neg.count(t+state[ret].delta)?state[ret].neg[t+state[ret].delta]:0)+(state[ret].neg.count(t+state[ret].delta+1)?state[ret].neg[t+state[ret].delta+1]:0); rem=min(rem,max(0,cnt-cur)); }
		if(rem>0) extra.PB(MP(t,rem)); 
	}
	state[ret].grow(1);
	REPSZ(i,extra) { int t=extra[i].first,cnt=extra[i].second; state[ret].insertneg(t-1,cnt); state[ret].insertpos(t+1,cnt); }
	state[ret].grow(parlen-1);
	//printf("dfs(%d,%d,%d):\n",at+1,par==-1?-1:par+1,parlen); state[ret].print();
	return ret;
}

int solve() {
	REP(i,n) sort(obs[i].begin(),obs[i].end());
	int res=dfs(0,-1,1);
	map<int,int> all;
	for(auto it=state[res].pos.begin();it!=state[res].pos.end();++it) all[2*(it->first+state[res].delta)+0]-=it->second;
	for(auto it=state[res].neg.begin();it!=state[res].neg.end();++it) all[2*(it->first-state[res].delta)+1]+=it->second;
	int ret=0,cur=0;
	for(auto it=all.begin();it!=all.end();++it) {
		cur+=it->second;
		ret=max(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b,c*=2; e[a].PB(MP(b,c)); e[b].PB(MP(a,c)); }
	scanf("%d",&nq);
	REP(i,nq) { int t,cnt,idx; scanf("%d%d%d",&t,&cnt,&idx); t*=2; --idx; obs[idx].PB(MP(t,cnt)); }

	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}