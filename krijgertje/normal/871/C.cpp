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

const int MAXN=100000;
const int MOD=1000000007;

int n;
int x[MAXN],y[MAXN];

int xx[MAXN],nxx;
int yy[MAXN],nyy;

int par[2*MAXN],sz[2*MAXN]; bool istree[2*MAXN];
int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
void unite(int a,int b) {
	a=find(a),b=find(b);
	if(a==b) {
		istree[a]=false;
	} else {
		if(sz[a]<sz[b]) swap(a,b);
		par[b]=a,sz[a]+=sz[b]; if(!istree[b]) istree[a]=false;
	}
}

int p2[2*MAXN+1];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&x[i],&y[i]);

	nxx=0; REP(i,n) xx[nxx++]=x[i]; sort(xx,xx+nxx); nxx=unique(xx,xx+nxx)-xx; REP(i,n) x[i]=lower_bound(xx,xx+nxx,x[i])-xx;
	nyy=0; REP(i,n) yy[nyy++]=y[i]; sort(yy,yy+nyy); nyy=unique(yy,yy+nyy)-yy; REP(i,n) y[i]=lower_bound(yy,yy+nyy,y[i])-yy;

	REP(i,nxx+nyy) par[i]=i,sz[i]=1,istree[i]=true;
	REP(i,n) unite(x[i],nxx+y[i]);

	p2[0]=1; FORE(i,1,nxx+nyy) p2[i]=(ll)2*p2[i-1]%MOD;
	int ret=1;
	REP(a,nxx+nyy) if(par[a]==a) {
		if(istree[a]) {
			ret=(ll)ret*(p2[sz[a]]+MOD-1)%MOD;
		} else {
			ret=(ll)ret*p2[sz[a]]%MOD;
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}