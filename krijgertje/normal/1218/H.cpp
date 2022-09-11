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

const int MAXN=200000;
const int MAXQ=100000;

int n;
int nxt[MAXN];
int nq;
ll qsteps[MAXQ]; int qidx[MAXQ]; int qans[MAXQ];

vector<vector<int>> cycs;
bool incyc[MAXN];
int state[MAXN];
vector<int> ch[MAXN];
vector<int> q[MAXN];

vector<int> res[MAXN];

int merge(int a,int b) {
	if(SZ(res[a])<SZ(res[b])) swap(a,b);
	REPSZ(i,res[b]) { int k=SZ(res[b])-i-1; res[a][SZ(res[a])-k-1]+=res[b][i]; }
	res[b]=vector<int>();
	return a;
}
int dfstree(int at) {
	int ret=at; res[ret].clear();
	REPSZ(i,ch[at]) {
		int to=ch[at][i];
		int sub=dfstree(to);
		ret=merge(ret,sub);
	}
	res[ret].PB(1);
	//printf("%d:",at+1); REPSZ(i,res[ret]) printf(" %d",res[ret][SZ(res[ret])-i-1]); puts("");
	if(!incyc[at]) REPSZ(i,q[at]) { int id=q[at][i]; qans[id]=qsteps[id]<SZ(res[ret])?res[ret][SZ(res[ret])-qsteps[id]-1]:0; }
	return ret;
}
void dfsadd(int at,int dep,vector<int> &lst) {
	while(dep>=SZ(lst)) lst.PB(0); ++lst[dep];
	REPSZ(i,ch[at]) { int to=ch[at][i]; dfsadd(to,dep+1,lst); }
}

void solve() {
	cycs.clear();
	REP(i,n) state[i]=0;
	REP(i,n) if(state[i]==0) {
		int at=i; while(state[at]==0) { state[at]=1; at=nxt[at]; }
		if(state[at]==1) { vector<int> cyc; while(state[at]==1) { state[at]=2; cyc.PB(at); at=nxt[at]; } cycs.PB(cyc); }
		at=i; while(state[at]==1) { state[at]=2; at=nxt[at]; }
	}
	REP(i,n) incyc[i]=false; REPSZ(i,cycs) REPSZ(j,cycs[i]) incyc[cycs[i][j]]=true;
	//REPSZ(i,cycs) { printf("cyc%d:",i); REPSZ(j,cycs[i]) printf(" %d",cycs[i][j]+1); puts(""); }

	REP(i,n) q[i].clear();
	REP(i,nq) q[qidx[i]].PB(i);
	REP(i,nq) qans[i]=-1;
	REP(i,n) ch[i].clear();
	REP(i,n) if(!incyc[i]) ch[nxt[i]].PB(i);
	REP(i,n) res[i].clear();
	REP(i,n) if(incyc[i]) { int sub=dfstree(i); res[sub]=vector<int>(); }

	REPSZ(i,cycs) {
		vector<int> cyc=cycs[i];
		vector<int> cnt;
		REPSZ(j,cyc) {
			int at=cyc[j];
			dfsadd(at,SZ(cyc)-j,cnt);
			//printf("after %d:",at+1); REPSZ(k,cnt) printf(" %d",cnt[k]); puts("");
			REPSZ(k,q[at]) { int id=q[at][k]; ll need=qsteps[id]+SZ(cyc)-j; qans[id]=need<SZ(cnt)?cnt[need]:0; }
		}
		FORSZ(k,SZ(cyc),cnt) cnt[k]+=cnt[k-SZ(cyc)];
		REPSZ(j,cyc) {
			int at=cyc[j];
			REPSZ(k,q[at]) { int id=q[at][k]; ll need=qsteps[id]-j; if(need>=SZ(cnt)) need-=(need-SZ(cnt)+SZ(cyc))/SZ(cyc)*SZ(cyc); if(need>=0) qans[id]+=cnt[need]; }
		}
	}

}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&nxt[i]),--nxt[i];
	scanf("%d",&nq);
	REP(i,nq) scanf("%lld%d",&qsteps[i],&qidx[i]),--qidx[i];
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}