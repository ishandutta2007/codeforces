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

const int MAXN=1000000;
const int MOD=1000000007;

int n;
int inv[MAXN+1];

void run() {
	inv[1]=1; FORE(i,2,MAXN) inv[i]=(MOD-(ll)(MOD/i)*inv[MOD%i]%MOD)%MOD;

	scanf("%d",&n);
	int ret=0,sub=0,p2=1,comb=2;
	REPE(i,2*n) {
		ret+=p2; if(ret>=MOD) ret-=MOD;
		p2+=p2; if(p2>=MOD) p2-=MOD;
		if(i>n) {
			//ret-=2*ways(#a<=i-n-1)
			//ret-=4*ways(#a<=i-n-2)+choose[i-1][i-n-1])
			//printf("2*(%d choose %d) = %d\n",i-1,i-n-1,comb);
			sub+=sub; if(sub>=MOD) sub-=MOD;
			sub+=comb; if(sub>=MOD) sub-=MOD;
			comb=(ll)comb*i%MOD*inv[i-n]%MOD;
			ret-=sub; if(ret<0) ret+=MOD;
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}