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

const int MOD=1000000007;
const int MAXSTEP=10000;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

ll n; int nsteps;

vector<pair<ll,int>> fact;

vector<int> inv;
vector<vector<int>> prob;

int rec(int at,int prod) {
	if(at>=SZ(fact)) return prod;
	int ret=0,oprod=prod;
	REPE(i,fact[at].second) {
		ret=(ret+(ll)prob[fact[at].second][i]*rec(at+1,prod))%MOD;
		prod=(ll)prod*(fact[at].first%MOD)%MOD;
	}
	//printf("rec(%d,%d)=%d\n",at,oprod,ret);
	return ret;
}

int solve() {
	{ fact.clear(); ll x=n; for(ll i=2;i*i<=x;++i) if(x%i==0) { int cnt=0; while(x%i==0) ++cnt,x/=i; fact.PB(MP(i,cnt)); } if(x!=1) fact.PB(MP(x,1)); }
	int mxpw=1; REPSZ(i,fact) mxpw=max(mxpw,fact[i].second);
	prob=vector<vector<int>>(mxpw+1,vector<int>(mxpw+1)); REPE(i,mxpw) prob[i][i]=1;
	inv=vector<int>(mxpw+2); inv[1]=1; FORE(i,2,mxpw+1) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	REP(rep,nsteps) REPE(i,mxpw) REPE(j,mxpw) {
		int p=(ll)prob[i][j]*inv[j+1]%MOD; prob[i][j]=0; 
		REPE(k,j) inc(prob[i][k],p);
	}
	//REPE(i,mxpw) { printf("%d:",i); REPE(j,mxpw) printf(" %d",prob[i][j]); puts(""); }
	return rec(0,1);
}

void run() {
	scanf("%lld%d",&n,&nsteps);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}