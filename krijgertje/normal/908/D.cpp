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

const int MAXNEED=1000;
const int MOD=1000000007;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int need,na,nb;
int E[MAXNEED+1][MAXNEED+1]; // E[i][j] = expected #ab combinations if we need i and already have j A's before

// E[i][j]=pa*E[i][j+1]+pb*(j+E[i-j][j])
// E[i][i]=pa*(pa*(pa*E[i][i+3]+pb*(i+2)+pb*(i+1))+pb*i=sum(j=0..oo,pa^j*pb*(i+j))=i*pb*sum(j=0..oo,pa^j)+pb*sum(j=0..oo,pa^j*j)=i*pb/(1-pa)+pb*pa/(1-pa)^2

void run() {
	scanf("%d%d%d",&need,&na,&nb);
	int pa=(ll)na*pw(na+nb,MOD-2)%MOD;
	int pb=(ll)nb*pw(na+nb,MOD-2)%MOD;
	int x1=(ll)pb*pw((1+MOD-pa)%MOD,MOD-2)%MOD;
	int x2=(ll)pb*pa%MOD*pw((1+MOD-pa)%MOD,2*MOD-4)%MOD;
	//printf("pa=%d pb=%d x1=%d x2=%d\n",pa,pb,x1,x2);
	E[0][0]=0;
	FORE(i,1,need) {
		FORE(j,i,need) E[i][j]=((ll)j*x1+x2)%MOD;
		for(int j=i-1;j>=1;--j) { int ni=max(0,i-j),nj=j; E[i][j]=((ll)pa*E[i][j+1]+(ll)pb*(j+E[ni][nj]))%MOD; }
		E[i][0]=E[i][1];
		//REPE(j,need) printf("E[%d][%d]=%d\n",i,j,E[i][j]);
	}
	printf("%d\n",E[need][0]);
}

int main() {
	run();
	return 0;
}