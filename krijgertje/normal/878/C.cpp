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

const int MAXN=50000;
const int MAXSPORTS=10;

int n,nsport;
int s[MAXN][MAXSPORTS];

int nxt[MAXN],prv[MAXN],head,tail;
pair<int,int> range[MAXN][MAXSPORTS];

int par[MAXN],sz[MAXN];
int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
int unite(int a,int b) {
	a=find(a),b=find(b); assert(a!=b);
	if(sz[a]<sz[b]) swap(a,b);
	par[b]=a,sz[a]+=sz[b];
	REP(j,nsport) range[a][j].first=min(range[a][j].first,range[b][j].first),range[a][j].second=max(range[a][j].second,range[b][j].second);
	return a;
}

map<int,int> who[MAXSPORTS];
set<int> best[MAXSPORTS];
set<int> worst[MAXSPORTS];

void run() {
	scanf("%d%d",&n,&nsport); REP(i,n) REP(j,nsport) scanf("%d",&s[i][j]);
	
	REP(i,n) REP(j,nsport) who[j][s[i][j]]=i;
	REP(i,n) par[i]=i,sz[i]=1,nxt[i]=prv[i]=-1; head=tail=-1; REP(i,n) REP(j,nsport) range[i][j]=MP(s[i][j],s[i][j]);
	REP(i,n) {
		int mxwin=-1;
		REP(j,nsport) {
			auto it=worst[j].lower_bound(s[i][j]); if(it==worst[j].begin()) continue; else --it;
			int cur=find(who[j][*it]);
			if(mxwin==-1||range[cur][0].first>range[mxwin][0].first) mxwin=cur;
		}
		int mnlose=-1;
		REP(j,nsport) {
			auto it=best[j].lower_bound(s[i][j]); if(it==best[j].end()) continue;
			int cur=find(who[j][*it]);
			if(mnlose==-1||range[cur][0].first<range[mnlose][0].first) mnlose=cur;
		}
		//printf("mxwin=%d mnlose=%d\n",mxwin,mnlose);
		if(mxwin==-1&&mnlose==-1) {
			assert(head==-1&&tail==-1);
			head=tail=i;
			REP(j,nsport) worst[j].insert(range[i][j].first),best[j].insert(range[i][j].second);
		} else if(mxwin==-1) {
			assert(mnlose==tail);
			nxt[tail]=i,prv[i]=tail,tail=i;
			REP(j,nsport) worst[j].insert(range[i][j].first),best[j].insert(range[i][j].second);
		} else if(mnlose==-1) {
			assert(mxwin==head);
			prv[head]=i,nxt[i]=head,head=i;
			REP(j,nsport) worst[j].insert(range[i][j].first),best[j].insert(range[i][j].second);
		} else if(range[mxwin][0].first<range[mnlose][0].first) {
			assert(nxt[mnlose]==mxwin);
			nxt[mnlose]=i,prv[i]=mnlose,nxt[i]=mxwin,prv[mxwin]=i;
			REP(j,nsport) worst[j].insert(range[i][j].first),best[j].insert(range[i][j].second);
		} else {
			vector<int> merge; for(int x=mxwin;x!=-1;x=nxt[x]) { merge.PB(x); if(x==mnlose) break; } assert(merge.back()==mnlose);
			REPSZ(k,merge) REP(j,nsport) worst[j].erase(range[merge[k]][j].first),best[j].erase(range[merge[k]][j].second);
			int cur=i; REPSZ(k,merge) cur=unite(cur,merge[k]);
			REP(j,nsport) worst[j].insert(range[cur][j].first),best[j].insert(range[cur][j].second);
			prv[cur]=prv[mxwin]; if(prv[cur]==-1) head=cur; else nxt[prv[cur]]=cur;
			nxt[cur]=nxt[mnlose]; if(nxt[cur]==-1) tail=cur; else prv[nxt[cur]]=cur;
		}
		//for(int x=head;x!=-1;x=nxt[x]) { printf("%d:",x); REP(j,nsport) printf(" [%d..%d]",range[x][j].first,range[x][j].second); puts(""); }
		printf("%d\n",sz[head]);
	}
}

int main() {
	run();
	return 0;
}