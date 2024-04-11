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
typedef struct F { int num,den; F(int num,int den):num(num),den(den) {} F():num(0),den(1) {} } F;
bool operator<(const F &a,const F &b) { return (ll)a.num*b.den<(ll)b.num*a.den; }
bool operator==(const F &a,const F &b) { return (ll)a.num*b.den==(ll)b.num*a.den; }
const pair<F,F> IMP=MP(F(0,1),F(-1,1));

int n;
int lx,ly,hx,hy;

pair<F,int> e[2*MAXN]; int ne;

pair<F,F> calc1dim(int l,int h,int s,int v) {
	//printf("\tcalc1dim(%d,%d,%d,%d)\n",l,h,s,v);
	if(v==0) return l<s&&s<h?MP(F(0,1),F(INT_MAX,1)):IMP;
	if(v<0) return calc1dim(-h,-l,-s,-v);
	if(s>h) return IMP;
	return MP(s>=l?F(0,1):F(l-s,v),F(h-s,v));
}

pair<F,F> calc(int sx,int sy,int vx,int vy) {
	pair<F,F> x=calc1dim(lx,hx,sx,vx);
	pair<F,F> y=calc1dim(ly,hy,sy,vy);
	if(x==IMP||y==IMP) return IMP;
	return MP(max(x.first,y.first),min(x.second,y.second));
}

void run() {
	scanf("%d%d%d%d%d",&n,&lx,&ly,&hx,&hy);
	ne=0;
	REP(i,n) {
		int sx,sy,vx,vy; scanf("%d%d%d%d",&sx,&sy,&vx,&vy);
		pair<F,F> cur=calc(sx,sy,vx,vy);
		//printf("%d: %.9lf..%.9lf\n",i,1.0*cur.first.num/cur.first.den,1.0*cur.second.num/cur.second.den);
		if(cur.first<cur.second) { e[ne++]=MP(cur.first,+1), e[ne++]=MP(cur.second,-1); }
	}
	sort(e,e+ne);
	int cur=0; REP(i,ne) { cur+=e[i].second; if(cur==n) { printf("%.9lf\n",1.0*e[i].first.num/e[i].first.den); return; } }
	printf("-1\n");
}

int main() {
	run();
	return 0;
}