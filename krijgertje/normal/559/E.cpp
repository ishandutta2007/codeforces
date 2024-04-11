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
typedef struct A { int x,d; } A;
bool operator<(const A &p,const A &q) { return p.x<q.x; }

int n;
A a[MAXN];

int mem[MAXN][MAXN+1][2];
int solve(int from,int lst,int up) {
	if(from>=n) return 0;
	int &ret=mem[from][lst+1][up];
	if(ret==-1) {
		ret=solve(from+1,lst,up);
		int phx=lst==-1?INT_MIN:a[lst].x+(up?a[lst].d:0);
		FOR(i,from,n) if(a[i].x>phx) {
			int lx=max(a[i].x-a[i].d,phx),hx=a[i].x,nlst=i,nup=0;
			FOR(j,from,i) if(a[j].x+a[j].d>hx) hx=a[j].x+a[j].d,nlst=j,nup=1;
			int cur=hx-lx+solve(i+1,nlst,nup);
			if(cur>ret) ret=cur;
		}
		FORE(i,from,from) if(a[i].x+a[i].d>phx) {
			int lx=max(a[i].x,phx),hx=a[i].x+a[i].d,nlst=i,nup=1;
			int cur=hx-lx+solve(i+1,nlst,nup);
			if(cur>ret) ret=cur;
		}
		//printf("%d %d (%d %d) = %d\n",from,phx,lst,up,ret);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&a[i].x,&a[i].d);
	sort(a,a+n);

	memset(mem,-1,sizeof(mem));
	int ret=solve(0,-1,0);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}