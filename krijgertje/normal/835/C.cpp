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

const int MAXLIM=10;
const int MAXH=100;
const int MAXW=100;

int n,nq,lim;

int cnt[MAXLIM+1][MAXH][MAXW];
int sum[MAXLIM+1][MAXH+1][MAXW+1];

void run() {
	scanf("%d%d%d",&n,&nq,&lim);
	memset(cnt,0,sizeof(cnt));
	REP(i,n) { int x,y,s; scanf("%d%d%d",&x,&y,&s); --x,--y; REPE(t,lim) cnt[t][x][y]+=(s+t)%(lim+1); }
	memset(sum,0,sizeof(sum));
	REPE(t,lim) REP(x,MAXH) REP(y,MAXW) sum[t][x+1][y+1]=sum[t][x][y+1]+sum[t][x+1][y]-sum[t][x][y]+cnt[t][x][y];
	REP(i,nq) {
		int t,lx,ly,hx,hy; scanf("%d%d%d%d%d",&t,&lx,&ly,&hx,&hy); --lx,--ly,hx,hy,t%=lim+1;
		int ans=sum[t][hx][hy]-sum[t][lx][hy]-sum[t][hx][ly]+sum[t][lx][ly];
		printf("%d\n",ans);
	}
}

int main() {
	run();
	return 0;
}