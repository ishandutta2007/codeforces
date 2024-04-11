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

const int MAXN=300000;

int n,delay;
int cost[MAXN];

priority_queue<pair<int,int> > q;
int ret[MAXN]; ll retcost=0;

void run() {
	scanf("%d%d",&n,&delay); REP(i,n) scanf("%d",&cost[i]);

	for(int i=0;i<n||SZ(q)>0;++i) {
		if(i<n) q.push(MP(cost[i],i));
		if(i>=delay&&SZ(q)>0) { int cur=q.top().second; q.pop(); ret[cur]=i; retcost+=(ll)(i-cur)*cost[cur]; }
	}
	printf("%lld\n",retcost);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}