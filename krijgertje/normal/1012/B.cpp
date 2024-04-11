#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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

const int MAXN=200000;
const int MAXH=200000;
const int MAXW=200000;

int h,w,n;
int x[MAXN],y[MAXN];

int par[MAXH+MAXW],sz[MAXH+MAXW];
int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
bool unite(int a,int b) { a=find(a),b=find(b); if(a==b) return false; if(sz[a]<sz[b]) swap(a,b); par[b]=a,sz[a]+=sz[b]; return true; }

void run() {
	scanf("%d%d%d",&h,&w,&n);
	REP(i,n) scanf("%d%d",&x[i],&y[i]),--x[i],--y[i];

	REP(i,h+w) par[i]=i,sz[i]=1;
	REP(i,n) unite(x[i],h+y[i]);

	int ncomp=0;
	REP(i,h+w) if(par[i]==i) ++ncomp;
	int ret=ncomp-1;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}