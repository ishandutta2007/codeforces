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

const int MOD=998244353;
const int MAXN=100;
const int MAXSUM=5000;
const int MAXFAC=MAXSUM+MAXN-1;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int n,sum,lbound;

int inv[MAXFAC+1];
int fac[MAXFAC+1];
int ifac[MAXFAC+1];

int C(int a,int b) { if(b<0||b>a) return 0; return (ll)fac[a]*ifac[b]%MOD*ifac[a-b]%MOD; }
int distribute(int a,int b) { if(b==0) return a==0?1:0; return C(a+b-1,b-1); }


// remplayers

int solve() {
	inv[1]=1; FORE(i,2,MAXFAC) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,MAXFAC) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,MAXFAC) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

	int num=0;
	FORE(me,lbound,sum) {
		for(int neq=0;neq<=n-1&&(1+neq)*me<=sum;++neq) {
			int remscore=sum-(1+neq)*me,remplayers=n-1-neq;
			int ways=0;
			for(int nerr=0;nerr<=remplayers&&nerr*me<=remscore;++nerr) {
				int cur=(ll)C(remplayers,nerr)*distribute(remscore-nerr*me,remplayers)%MOD;
				if(nerr%2==0) inc(ways,cur); else dec(ways,cur);
			}
			ways=(ll)ways*C(n-1,neq)%MOD;
			//printf("me=%d neq=%d -> ways=%d\n",me,neq,ways);
			inc(num,(ll)ways*inv[1+neq]%MOD);
		}
	}
	int den=distribute(sum-lbound,n);
	return (ll)num*pw(den,MOD-2)%MOD;
}

void run() {
	scanf("%d%d%d",&n,&sum,&lbound);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}