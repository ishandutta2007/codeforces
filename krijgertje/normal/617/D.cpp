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

typedef struct P { int x,y; } P;

P p[3];
int calc() {
	if(p[0].x==p[1].x&&p[0].x==p[2].x) return 1;
	if(p[0].y==p[1].y&&p[0].y==p[2].y) return 1;
	REP(i,3) REP(j,3) if(i!=j) if(p[i].x==p[j].x&&p[i].y<=p[j].y&&(p[3-i-j].y<=p[i].y||p[3-i-j].y>=p[j].y)) return 2;
	REP(i,3) REP(j,3) if(i!=j) if(p[i].y==p[j].y&&p[i].x<=p[j].x&&(p[3-i-j].x<=p[i].x||p[3-i-j].x>=p[j].x)) return 2;
	return 3;
}

void run() {
	REP(i,3) scanf("%d%d",&p[i].x,&p[i].y);
	printf("%d\n",calc());
}

int main() {
	run();
	return 0;
}