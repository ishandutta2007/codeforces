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

int egcd(int a,int b,int &x,int &y) { // x*a+y*b=g
	if(b==0) { x=1,y=0; return a; }
	int g=egcd(b,a%b,y,x); y-=(a/b)*x; return g;
}

ll mlt(ll a,ll b,ll mod) {
	a=(a%mod+mod)%mod; b=(b%mod+mod)%mod;
	ll ret=0; while(a>0) { if(a&1) ret=(ret+b)%mod; a>>=1; b=(b+b)%mod; } return ret;
}

bool solve(int n,int m,int x,int y,int vx,int vy,int &px,int &py) {
	if(vx<0) { 
		if(!solve(n,m,n-x,y,-vx,vy,px,py)) return false;
		px=n-px; return true;
	}
	if(vy<0) {
		if(!solve(n,m,x,m-y,vx,-vy,px,py)) return false;
		py=m-py; return true;
	}
	if(vx==1&&vy==0) {
		if(y==0||y==m) { px=n,py=y; return true; }
		return false;
	}
	if(vx==0&&vy==1) {
		if(x==0||x==n) { px=x,py=m; return true; }
		return false;
	}
	if(vx==1&&vy==1) {
		int a,b,g=egcd(n,m,a,b); ll mod=(ll)n*m/g; // a*n+b*m=g
		// x+t=0 mod n, y+t=0 mod m -> t=-x=u mod n, t=-y=v mod m
		int u=n-x,v=m-y;
		if(u%g!=v%g) return false;
		// t=(u%g)+(u/g)*b*m+(v/g)*a*n
		ll t=(u%g)+mlt(u/g,(ll)b*m,mod)+mlt(v/g,(ll)a*n,mod);
		t=(t%mod+mod)%mod;
		//printf("x+t=%lld y+t=%lld\n",(x+t)%n,(y+t)%m);
		px=(x+t)%(2*n),py=(y+t)%(2*m);
		return true;
	}
	assert(false); return false;
}

void run() {
	int n,m,x,y,vx,vy;
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&vx,&vy);
	int px,py;
	if(!solve(n,m,x,y,vx,vy,px,py)) printf("-1\n"); else printf("%d %d\n",px,py);
}

int main() {
	run();
	return 0;
}