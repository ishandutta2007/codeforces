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

const int MAXN=100000;
struct P { ll x,y; P() {} P(ll x,ll y):x(x),y(y) {} };
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
int side(const P &a,const P &b,const P &c) { ll res=(b-a)^(c-a); return res>0?+1:res<0?-1:0; }

int n;
P p[MAXN];

P h[MAXN]; int nh;

void calcupperhull() {
	nh=0;
	REP(i,n) {
		while(nh>=2&&side(h[nh-2],h[nh-1],p[i])>=0) --nh;
		h[nh++]=p[i];
	}
}


int solve() {
	sort(p,p+n);
	{ int nn=0; REP(i,n) { if(nn>0&&p[nn-1].x==p[i].x) --nn; p[nn++]=p[i]; } n=nn; }
	REP(i,n) p[i].y-=p[i].x*p[i].x;
	calcupperhull();
	return nh-1;
}


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%lld%lld",&p[i].x,&p[i].y);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}