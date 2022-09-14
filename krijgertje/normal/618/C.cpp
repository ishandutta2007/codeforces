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
const P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
const ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
ll dd(const P &a,const P &b) { int dx=a.x-b.x,dy=a.y-b.y; return (ll)dx*dx+(ll)dy*dy; }
ll area2(const P &a,const P &b,const P &c) { return abs((b-a)^(c-a)); }

int n;
P p[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	int a=0,b=-1,c=-1;
	REP(i,n) if(i!=a) if(b==-1||dd(p[a],p[i])<dd(p[a],p[b])) b=i;
	REP(i,n) if(i!=a&&i!=b&&area2(p[a],p[b],p[i])>0) if(c==-1||area2(p[a],p[b],p[i])<area2(p[a],p[b],p[c])) c=i;
	printf("%d %d %d\n",a+1,b+1,c+1);
}

int main() {
	run();
	return 0;
}