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

const int MAXN=100;
typedef struct R { int a,d,id; } R;
bool operator<(const R &p,const R &q) {
	int pp=p.d<0?-1:p.d>0?+1:0,qq=q.d<0?-1:q.d>0?+1:0; if(pp!=qq) return pp<qq;
	if(pp==-1) { if(p.a!=q.a) return p.a>q.a; return p.id<q.id; }
	if(pp==+1) { if(p.a!=q.a) return p.a<q.a; return p.id>q.id; }
	return false;
}

int n;
R r[MAXN];

int calc(R &p,R &q) {
	if(p.a!=q.a) return p.a>q.a?-1:+1;
	if(p.id!=q.id) return p.id<q.id?-1:+1;
	return 0;
}

bool change(R &p,R &q) {
	int x=calc(p,q);
	p.a+=p.d;
	int y=calc(p,q);
	p.a-=p.d;
	return x!=y;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&r[i].a,&r[i].d),r[i].id=i;
	sort(r,r+n);
	//REP(i,n) printf("%d: %d %d\n",r[i].id,r[i].a,r[i].d);
	int ret=0;
	REP(i,n) FOR(j,i+1,n) {
		if(change(r[i],r[j])) ++ret; //,printf("x %d %d\n",r[i].id,r[j].id);
		r[i].a+=r[i].d;
		if(change(r[j],r[i])) ++ret; //,printf("y %d %d\n",r[i].id,r[j].id);
		r[i].a-=r[i].d;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}