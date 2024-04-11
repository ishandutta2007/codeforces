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

const int MAXN=2000;
const int MOD=998244353;
const int INV2=(MOD+1)/2;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int inv(int x) { return pw(x,MOD-2); }

int nseg,need,len;

int C[2*MAXN+2+1][2*MAXN+2+1];
int fac[2*MAXN+2+1];
int ways[2*MAXN+1];

int solve() {
	REPE(i,2*MAXN+2) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD; }
	fac[0]=1; FORE(i,1,2*MAXN+2) fac[i]=(ll)fac[i-1]*i%MOD;
	REPE(i,MAXN) { ways[2*i]=fac[i]; REP(j,i) ways[2*i]=(ll)ways[2*i]*(2*j+1)%MOD; }

	int ret=0;
	int den=ways[2*nseg],invden=inv(den);
	REP(i,2*nseg-1) {
		int nleft=i+1,nright=2*nseg-1-i;
		FORE(j,need,nseg) {
			if(j>nleft||j>nright) break;
			if((nleft-j)%2==1||(nright-j)%2==1) continue;
			int num=(ll)C[nseg][j]*C[nleft][j]%MOD*C[nright][j]%MOD*fac[j]%MOD*fac[j]%MOD*ways[nleft-j]%MOD*ways[nright-j]%MOD*C[(nleft-j)/2+(nright-j)/2][(nleft-j)/2]%MOD;
			//printf("i=%d j=%d num=%d den=%d\n",i,j,num,den);
			ret=(ret+num)%MOD;
		}
	}
	int mlt=(ll)invden*inv(2*nseg+1)%MOD*len%MOD;
	return (ll)ret*mlt%MOD;
}

void run() {
	scanf("%d%d%d",&nseg,&need,&len);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}