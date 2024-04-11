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

const int MAXN=200000;
const int MAXM=200000;

int n,m;
vector<pair<int,ll> > adj[MAXN];
ll citycost[MAXN];

ll dst[MAXN];
priority_queue<pair<ll,int> > pq;

void run() {
	scanf("%d%d",&n,&m); REP(i,m) { int a,b; ll c; scanf("%d%d%lld",&a,&b,&c); --a,--b; adj[a].PB(MP(b,c)); adj[b].PB(MP(a,c)); } REP(i,n) scanf("%lld",&citycost[i]);

	REP(i,n) dst[i]=citycost[i]; pq=priority_queue<pair<ll,int> >(); REP(i,n) pq.push(MP(-dst[i],i));
	while(!pq.empty()) {
		ll cost=-pq.top().first; int at=pq.top().second; pq.pop();
		if(cost>dst[at]) continue;
		//printf("%d: %lld\n",at,cost);
		REPSZ(i,adj[at]) {
			int to=adj[at][i].first; ll ncost=cost+2*adj[at][i].second;
			//printf(" -> %d = %lld\n",to,ncost);
			if(ncost<dst[to]) dst[to]=ncost,pq.push(MP(-dst[to],to));
		}
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",dst[i]); } puts("");
}

int main() {
	run();
	return 0;
}