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

const int MAXN=1000;
typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator*(const P &a,const P &b) { return (ll)a.x*b.x+(ll)a.y*b.y; }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
double len(const P &a) { return sqrt(1.0*(a*a)); }

int n;
P p[MAXN+2];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y); p[n]=p[0],p[n+1]=p[1];
	double ret=1e200;
	REP(i,n) {
		P A=p[i],B=p[i+1],C=p[i+2],v=B-A,w=C-A;
		//double cosa=1.0*(v*w)/len(v)/len(w);
		//double cur=sin(acos(cosa))*len(v)/2;
		double sina=1.0*(w^v)/len(v)/len(w);
		double cur=sina*len(v)/2;
		if(cur<ret) ret=cur;
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}