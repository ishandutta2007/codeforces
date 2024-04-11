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

const int MAXK=100000;
const int MOD=1000000009;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int n,a,b,k;
char s[MAXK+1];

int solve() {
	int ainv=pw(a,MOD-2);
	int p=pw((ll)b*ainv%MOD,k);
	int mlt=pw(a,n);
	int den=(1+MOD-p)%MOD,iden=pw(den,MOD-2);
	//printf("p=%d den=%d iden=%d ainv=%d %lld\n",p,den,iden,ainv,(ll)b*ainv%MOD);

	int ret=0;
	REP(i,k) {
		int z=(n-i)/k;
		// s[i]*sum(j=0..z,a^(n-j*k-i)*b^(j*k+i))
		// s[i]*sum(j=0..z,((b/a)^k)^j)*b^i*a^(n-i) = with p=(b/a)^k = s[i]*sum(j=0..z,p^j)*b^i*a^(n-i) = s[i]*(1-p^(z+1))/(1-p)*b^i*a^(n-i)
		int cur=mlt;
		if(p!=1) {
			cur=(ll)cur*(1+MOD-pw(p,z+1))%MOD*iden%MOD;
		} else {
			cur=(ll)cur*(z+1)%MOD;
		}
		//printf("%d: z=%d cur=%d\n",i,z,cur);
		if(s[i]=='+') ret=(ret+cur)%MOD; else ret=(ret+MOD-cur)%MOD;
		mlt=(ll)mlt*ainv%MOD*b%MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d%d%d",&n,&a,&b,&k); scanf("%s",s);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}