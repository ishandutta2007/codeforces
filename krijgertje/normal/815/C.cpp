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

const int MAXN=5000;

int n,have;
int cost[MAXN],discount[MAXN],par[MAXN];
vector<int> childs[MAXN];

vector<ll> merge(vector<ll> &a,vector<ll> &b) {
	int na=SZ(a),nb=SZ(b);
	vector<ll> ret(na+nb,LLONG_MAX);
	//FOR(i,1,na) a[i]+=a[i-1]; FOR(i,1,nb) b[i]+=b[i-1];
	REPE(i,na) REPE(j,nb) if(i+j!=0) {
		ll cur=(i==0?0:a[i-1])+(j==0?0:b[j-1]);
		if(cur<ret[i+j-1]) ret[i+j-1]=cur;
	}
	//for(int i=na+nb-1;i>=1;--i) ret[i]-=ret[i-1];
	return ret;
}
vector<ll> nodiscount;
void gather(int at) {
	nodiscount.PB(cost[at]);
	REPSZ(i,childs[at]) {
		int to=childs[at][i];
		gather(to);
	}
}
vector<ll> solve(int at) {
	vector<ll> ret;
	REPSZ(i,childs[at]) {
		int to=childs[at][i];
		vector<ll> cur=solve(to);
		ret=merge(ret,cur);
	}
	ret.insert(ret.begin(),0); REPSZ(i,ret) ret[i]+=cost[at]-discount[at];
	nodiscount.clear();
	gather(at);
	sort(nodiscount.begin(),nodiscount.end());
	assert(SZ(ret)==SZ(nodiscount));
	FORSZ(i,1,nodiscount) nodiscount[i]+=nodiscount[i-1];
	REPSZ(i,ret) if(nodiscount[i]<ret[i]) ret[i]=nodiscount[i];
	//printf("%d:",at+1); REPSZ(i,ret) printf(" %lld",ret[i]); puts("");
	return ret;
}

void run() {
	scanf("%d%d",&n,&have);
	REP(i,n) {
		scanf("%d%d",&cost[i],&discount[i]); if(i==0) par[i]=-1; else scanf("%d",&par[i]),--par[i];
		childs[i].clear(); if(par[i]!=-1) childs[par[i]].PB(i);
	}
	//n=MAXN; FOR(i,1,n) par[i]=(i-1)/2; REP(i,n) { cost[i]=rand()%1000+1,discount[i]=rand()%1000+1; if(discount[i]>=cost[i]) swap(discount[i],cost[i]); }

	vector<ll> res=solve(0);
	int ret=0; while(ret<SZ(res)&&have>=res[ret]) ++ret;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}