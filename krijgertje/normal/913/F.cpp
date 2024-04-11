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

const int MOD=998244353;
const int MAXN=2000;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int inv(int x) { return pw(x,MOD-2); }

int n,a,b;

int pstronger[MAXN+1]; // pstronger[x] is probability that a stronger player wins x matches in a row
int pweaker[MAXN+1]; // pweaker[x] is probability that a weaker player wins x matches in a row

int p[MAXN+1][MAXN+1]; // p[i][j] = sum over all subsets of [0..i) of size j of the probability that that subset wins all its matches against players outside the subset

int pconn[MAXN+1]; // pconn[i] = probability that the results of a group of i players forms an scc
int E[MAXN+1]; // E[i] = expected games for i players

void run() {
	scanf("%d%d%d",&n,&a,&b);

	pstronger[0]=1; pstronger[1]=(ll)a*inv(b)%MOD; FORE(i,2,n) pstronger[i]=(ll)pstronger[i-1]*pstronger[1]%MOD;
	pweaker[0]=1; pweaker[1]=(1+MOD-pstronger[1])%MOD; FORE(i,2,n) pweaker[i]=(ll)pweaker[i-1]*pweaker[1]%MOD;

	memset(p,0,sizeof(p)); p[0][0]=1;
	REP(i,n) REPE(j,i) {
		p[i+1][j]=(p[i+1][j]+(ll)p[i][j]*pstronger[j])%MOD;
		p[i+1][j+1]=(p[i+1][j+1]+(ll)p[i][j]*pweaker[i-j])%MOD;
	}

	memset(E,0,sizeof(E)); pconn[0]=1;
	FORE(i,1,n) {
		pconn[i]=1; FORE(j,1,i-1) pconn[i]=(pconn[i]+MOD-(ll)pconn[j]*p[i][j]%MOD)%MOD;
		E[i]=(ll)pconn[i]*(i*(i-1)/2)%MOD;
		FORE(j,1,i-1)  {
			int cur=((ll)j*(j-1)/2+j*(i-j)+E[j]+E[i-j])%MOD;
			E[i]=(E[i]+(ll)p[i][j]*pconn[j]%MOD*cur)%MOD;
		}
		E[i]=(ll)E[i]*inv(1+MOD-pconn[i])%MOD;
	}

	printf("%d\n",E[n]);

	//printf("%d %d\n",pstronger[1],pweaker[1]);
	//printf("p:"); REPE(i,n) { if(i!=0) printf(" |"); REPE(j,i) printf(" %d",p[i][j]); } puts("");
	//printf("pconn:"); REPE(i,n) printf(" %d",pconn[i]); puts("");
	//printf("E:"); REPE(i,n) printf(" %d",E[i]); puts("");
}

int main() {
	run();
	return 0;
}