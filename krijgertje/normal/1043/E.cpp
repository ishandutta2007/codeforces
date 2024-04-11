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
const int MAXM=300000;
struct P { int x,y,id; };
bool operator<(const P &a,const P &b) { return a.x-a.y<b.x-b.y; }

int n,m;
P p[MAXN];
int e[MAXM][2];
ll ans[MAXN];

ll xsum[MAXN+1];
ll ysum[MAXN+1];

void solve() {
	REP(i,n) ans[i]=0;
	REP(i,m) { int a=e[i][0],b=e[i][1]; ll cur=p[a]<p[b]?p[a].x+p[b].y:p[a].y+p[b].x; ans[a]-=cur,ans[b]-=cur; }
	
	sort(p,p+n);
	xsum[0]=0; REP(i,n) xsum[i+1]=xsum[i]+p[i].x;
	ysum[0]=0; REP(i,n) ysum[i+1]=ysum[i]+p[i].y;
	REP(i,n) {
		ans[p[i].id]+=xsum[i]+(ll)i*p[i].y;
		ans[p[i].id]+=(ll)(n-i-1)*p[i].x+ysum[n]-ysum[i+1];
	}
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y),p[i].id=i;
	REP(i,m) REP(j,2) scanf("%d",&e[i][j]),--e[i][j];
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}