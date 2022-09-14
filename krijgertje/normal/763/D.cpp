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

const int MAXN=100000;
const int MAXM=MAXN-1;
const int MAXID=2*MAXN;

int n;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];

map<vector<int>,int> mp; 
int id[MAXN],parid[MAXN],nid;

void dfs1(int at,int par) {
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfs1(to,at);
	}
	vector<int> cur;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		cur.PB(id[to]);
	}
	sort(cur.begin(),cur.end());
	if(!mp.count(cur)) mp[cur]=nid++;
	id[at]=mp[cur];
}
int tmp[MAXID];
void dfs2(int at,int par) {
	vector<int> cur;
	if(par!=-1) cur.PB(parid[at]);
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		cur.PB(id[to]);
	}
	sort(cur.begin(),cur.end());
	if(SZ(cur)!=0) {
		int other=cur.back(); bool diff=true; cur.pop_back();
		for(int i=SZ(cur);i>=0;--i) {
			if(diff) {
				if(!mp.count(cur)) mp[cur]=nid++;
				tmp[other]=mp[cur];
			}
			if(i>=1) diff=cur[i-1]!=other,swap(cur[i-1],other);
		}
	}
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		parid[to]=tmp[id[to]];
	}
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfs2(to,at);
	}
}
int cnt[MAXID],cntdiff,retdiff,ret;
void mod(int x,int by) {
	int c=cnt[x]>=1?1:0;
	cnt[x]+=by;
	c-=cnt[x]>=1?1:0;
	cntdiff-=c;
}
void dfs3(int at,int par) {
	if(par!=-1) mod(id[at],+1);
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfs3(to,at);
	}
}
void dfs4(int at,int par) {
	//printf("%d: %d\n",at,cntdiff);
	if(cntdiff>retdiff) retdiff=cntdiff,ret=at;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		mod(id[to],-1); mod(parid[to],+1);
		dfs4(to,at);
		mod(id[to],+1); mod(parid[to],-1);
	}
}

int solve() {
	mp=map<vector<int>,int>(); nid=0;
	dfs1(0,-1);
	parid[0]=-1; dfs2(0,-1);
	//REP(i,n) printf("%d: %d %d\n",i,id[i],parid[i]);

	memset(cnt,0,sizeof(cnt)); cntdiff=0;
	dfs3(0,-1);
	ret=-1,retdiff=-1; dfs4(0,-1);
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	int ret=solve();
	printf("%d\n",ret+1);
}

void gen() {
	n=MAXN; REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a=0,b=i+1;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	solve();
	printf("done (%d,%d)\n",ret,retdiff);
}

int main() {
	run();
	//gen();
	return 0;
}