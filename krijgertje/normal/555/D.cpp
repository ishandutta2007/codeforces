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

const int MAXN=200000;
typedef struct P { int x,idx; } P;
bool operator<(const P &a,const P &b) { return a.x<b.x; }

int n,nq;
P p[MAXN];
int mp[MAXN];

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&p[i].x),p[i].idx=i;
	sort(p,p+n);
	REP(i,n) mp[p[i].idx]=i;

	REP(qi,nq) {
		int idx,clen; scanf("%d%d",&idx,&clen); --idx; int ci=mp[idx];
		while(true) {
			// find max i such that cx<=p[i].x<=cx+clen
			int ni;
			{ int l=ci,h=n; while(l+1<h) { int m=l+(h-l)/2; if(p[m].x<=p[ci].x+clen) l=m; else h=m; } ni=l; }
			// find min i such that ncx-nclen<=p[i].x<ncx
			int nni;
			{ int l=-1,h=ni; while(l+1<h) { int m=l+(h-l)/2; if(p[m].x>=p[ni].x-clen+(p[ni].x-p[ci].x)) h=m; else l=m; } nni=h; }
			//printf("at %d (%d) -> %d -> %d\n",p[ci].x,clen,p[ni].x,p[nni].x);
			
			if(ci==ni&&ni==nni) { printf("%d\n",p[ci].idx+1); break; }
			if(ci==nni) { int times=clen/(2*(p[ni].x-p[ci].x)); clen-=2*times*(p[ni].x-p[ci].x); continue; }
			clen-=(p[ni].x-p[ci].x)+(p[ni].x-p[nni].x); ci=nni;
		}
	}
}

int main() {
	run();
	return 0;
}