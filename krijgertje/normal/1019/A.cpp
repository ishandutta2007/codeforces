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

const int MAXN=3000;
const int MAXPARTY=3000;

int n,nparty;
int vote[MAXN],cost[MAXN];

pair<int,int> a[MAXN];
vector<pair<int,int>> b[MAXPARTY];

bool used[MAXN];

void run() {
	scanf("%d%d",&n,&nparty);
	REP(i,n) scanf("%d%d",&vote[i],&cost[i]),--vote[i];

	REP(i,n) a[i]=MP(cost[i],i),b[vote[i]].PB(MP(cost[i],i));
	sort(a,a+n); REP(i,nparty) sort(b[i].begin(),b[i].end());

	ll ret=LLONG_MAX;
	int nme=0; REP(j,n) if(vote[j]==0) ++nme;
	REPE(npay,n-nme) {
		REP(j,n) used[j]=vote[j]==0;
		int rem=npay; bool ok=true;
		FOR(k,1,nparty) {
			int need=max(0,SZ(b[k])-nme-npay+1);
			if(need>rem||need>SZ(b[k])) { ok=false; break; }
			rem-=need; REP(j,need) used[b[k][j].second]=true;
		}
		if(!ok) continue;
		REP(j,n) if(rem>0&&!used[a[j].second]) --rem,used[a[j].second]=true;
		assert(rem==0);
		ll cur=0; REP(j,n) if(used[j]&&vote[j]!=0) cur+=cost[j];
		//printf("%d: %lld\n",npay,cur);
		ret=min(ret,cur);
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}