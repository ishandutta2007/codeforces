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

int n,m;
int skill[MAXN];
vector<int> adj[MAXN];

int cnt[MAXN]; // how many in quarell that have less than current skill
pair<int,int> o[MAXN];
int ans[MAXN];

void run() {
	scanf("%d%d",&n,&m); REP(i,n) scanf("%d",&skill[i]); REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }

	REP(i,n) cnt[i]=SZ(adj[i]);
	REP(i,n) o[i]=MP(-skill[i],i); sort(o,o+n);
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&o[l].first==o[r].first) ++r;
		FOR(i,l,r) {
			int at=o[i].second;
			REPSZ(j,adj[at]) { int to=adj[at][j]; --cnt[to]; }
		}
		FOR(i,l,r) {
			int at=o[i].second;
			ans[at]=n-r-cnt[at];
		}
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}