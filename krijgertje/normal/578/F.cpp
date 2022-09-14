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

const int MAXH=100;
const int MAXW=100;
const int MAXNN=(MAXH+1)*(MAXW+1);
const int MAXSTAR=200;
const int MAXN=MAXSTAR+1;

typedef struct UF {
	int par[MAXNN];
	void init(int n) { REP(i,n) par[i]=-1; }
	int find(int x) { if(par[x]<0) return x; return par[x]=find(par[x]); }
	bool unite(int x,int y) {
		x=find(x); y=find(y);
		if(x==y) return false;
		if(par[x]<par[y]) swap(x,y);
		par[x]+=par[y]; par[y]=x;
		return true;
	}
} UF;

UF uf;

int h,w,MOD;
char g[MAXH][MAXW];

int n;
int id[MAXNN];
int A[MAXN][MAXN];

inline void inc(int &a,const int &b) { if((a+=b)>=MOD) a-=MOD; }
inline void neg(int &a) { if(a!=0) a=MOD-a; }
inline void mult(int &a,const int &b) { a=(ll)a*b%MOD; }
inline void sub(int &a,const int &b) { if((a-=b)<0) a+=MOD; }
inline int mpow(int a,int n) { int ret=1; while(true) { if(n%2==1) mult(ret,a); n/=2; if(n==0) return ret; mult(a,a); } }
inline int inv(const int &a) { return mpow(a,MOD-2); }
int det() {
	//printf("det:\n"); REP(i,n) { REP(j,n) printf("%4d",A[i][j]); puts(""); }
	int ret=1,x=0,y=0;
	while(x<n&&y<n) {
		{ int xx=x; while(xx<n&&A[xx][y]==0) ++xx; if(xx>=n) return 0; if(xx!=x) { neg(ret); FOR(yy,y,n) swap(A[x][yy],A[xx][yy]); } }
		if(A[x][y]!=1) { int z=inv(A[x][y]); mult(ret,A[x][y]); FOR(yy,y,n) mult(A[x][yy],z);  }
		FOR(xx,x+1,n) { int times=A[xx][y]; FOR(yy,y,n) { int cur=A[x][yy]; mult(cur,times); sub(A[xx][yy],cur); } }
		++x,++y;
	}
	//printf("-> %d\n",ret);
	return ret;
}

int calc(int p) {
	n=0;
	REPE(x,h) REPE(y,w) if((x+y)%2==p&&uf.par[x*(w+1)+y]<0) id[x*(w+1)+y]=n++; else id[x*(w+1)+y]=-1;
	int nstar=0; REP(x,h) REP(y,w) if(g[x][y]=='*') ++nstar; if(n>nstar+1) return 0;
	REP(i,n) REP(j,n) A[i][j]=0;

	REP(x,h) REP(y,w) if(g[x][y]=='*') {
		int a,b;
		if((x+y)%2==p) {
			a=id[uf.find(x*(w+1)+y)],b=id[uf.find((x+1)*(w+1)+(y+1))];
		} else {
			a=id[uf.find(x*(w+1)+(y+1))],b=id[uf.find((x+1)*(w+1)+y)];
		}
		assert(a!=-1&&b!=-1);
		if(a==b) continue;
		inc(A[a][a],1); inc(A[b][b],1); sub(A[a][b],1); sub(A[b][a],1);
	}
	--n;
	return det();
}

void run() {
	scanf("%d%d%d",&h,&w,&MOD);
	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);

	bool ok=true;
	uf.init((h+1)*(w+1));
	REP(x,h) REP(y,w) {
		if(g[x][y]=='\\') if(!uf.unite(x*(w+1)+y,(x+1)*(w+1)+(y+1))) ok=false;
		if(g[x][y]=='/') if(!uf.unite(x*(w+1)+(y+1),(x+1)*(w+1)+y)) ok=false;
	}
	if(!ok) { printf("0\n"); return; }

	int ret=0;
	REP(p,2) inc(ret,calc(p));
	printf("%d\n",ret);


}

int main() {
	run();
	return 0;
}