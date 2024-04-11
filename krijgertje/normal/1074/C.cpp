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

const int MAXN=300000;
struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };

int n;
int px[MAXN],py[MAXN];
int ans[MAXN+1];


vector<P> opt;


int calc(const P &a,const P &b,const P &c) {
	int lx=min(a.x,min(b.x,c.x));
	int hx=max(a.x,max(b.x,c.x));
	int ly=min(a.y,min(b.y,c.y));
	int hy=max(a.y,max(b.y,c.y));
	return 2*(hx-lx+hy-ly);
}

void solve() {
	int lx=px[0],hx=px[0],ly=py[0],hy=py[0]; REP(i,n) lx=min(lx,px[i]),hx=max(hx,px[i]),ly=min(ly,py[i]),hy=max(hy,py[i]);
	
	ans[3]=-1;
	FORE(i,4,n) ans[i]=2*(hx-lx+hy-ly);

	opt.clear(); REP(i,n) if(px[i]==lx||px[i]==hx||py[i]==ly||py[i]==hy) opt.PB(P(px[i],py[i]));
	REP(i,n) {
		REPSZ(j,opt) FORSZ(k,j+1,opt) {
			int cur=calc(P(px[i],py[i]),opt[j],opt[k]);
			ans[3]=max(ans[3],cur);
		}
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&px[i],&py[i]);
	solve();
	FORE(i,3,n) { if(i!=3) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}