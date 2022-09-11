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

const int MAXN=1000000;

int n;
int a[MAXN];
int b[MAXN];

int c[2*MAXN],nc;

int par[2*MAXN],sz[2*MAXN]; bool cyc[2*MAXN],used[2*MAXN];
int uffind(int x) { if(par[x]==x) return x; return par[x]=uffind(par[x]); }

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&a[i],&b[i]);

	nc=0; REP(i,n) c[nc++]=a[i],c[nc++]=b[i]; sort(c,c+nc); nc=unique(c,c+nc)-c; REP(i,n) a[i]=lower_bound(c,c+nc,a[i])-c,b[i]=lower_bound(c,c+nc,b[i])-c;

	REP(i,nc) par[i]=i,sz[i]=i,cyc[i]=used[i]=false;
	REP(i,n) {
		int x=a[i],y=b[i];
		x=uffind(x),y=uffind(y);
		if(x==y) {
			if(cyc[x]) { printf("-1\n"); return; }
			cyc[x]=true;
		} else {
			if(sz[x]<sz[y]) swap(x,y);
			if(cyc[x]&&cyc[y]) { printf("-1\n"); return; }
			par[y]=x,sz[x]+=sz[y],cyc[x]|=cyc[y];
		}
	}
	//REP(i,nc) printf("%d: %d\n",c[i],uffind(i));
	for(int i=nc-1;i>=0;--i) {
		int x=uffind(i);
		if(cyc[x]||used[x]) { printf("%d\n",c[i]); return; }
		used[x]=true;
	}
	assert(false);
}

int main() {
	run();
	return 0;
}