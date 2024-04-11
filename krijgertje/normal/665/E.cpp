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

const int MAXN=1000000;

int n,want;
int x[MAXN];
int y[MAXN+1];

ll solve2(int l,int r,int L,int R,int idx) {
	if(l>=r||L>=R) return 0;
	if(idx<0) return (ll)(r-l)*(R-L);
	int m=l; while(m<r&&((y[m]>>idx)&1)==0) ++m;
	int M=L; while(M<R&&((y[M]>>idx)&1)==0) ++M;
	bool need=((want>>idx)&1)!=0;
	if(!need) {
		return solve2(l,m,L,M,idx-1)+solve2(m,r,M,R,idx-1)+(ll)(r-m)*(M-L)+(ll)(m-l)*(R-M);
	} else {
		return solve2(l,m,M,R,idx-1)+solve2(m,r,L,M,idx-1);
	}
}

ll solve(int l,int r,int idx) {
	if(l>=r) return 0;
	int m=l; while(m<r&&((y[m]>>idx)&1)==0) ++m;
	bool need=((want>>idx)&1)!=0;
	if(!need) {
		return solve(l,m,idx-1)+solve(m,r,idx-1)+(ll)(m-l)*(r-m);
	} else {
		return solve2(l,m,m,r,idx-1);
	}
}

void run() {
	scanf("%d%d",&n,&want);
	REP(i,n) scanf("%d",&x[i]);
	//srand(time(NULL)); n=MAXN; REP(i,n) x[i]=(rand()*1000+rand())%1000000+1; want=(rand()*1000+rand())%1000000+1;
	y[0]=0; REP(i,n) y[i+1]=y[i]^x[i]; sort(y,y+n+1);
	//REPE(i,n) printf("%x\n",y[i]);
	ll ret=solve(0,n+1,29);
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}