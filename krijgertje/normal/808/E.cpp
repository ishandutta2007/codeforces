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
const int MAXCAP=300000;
typedef struct R { int w,c; } R;
bool operator<(const R &a,const R &b) { return (ll)a.c*b.w>(ll)b.c*a.w; }


int n,cap;
R r[MAXN];

multiset<int> have[4];
multiset<int> avail[4];

ll getlargest(multiset<int> &a,int cnt) {
	if(SZ(a)<cnt) return INT_MIN;
	auto it=a.end(); ll ret=0; REP(i,cnt) { --it; ret+=*it; } return ret;
}
ll getsmallest(multiset<int> &a,int cnt) {
	if(SZ(a)<cnt) return INT_MAX;
	auto it=a.begin(); ll ret=0; REP(i,cnt) { ret+=*it; ++it; } return ret;
}
void removeone(multiset<int> &a,int val) {
	auto it=a.find(val); if(it==a.end()) printf("err (%d)\n",val); else a.erase(it);
}
void take(int cnt,int type) {
	REP(i,cnt) { ll cur=getlargest(avail[type],1); removeone(avail[type],cur); have[type].insert(cur); }
}
void remove(int cnt,int type) {
	REP(i,cnt) { ll cur=getsmallest(have[type],1); removeone(have[type],cur); avail[type].insert(cur); }
}

void run() {
	scanf("%d%d",&n,&cap); REP(i,n) scanf("%d%d",&r[i].w,&r[i].c); sort(r,r+n);

	int left=cap;
	REP(i,4) have[i].clear(),avail[i].clear();
	REP(i,n) avail[r[i].w].insert(r[i].c);

	ll ret=0;
	REP(i,n) {
		if(r[i].w>left) break;
		//printf("%d (%d,%d)\n",i,r[i].w,r[i].c);
		left-=r[i].w; ret+=r[i].c; have[r[i].w].insert(r[i].c); removeone(avail[r[i].w],r[i].c);
	}
	while(left>=1) {
		ll best=0; int besttype=-1;
		{ ll cur=getlargest(avail[1],1); if(cur>best) best=cur,besttype=0; }
		{ ll cur=getlargest(avail[2],1)-getsmallest(have[1],1); if(cur>best) best=cur,besttype=1; }
		{ ll cur=getlargest(avail[2],2)-getsmallest(have[3],1); if(cur>best) best=cur,besttype=2; }
		{ ll cur=getlargest(avail[3],1)-getsmallest(have[2],1); if(cur>best) best=cur,besttype=3; }
		{ ll cur=getlargest(avail[3],1)-getsmallest(have[1],2); if(cur>best) best=cur,besttype=4; }
		//printf("1besttype=%d best=%lld\n",besttype,best);
		if(besttype==-1) break;
		if(besttype==0) take(1,1);
		else if(besttype==1) take(1,2),remove(1,1);
		else if(besttype==2) take(2,2),remove(1,3);
		else if(besttype==3) take(1,3),remove(1,2);
		else if(besttype==4) take(1,3),remove(2,1);
		ret+=best; --left;
	}
	while(left>=2) {
		ll best=0; int besttype=-1;
		{ ll cur=getlargest(avail[2],1); if(cur>best) best=cur,besttype=0; }
		{ ll cur=getlargest(avail[3],1)-getsmallest(have[1],1); if(cur>best) best=cur,besttype=1; }
		{ ll cur=getlargest(avail[3],2)-getsmallest(have[2],2); if(cur>best) best=cur,besttype=2; }
		//printf("2besttype=%d best=%lld\n",besttype,best);
		if(besttype==-1) break;
		if(besttype==0) take(1,2);
		else if(besttype==1) take(1,3),remove(1,1);
		else if(besttype==2) take(2,3),remove(2,2);
		ret+=best; --left;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}