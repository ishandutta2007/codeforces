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
typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y>b.y; }
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
int side(const P &a,const P &b,const P &c) { ll ret=(b-a)^(c-a); return ret<0?-1:ret>0?+1:0; }

void makehull(int &n,P p[MAXN+2]) {
	sort(p,p+n);
	int nh=0;
	REP(i,n) {
		while(nh>=2&&side(p[nh-2],p[nh-1],p[i])>=0) --nh;
		p[nh++]=p[i];
	}
	n=nh;
}

int n[2];
P s;
P p[2][MAXN+2];

void run() {
	REP(i,2) scanf("%d",&n[i]);
	scanf("%d%d",&s.x,&s.y);
	REP(i,2) REP(j,n[i]) scanf("%d%d",&p[i][j].x,&p[i][j].y);
	REP(i,2) { int hx=p[i][0].x; FOR(j,1,n[i]) if(p[i][j].x>hx) hx=p[i][j].x; p[i][n[i]].x=hx,p[i][n[i]].y=0,++n[i]; }
	REP(i,2) { int hy=p[i][0].y; FOR(j,1,n[i]) if(p[i][j].y>hy) hy=p[i][j].y; p[i][n[i]].x=0,p[i][n[i]].y=hy,++n[i]; }
	REP(i,2) makehull(n[i],p[i]);
	//REP(i,2) { printf("%s:",i==0?"A":"B"); REP(j,n[i]) printf(" (%d,%d)",p[i][j].x,p[i][j].y); puts(""); }
	int j=0;
	REP(i,n[0]) {
		while(j+2<n[1]&&p[1][j+1]<p[0][i]) ++j;
		//printf("%d %d\n",i,j);
		if(side(p[1][j],p[0][i],p[1][j+1])<=0) { printf("Max\n"); return; }
	}
	printf("Min\n");
}

int main() {
	run();
	return 0;
}