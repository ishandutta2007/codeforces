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
const int MAXM=100000;
struct E { int a,b,c; };

int n,m;
E e[MAXM];

map<int,int> best[MAXN];

int findbestbelow(int at,int lim) {
	auto it=best[at].lower_bound(lim);
	if(it==best[at].begin()) return 0;
	--it; return it->second;
}

void setbest(int at,int pos,int val) {
	auto it=best[at].lower_bound(pos);
	while(it!=best[at].end()&&it->second<=val) {
		auto nxt=it; ++nxt; best[at].erase(it); it=nxt;
	}
	if(it!=best[at].begin()) {
		auto prv=it; if(it->first!=pos) --prv;
		if(val<=prv->second) return;
	} 
	best[at][pos]=val;
}

void run() {
	scanf("%d%d",&n,&m); REP(i,m) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c),--e[i].a,--e[i].b;

	int ret=0;
	REP(i,m) {
		int cur=1+findbestbelow(e[i].a,e[i].c);
		ret=max(ret,cur);
		setbest(e[i].b,e[i].c,cur);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}