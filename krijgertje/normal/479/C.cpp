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

typedef struct X { int a,b; } X;
bool operator<(const X &p,const X &q) {
	if(p.a!=q.a) return p.a<q.a;
	return p.b<q.b;
}

int n;
X x[5000];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&x[i].a,&x[i].b);

	int last=0;
	sort(x,x+n);
	REP(i,n) {
		if(x[i].b>=last) last=x[i].b;
		else last=x[i].a;
	}
	printf("%d\n",last);
}

int main() {
	run();
	return 0;
}