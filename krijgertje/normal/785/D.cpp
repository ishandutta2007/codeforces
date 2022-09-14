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

const int MAXLEN=200000;
const int MOD=1000000007;

char s[MAXLEN+1]; int len;
int fac[MAXLEN+1];
int inv[MAXLEN+1];
int ifac[MAXLEN+1];

int comb(int n,int k) { return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD; }

void run() {
	fac[0]=1; FORE(i,1,MAXLEN) fac[i]=(ll)fac[i-1]*i%MOD;
	inv[1]=1; FORE(i,2,MAXLEN) inv[i]=(ll)(MOD-(MOD/i))*inv[MOD%i]%MOD;
	ifac[0]=1; FORE(i,1,MAXLEN) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

	scanf("%s",s); len=strlen(s);
	int nopen=0,nclose=0; REP(i,len) if(s[i]==')') ++nclose;
	int ret=0;
	REP(i,len) {
		if(s[i]=='(') {
			int maxhalf=min(nopen+1,nclose);
			//FORE(j,1,maxhalf) ret=(ret+(ll)comb(nopen,j-1)*comb(nclose,j))%MOD;
			//FORE(j,1,maxhalf) ret=(ret+(ll)comb(nopen,j-1)*comb(nclose,nclose-j))%MOD;
			if(nclose>=1) ret=(ret+comb(nopen+nclose,nclose-1))%MOD;
		}
		if(s[i]=='(') ++nopen; else --nclose;
	}
	printf("%d\n",ret);



}

int main() {
	run();
	return 0;
}