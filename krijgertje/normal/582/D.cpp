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


const int MAXLEN=1000;
const int MAXDIG=3322;
const int MOD=1000000007;
const int INV2=(MOD+1)/2;

int p,want;
char s[MAXLEN+1];

int dig[MAXDIG]; int ndig;

// ways[i][j][c][eq] = #ways to choose first i digits of n and k, so that there are j carries, there needs to be carry from next digit (indicator c) and n is equal or lower to A (indicator eq)
int ways[MAXDIG+1][MAXDIG+1][2][2];

inline void inc(int &a,const int &b) { if((a+=b)>=MOD) a-=MOD; }
inline int mult(const int &a,const int &b) { return (ll)a*b%MOD; }
int calcmod(char *at) {
	ll ret=0;
	for(;*at!='\0';++at) {
		ret=ret*10+(*at-'0');
		*at='0'+(ret/p);
		ret%=p;
	}
	return ret;
}


void run() {
	scanf("%d%d%s",&p,&want,&s);
	//p=2; REP(i,MAXLEN) s[i]='9'; s[MAXLEN]='\0';

	ndig=0; char *at=s;
	while(true) {
		while(*at=='0') ++at;
		if(*at=='\0') break;
		dig[ndig++]=calcmod(at);
	}
	reverse(dig,dig+ndig);
	//REP(i,ndig) printf("%d ",dig[i]); puts("");

	if(want>ndig) { printf("0\n"); return; }

	REP(c,2) REP(eq,2) ways[0][0][c][eq]=(c==0&&eq==1)?1:0;
	REP(i,ndig) REPE(j,i) REP(c,2) REP(eq,2) if(ways[i][j][c][eq]!=0) REP(nc,2) {
		if(eq) {
			if(c==0) {
				inc(ways[i+1][j+nc][nc][1],mult(dig[i]-nc+1,ways[i][j][c][eq]));
				inc(ways[i+1][j+nc][nc][0],mult(mult(mult(dig[i]-nc,dig[i]+1-nc),INV2),ways[i][j][c][eq]));
			} else {
				inc(ways[i+1][j+nc][nc][1],mult(p-dig[i]+nc-1,ways[i][j][c][eq]));
				inc(ways[i+1][j+nc][nc][0],mult(mult(dig[i],p-dig[i]+nc),ways[i][j][c][eq]));
				inc(ways[i+1][j+nc][nc][0],mult(mult(mult(dig[i],dig[i]-1),INV2),ways[i][j][c][eq]));
			}
		} else {
			if(c==0) {
				// ki+nc<=ni
				inc(ways[i+1][j+nc][nc][0],mult(mult(mult(p-nc,p+1-nc),INV2),ways[i][j][c][eq]));
			} else {
				// ki+nc>ni
				inc(ways[i+1][j+nc][nc][0],mult(mult(mult(p+nc,p-1+nc),INV2),ways[i][j][c][eq]));
			}
		}

		/*REP(ni,p) REP(ki,p) {
			if(eq&&ni>dig[i]) continue;
			int neq=eq&&ni==dig[i]?1:0;
			if(c==0&&ki+nc>ni||c==1&&ki+nc<=ni) continue;
			inc(ways[i+1][j+nc][nc][neq],ways[i][j][c][eq]);
		}*/
	}
	//REPE(i,ndig) REPE(j,i) REP(c,2) REP(eq,2) if(ways[i][j][c][eq]!=0) printf("%d %d %d %d = %d\n",i,j,c,eq,ways[i][j][c][eq]);
	int ret=0;
	FORE(j,want,ndig) REP(eq,2) inc(ret,ways[ndig][j][0][eq]);
	printf("%d\n",ret);
	
}

int main() {
	run();
	return 0;
}