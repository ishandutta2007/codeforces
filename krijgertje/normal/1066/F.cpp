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

const int MAXN=200000;
struct P { int x,y,lev; };
bool operator<(const P &a,const P &b) {
	if(a.lev!=b.lev) return a.lev<b.lev;
	if(a.x!=b.x) return a.x<b.x;
	if(a.y!=b.y) return a.y>b.y;
	return false;
}

int n;
P p[MAXN];

ll dst(const P &a,const P &b) { return abs(a.x-b.x)+abs(a.y-b.y); }

ll solve() {
	REP(i,n) p[i].lev=max(p[i].x,p[i].y); sort(p,p+n);
	sort(p,p+n);
	P a; a.x=a.y=a.lev=0; ll acost=0; P b; b.x=b.y=b.lev=0; ll bcost=0;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&p[l].lev==p[r].lev) ++r;
		//printf("%d: ",p[l].lev); FOR(i,l,r) printf(" (%d,%d)",p[i].x,p[i].y); puts("");

		P na=p[l],nb=p[r-1];
		ll nacost=min(acost+dst(a,nb),bcost+dst(b,nb))+dst(nb,na);
		ll nbcost=min(acost+dst(a,na),bcost+dst(b,na))+dst(na,nb);
		//printf("na=(%d,%d) nacost=%lld nb=(%d,%d) nbcost=%lld\n",na.x,na.y,nacost,nb.x,nb.y,nbcost);
		a=na,acost=nacost,b=nb,bcost=nbcost;
	}
	return min(acost,bcost);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}