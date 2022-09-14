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

int ndig,mod,MOD;

int pmod[1000];
ll pMOD[1000];
ll ways[1001][100][2];

void run() {
	scanf("%d%d%d",&ndig,&mod,&MOD);
	memset(ways,0,sizeof(ways));
	pmod[0]=1; REP(i,ndig-1) pmod[i+1]=10*pmod[i]%mod;
	pMOD[0]=1; REP(i,ndig-1) pMOD[i+1]=10*pMOD[i]%MOD;
	ways[0][0][0]=1;
	REP(i,ndig) REP(j,mod) REP(k,2) if(ways[i][j][k]!=0) {
		ways[i][j][k]%=MOD;
		REP(x,10) {
			if(i==ndig-1&&x==0) continue;
			int nj=(j+x*pmod[i])%mod;
			int nk=k==1||x!=0&&nj==0?1:0;
			ways[i+1][nj][nk]+=ways[i][j][k];
		}
	}
	ll ret=0;
	REP(j,mod) ret+=ways[ndig][j][1];
	ret%=MOD;
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}