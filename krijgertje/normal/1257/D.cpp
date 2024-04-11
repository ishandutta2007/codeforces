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

const int MAXMONSTER=200000;
const int MAXHERO=200000;
struct Hero { int have,lim; };
bool operator<(const Hero &a,const Hero &b) {
	if(a.have!=b.have) return a.have>b.have;
	return a.lim>b.lim;
}

int nmonster;
int need[MAXMONSTER];
int nhero;
Hero hero[MAXHERO];

int solve() {
	sort(hero,hero+nhero);
	{ int cnt=0; REP(i,nhero) if(cnt==0||hero[i].lim>hero[cnt-1].lim) hero[cnt++]=hero[i]; nhero=cnt; }
	int at=0,ret=0;
	while(at<nmonster) {
		int to=at;
		int idx=0,mx=0;
		while(idx<nhero&&hero[idx].have>=mx) {
			while(to<nmonster&&need[to]<=hero[idx].have&&to-at+1<=hero[idx].lim) mx=max(mx,need[to++]);
			if(to>=nmonster) break;
			if(need[to]>hero[idx].have) break;
			++idx;
		}
		if(to==at) return -1;
		at=to,++ret;
	}
	return ret;
}

void run() {
	scanf("%d",&nmonster);
	REP(i,nmonster) scanf("%d",&need[i]);
	scanf("%d",&nhero);
	REP(i,nhero) scanf("%d%d",&hero[i].have,&hero[i].lim);
	printf("%d\n",solve());
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}