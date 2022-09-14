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
const int MAXX=19;
const int MAXR=1000000;
const int MOD=1000000007;

int nq;
int mndv[MAXN+1];
int F[MAXR+1][MAXX+1];

void precalc() {
	REPE(i,MAXN) mndv[i]=-1;
	FORE(i,2,MAXN) if(mndv[i]==-1) { mndv[i]=i; if((ll)i*i<=MAXN) for(int j=i*i;j<=MAXN;j+=i) if(mndv[j]==-1) mndv[j]=i; }
	REPE(j,MAXX) F[0][j]=j==0?1:2;
	FORE(i,1,MAXR) { int sum=0; REPE(j,MAXX) { if((sum+=F[i-1][j])>=MOD) sum-=MOD; F[i][j]=sum; } }
}

void run() {
	precalc();
	scanf("%d",&nq);
	REP(i,nq) {
		int r,n; scanf("%d%d",&r,&n);
		int ret=1;
		while(n!=1) {
			int p=mndv[n],x=0; while(mndv[n]==p) n/=p,++x;
			ret=(ll)ret*F[r][x]%MOD;
		}
		printf("%d\n",ret);
	}
}

int main() {
	run();
	return 0;
}