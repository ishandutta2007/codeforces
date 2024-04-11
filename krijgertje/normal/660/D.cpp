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

const int MAXN=2000;
const int MAXE=MAXN*(MAXN-1)/2;
typedef struct E { int dx,dy; ll c; } E;
bool operator<(const E &a,const E &b) { if(a.dx!=b.dx) return a.dx<b.dx; if(a.dy!=b.dy) return a.dy<b.dy; return a.c<b.c; }

int n;
int px[MAXN],py[MAXN];
E e[MAXE]; int ne;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&px[i],&py[i]);
	ne=0;
	REP(i,n) FOR(j,i+1,n) {
		int dx=px[j]-px[i],dy=py[j]-py[i]; int a=dy,b=-dx; 
		if(dx==0&&dy==0) continue;
		if(a<0||a==0&&b<0) a=-a,b=-b; int g=gcd(a,abs(b)); a/=g,b/=g;
		if(dx<0||dx==0&&dy<0) dx=-dx,dy=-dy;
		e[ne].dx=dx,e[ne].dy=dy,e[ne].c=(ll)a*px[i]+(ll)b*py[i],++ne;
	}
	sort(e,e+ne);
	ll ret=0;
	for(int at=0,to=at;at<ne;at=to) {
		while(to<ne&&e[at].dx==e[to].dx&&e[at].dy==e[to].dy) ++to;
		int cnt=to-at; ret+=(ll)cnt*(cnt-1)/2;
	}
	for(int at=0,to=at;at<ne;at=to) {
		while(to<ne&&e[at].dx==e[to].dx&&e[at].dy==e[to].dy&&e[at].c==e[to].c) ++to;
		int cnt=to-at; ret-=(ll)cnt*(cnt-1)/2;
	}
	ret/=2;
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}