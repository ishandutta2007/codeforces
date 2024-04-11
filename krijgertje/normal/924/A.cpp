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

const int MAXH=50;
const int MAXW=50;

int h,w;
char g[MAXH][MAXW+1];

int par[MAXH+MAXW],sz[MAXH+MAXW],nrows[MAXH+MAXW],ncols[MAXH+MAXW],ncells[MAXH+MAXW];


int find(int x) { if(par[x]==x) return x; return par[x]=find(par[x]); }
void unite(int a,int b) {
	a=find(a),b=find(b);
	if(a==b) { ++ncells[a]; return; }
	if(sz[b]>sz[a]) swap(a,b);
	par[b]=a,sz[a]+=sz[b],nrows[a]+=nrows[b],ncols[a]+=ncols[b],ncells[a]+=ncells[b],++ncells[a];
}

bool solve() {
	REP(i,h+w) par[i]=i,sz[i]=i,nrows[i]=i<h?1:0,ncols[i]=i>=h?1:0,ncells[i]=0;
	REP(x,h) REP(y,w) if(g[x][y]=='#') unite(x,h+y);

	//REP(i,h+w) if(find(i)==i) printf("%d: rows=%d cols=%d cells=%d\n",i,nrows[i],ncols[i],ncells[i]);

	REP(i,h+w) if(find(i)==i) if(nrows[i]*ncols[i]!=ncells[i]) return false;
	return true;
}

void run() {
	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]);
	printf("%s\n",solve()?"Yes":"No");
}

int main() {
	run();
	return 0;
}