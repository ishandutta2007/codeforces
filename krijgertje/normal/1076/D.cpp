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

const int MAXN=300000;
const int MAXM=300000;
struct E { int to,len,id; E() {} E(int to,int len,int id):to(to),len(len),id(id) {} };

int n,m,nkeep;
vector<E> e[MAXN];

ll dst[MAXN];
int use[MAXN];
priority_queue<pair<ll,int>> pq;
int o[MAXN]; int no;

int ret[MAXM],nret;

void solve() {
	no=0; pq=priority_queue<pair<ll,int>>(); REP(i,n) dst[i]=LLONG_MAX,use[i]=-1;
	dst[0]=0; pq.push(MP(-dst[0],0));
	while(!pq.empty()) {
		ll cost=-pq.top().first; int at=pq.top().second; pq.pop();
		if(cost>dst[at]) continue;
		o[no++]=at;
		REPSZ(i,e[at]) {
			int to=e[at][i].to; ll ncost=cost+e[at][i].len;
			if(ncost<dst[to]) use[to]=e[at][i].id,dst[to]=ncost,pq.push(MP(-dst[to],to));
		}
	}

	nret=0; REP(i,n) { int at=o[i]; if(use[at]!=-1&&nret<nkeep) ret[nret++]=use[at]; } sort(ret,ret+nret);
}

void run() {
	scanf("%d%d%d",&n,&m,&nkeep);
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; e[a].PB(E(b,c,i)); e[b].PB(E(a,c,i)); }
	solve();
	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}