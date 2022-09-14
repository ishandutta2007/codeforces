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
const int MAXRET=2000000;

int n;
int a[MAXN];
int b[MAXN];
int binv[MAXN];
int p[MAXN];

int retcost;
int ret[MAXRET][2],nret;

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]),--a[i];
	REP(i,n) scanf("%d",&b[i]),--b[i];
	REP(i,n) binv[b[i]]=i;
	REP(i,n) p[i]=binv[a[i]];
	

	nret=retcost=0;
	REP(i,n) {
		int at=-1; REP(j,n) if(p[j]==i) { at=j; break; } assert(at!=-1);
		while(at>i) {
			//printf("%d (%d):",i,at); REP(j,n) printf(" %d",p[j]); puts("");
			int to=at-1; while(to>=i&&p[to]<at) --to; assert(to>=i);
			ret[nret][0]=at,ret[nret][1]=to,++nret,retcost+=at-to;
			swap(p[at],p[to]); swap(at,to);
		}
	}
	printf("%d\n",retcost);
	printf("%d\n",nret);
	REP(i,nret) printf("%d %d\n",ret[i][0]+1,ret[i][1]+1);
}

int main() {
	run();
	return 0;
}