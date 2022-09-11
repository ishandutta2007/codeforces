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
const int INV6=(MOD+1)/6;
ll m;

int sumsqpw[MAXN+1][4];



void run() {
	scanf("%lld",&m);
	int n=(int)floor(sqrt(1.0*m));
	REP(j,4) sumsqpw[0][j]=j==0?1:0;
	FORE(i,1,n) { int ii=(ll)i*i%MOD,cur=1; REP(j,4) { sumsqpw[i][j]=(sumsqpw[i-1][j]+cur)%MOD; cur=(ll)cur*ii%MOD; } }
	FORE(i,1,n) REP(j,4) sumsqpw[i][j]=((ll)2*sumsqpw[i][j]+MOD-sumsqpw[0][j])%MOD;
	//REPE(i,n) { printf("sumsqpw[%d]:",i); REP(j,4) printf(" %d",sumsqpw[i][j]); puts(""); }
	int ret=0;
	// a*v*v*v+b*v*v+c*v+d
	int a=2;
	int b=((-3*m-6)%MOD+MOD)%MOD;
	int c=(3*m+4)%MOD;
	int d=((m+2)%MOD)*((m+1)%MOD)%MOD*(m%MOD)%MOD;
	FORE(x,-n,+n) {
		// a*(x^6+3*x^4*y^2+3*x^2*y^4+y^6)+b*(x^4+2*x^2*y^2+y^4)+c*(x*x+y*y)+d=A*y^6+B*y^4+C*y^2+D
		int xx=(ll)x*x%MOD,xxxx=(ll)xx*xx%MOD,xxxxxx=(ll)xxxx*xx%MOD;
		int A=a;
		int B=((ll)3*a*xx+b)%MOD;
		int C=((ll)3*a*xxxx+(ll)2*b*xx+c)%MOD;
		int D=((ll)a*xxxxxx+(ll)b*xxxx+(ll)c*xx+d)%MOD;
		int ylim=(int)floor(sqrt(1.0*(m-(ll)x*x)));
		ret=(ret+(ll)A*sumsqpw[ylim][3]+(ll)B*sumsqpw[ylim][2]+(ll)C*sumsqpw[ylim][1]+(ll)D*sumsqpw[ylim][0])%MOD;
		/*FORE(y,-ylim,+ylim) {
			int yy=(ll)y*y%MOD;
			ll cur=(ll)A*yy*yy*yy+(ll)B*yy*yy+(ll)C*yy+D;
			//ll v=(ll)x*x+(ll)y*y;
			//ll cur=a*v*v*v+b*v*v+c*v+d;
			printf("(%d,%d): %lld\n",x,y,cur);
			ret=(ret+cur)%MOD;
		}*/
	}
	ret=(ll)ret*INV6%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}