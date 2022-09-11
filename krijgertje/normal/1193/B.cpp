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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;

int n,nfruit,mxday;
int par[MAXN];
int fday[MAXN],fval[MAXN];

vector<int> ch[MAXN];

map<int,ll> res[MAXN];


int merge(int a,int b) {
	if(SZ(res[b])>SZ(res[a])) swap(a,b);
	for(auto it=res[b].begin();it!=res[b].end();++it) res[a][it->first]+=it->second;
	res[b].clear();
	return a;
}
void update(int a,int key,int val) {
	res[a][key]+=val;
	auto it=res[a].upper_bound(key);
	int rem=val;
	while(it!=res[a].end()&&rem>0) {
		int cur=min((ll)rem,it->second);
		rem-=cur; auto pit=it++; if(pit->second==cur) res[a].erase(pit); else pit->second-=cur;
	}
}

int calc(int at) {
	int retidx=at; res[retidx].clear();
	REPSZ(i,ch[at]) {
		int to=ch[at][i];
		int subidx=calc(to);
		retidx=merge(retidx,subidx);
	}
	if(fday[at]!=-1) update(retidx,fday[at],fval[at]);
	return retidx;
}

ll solve() {
	REP(i,n) ch[i].clear();
	REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	int ansidx=calc(0);
	ll ret=0; for(auto it=res[ansidx].begin();it!=res[ansidx].end();++it) ret+=it->second; return ret;
}

void run() {
	scanf("%d%d%d",&n,&nfruit,&mxday);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	REP(i,n) fday[i]=-1,fval[i]=0; REP(i,nfruit) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a; assert(fday[a]==-1); fday[a]=b,fval[a]=c; }
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}