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
#include <chrono>
#include <chrono>
#include <random>
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

int n,tuse;
int t[MAXN];
ll ans[MAXN];

pair<int,int> o[MAXN];
queue<int> q;
set<int> standing;
set<int> waiting;

void solve() {
	REP(i,n) o[i]=MP(t[i],i);
	sort(o,o+n);
	q=queue<int>();
	standing.clear();
	waiting.clear();
	ll t=0;
	int ato=0;
	int rem=n;
	while(rem>0) {
		//printf("t=%lld rem=%d SZ(q)=%d\n",t,rem,SZ(q));
		if(!q.empty()) {
			t+=tuse;
			while(ato<n&&o[ato].first<t) {
				int cur=o[ato++].second;
				if(cur<*standing.begin()) q.push(cur),standing.insert(cur); else waiting.insert(cur);
			}
			int at=q.front(); q.pop(); standing.erase(at); ans[at]=t; --rem;
		} else {
			assert(ato<n);
			t=o[ato].first;
		}
		while(ato<n&&o[ato].first<=t) {
			int cur=o[ato++].second;
			waiting.insert(cur);
		}
		while(SZ(waiting)>=1&&(SZ(standing)==0||*waiting.begin()<*standing.begin())) {
			int cur=*waiting.begin(); waiting.erase(cur); q.push(cur); standing.insert(cur);
		}
	}
}

void run() {
	scanf("%d%d",&n,&tuse);
	REP(i,n) scanf("%d",&t[i]);
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}