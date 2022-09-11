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
#include <bitset>
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

const int MAXN=2000;

int n,sz;
char g[MAXN][MAXN+1];

int cnt[MAXN+1][MAXN+1];

void addrect(int lx,int ly,int hx,int hy ) { ++cnt[hx+1][hy+1],--cnt[lx][hy+1],--cnt[hx+1][ly],++cnt[lx][ly]; }

int solve() {
	REPE(x,n) REPE(y,n) cnt[x][y]=0;
	REP(x,n) {
		int l=INT_MAX,r=INT_MIN;
		REP(y,n) if(g[x][y]=='B') l=min(l,y),r=max(r,y);
		if(l>r) { addrect(0,0,n-1,n-1); continue; }
		int lx=max(0,x-sz+1),hx=x,ly=max(0,r-sz+1),hy=l; if(ly<=hy) addrect(lx,ly,hx,hy);
	}
	REP(y,n) {
		int l=INT_MAX,r=INT_MIN;
		REP(x,n) if(g[x][y]=='B') l=min(l,x),r=max(r,x);
		if(l>r) { addrect(0,0,n-1,n-1); continue; }
		int ly=max(0,y-sz+1),hy=y,lx=max(0,r-sz+1),hx=l; if(lx<=hx) addrect(lx,ly,hx,hy);
	}
	//REPE(x,n) { REPE(y,n) printf("%d ",cnt[x][y]); puts(""); } puts("");
	REP(x,n) REPE(y,n) cnt[x+1][y]+=cnt[x][y];
	//REPE(x,n) { REPE(y,n) printf("%d ",cnt[x][y]); puts(""); } puts("");
	REPE(x,n) REP(y,n) cnt[x][y+1]+=cnt[x][y];
	//REPE(x,n) { REPE(y,n) printf("%d ",cnt[x][y]); puts(""); } puts("");
	int ret=0; REP(x,n) REP(y,n) ret=max(ret,cnt[x][y]); return ret;
}

void run() {
	scanf("%d%d",&n,&sz);
	REP(x,n) scanf("%s",&g[x]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}