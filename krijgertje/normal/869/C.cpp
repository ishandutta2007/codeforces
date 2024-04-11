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
const int MAXNUM=5000;

int C[MAXNUM+1][MAXNUM+1];
int fac[MAXNUM+1];

int a,b,c;

void run() {
	fac[0]=1; FORE(i,1,MAXNUM) fac[i]=(ll)fac[i-1]*i%MOD;
	REPE(i,MAXNUM) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD; }
	
	scanf("%d%d%d",&a,&b,&c);
	int ret=1;
	REP(i,3) {
		int x=i==0?a:i==1?b:c,y=i==0?b:i==1?c:a,mn=min(x,y);
		int cur=0;
		REPE(j,mn) {
			cur=(cur+(ll)C[x][j]*C[y][j]%MOD*fac[j])%MOD;
		}
		ret=(ll)ret*cur%MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}