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
typedef struct L { int a,b,c; } L;
bool operator<(const L &p,const L &q) { if(p.a!=q.a) return p.a<q.a; if(p.b!=q.b) return p.b<q.b; return p.c<q.c; }

int n;
int x[MAXN],y[MAXN];

L l[MAXN*MAXN]; int nl;

int g[MAXN*MAXN]; int ng;

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&x[i],&y[i]);

	nl=0;
	REP(i,n) FOR(j,i+1,n) {
		int a=y[j]-y[i],b=x[i]-x[j],c=a*x[i]+b*y[i];
		if(a<0||a==0&&b<0) a=-a,b=-b,c=-c;
		int g=gcd(abs(a),gcd(abs(b),abs(c))); a/=g,b/=g,c/=g;
		l[nl].a=a,l[nl].b=b,l[nl].c=c,++nl;
	}
	sort(l,l+nl);
	//REP(i,nl) printf("%d %d %d\n",l[i].a,l[i].b,l[i].c);

	ll ret=(ll)n*(n-1)*(n-2)/6;
	int at=0; ng=0;
	while(at<nl) {
		int to=at; while(to<nl&&l[at].a==l[to].a&&l[at].b==l[to].b&&l[at].c==l[to].c) ++to;
		int cnt=to-at;
		g[ng++]=cnt;
		at=to;
	}
	sort(g,g+ng);
	//REP(i,ng) printf("%d ",g[i]); puts("");

	int cur=1;
	REP(i,ng) {
		while(cur*(cur-1)/2!=g[i]) ++cur;
		ret-=(ll)cur*(cur-1)*(cur-2)/6;
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}