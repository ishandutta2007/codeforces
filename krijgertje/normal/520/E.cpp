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

const int MOD=1000000007;
int n,nplus;
char s[100001];
int p[100000];
int digsum[100001];
int inv[100000];

int choose(int n,int k) { 
	int ret=1;
	REP(i,k) ret=(ll)ret*(n-i)%MOD*inv[i+1]%MOD;
	return ret;
}


// digit as pos i is used in 10^j: ??????i*****+????? + ?????i*****
// sum(k=0..nplus-1,choose(i,k)*choose(n-i-j-2,nplus-k-1))+(j==n-i-1?choose(i,nplus):0)

void run() {

	scanf("%d%d",&n,&nplus);
	scanf("%s",s);
	p[0]=1; FOR(i,1,n) p[i]=(ll)p[i-1]*10%MOD;
	digsum[0]=0; REP(i,n) digsum[i+1]=digsum[i]+(s[i]-'0');
	inv[1]=1; FOR(i,2,n) inv[i]=(ll)(MOD-(MOD/i))*inv[MOD%i]%MOD;

	// sum(i=0..n-1,sum(j=0..n-i-1,s[i]*p[j]*choose(i,nplus-1))))
	// sum(i=0..n-1,sum(j=0..n-i-2,s[i]*p[j]*choose(n-j-2,nplus-1)))
	// sum(j=0..n-2,choose(n-j-2,nplus-1)*p[j]*sum(i=0..n-j-2,s[i]))

	int ret=0,cur;

	cur=1;
	FOR(i,nplus,n) {
		ret=(ret+(ll)cur*(s[i]-'0')%MOD*p[n-i-1])%MOD;
		cur=(ll)cur*(i+1)%MOD*inv[i-nplus+1]%MOD;
	}

	if(nplus!=0) {
		cur=choose(n-2,nplus-1);
		REPE(j,n-2) {
			ret=(ret+(ll)cur*p[j]%MOD*digsum[n-j-1])%MOD;
			if(j!=n-2) cur=(ll)cur*(n-j-nplus-1)%MOD*inv[n-j-2]%MOD;
		}
	}
	printf("%d\n",ret);

}

int main() {
	run();
	return 0;
}