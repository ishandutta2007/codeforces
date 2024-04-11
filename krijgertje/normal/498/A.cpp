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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

typedef struct P { int x,y; } P;
typedef struct L { int a,b,c; } L;
int side(const P &p,const L &l) {
	ll val=(ll)p.x*l.a+(ll)p.y*l.b+l.c;
	return val<0?-1:val>0?+1:0;
}

P s,t;
int n;
L lines[300];


void run() {
	scanf("%d%d",&s.x,&s.y);
	scanf("%d%d",&t.x,&t.y);
	scanf("%d",&n); REP(i,n) scanf("%d%d%d",&lines[i].a,&lines[i].b,&lines[i].c);

	int ret=0;
	REP(i,n) {
		int sside=side(s,lines[i]),tside=side(t,lines[i]);
		if(sside!=tside) ++ret;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}