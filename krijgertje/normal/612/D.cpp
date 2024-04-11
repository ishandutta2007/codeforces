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

const int MAXN=1000000;

int n,want;
typedef struct E { int x,type; } E;
bool operator<(const E &a,const E &b) { if(a.x!=b.x) return a.x<b.x; return a.type>b.type; }


E e[2*MAXN]; int ne;

int ret[MAXN][2],nret;

void run() {
	scanf("%d%d",&n,&want);
	REP(i,n) { int l,r; scanf("%d%d",&l,&r); e[ne].x=2*l,e[ne].type=+1,++ne; e[ne].x=2*r+1,e[ne].type=-1,++ne; }
	sort(e,e+ne);

	int cur=0; nret=0;
	REP(i,ne) {
		cur+=e[i].type;
		//printf("%d: %d\n",e[i].x,cur);
		if(e[i].type==+1&&cur==want) ret[nret][0]=e[i].x;
		if(e[i].type==-1&&cur==want-1) ret[nret++][1]=e[i].x-1;
	}
	printf("%d\n",nret);
	REP(i,nret) printf("%d %d\n",ret[i][0]/2,ret[i][1]/2);
}

int main() {
	run();
	return 0;
}