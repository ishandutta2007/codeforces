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

const int MAXLEN=1001;
const int MOD=1000000007;

char s[MAXLEN+1]; int slen;
int want;

int f[MAXLEN+1];
int C[MAXLEN+1][MAXLEN+1];

int calc(int nbits) {
	int have=0,ret=0;
	REP(i,slen) {
		if(s[i]=='0') continue;
		int pos=slen-i-1,rem=nbits-have;
		if(rem>=0&&rem<=pos) ret=(ret+C[pos][rem])%MOD;
		++have;
	}
	if(have==nbits) ret=(ret+1)%MOD;
	if(nbits==1) ret=(ret+MOD-1)%MOD;
	return ret;
}

int solve() {
	if(want==0) return 1;
	f[1]=0;
	FORE(i,2,MAXLEN) {
		int cnt=0; for(int x=i;x>0;x/=2) cnt+=x%2; f[i]=1+f[cnt];
	}
	REPE(i,MAXLEN) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD; }
	int ret=0;
	FORE(i,1,MAXLEN) if(f[i]==want-1) {
		ret=(ret+calc(i))%MOD;
	}
	return ret;
}

void run() {
	scanf("%s%d",s,&want); slen=strlen(s);
	printf("%d\n",solve());



}

int main() {
	run();
	return 0;
}