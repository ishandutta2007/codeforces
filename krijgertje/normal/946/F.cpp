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

const int MAXLEN=100;
const int MAXFIB=100;
const int MOD=1000000007;

int slen,fibidx;
char s[MAXLEN+1]; 


int cnt[MAXFIB+1]; // cnt[x] = number of subsequences of F(x)

int prefcnt[MAXFIB+1][MAXLEN][MAXLEN]; // prefcnt[x][i] = number of subsequences of F(x) that start with s[i..j]
int suffcnt[MAXFIB+1][MAXLEN][MAXLEN]; // suffcnt[x][i] = number of subsequences of F(x) that end with s[i..j]
int eqcnt[MAXFIB+1][MAXLEN][MAXLEN]; // eqcnt[x][i] = number of subsequences of F(x) that equal s[i..j]
int scnt[MAXFIB+1]; // scnt[x] = sum over subsequences of F(x) of occurrences of s


void inc(int &a,ll b) { a=(a+b)%MOD; }
void run() {
	scanf("%d%d%s",&slen,&fibidx,&s);

	memset(prefcnt,0,sizeof(prefcnt));
	memset(suffcnt,0,sizeof(suffcnt));
	memset(eqcnt,0,sizeof(eqcnt));
	memset(scnt,0,sizeof(scnt));
	REP(x,2) {
		cnt[x]=2;
		REP(i,slen) if(s[i]=='0'+x) prefcnt[x][i][i]=suffcnt[x][i][i]=eqcnt[x][i][i]=1;
		if(slen==1&&s[0]=='0'+x) scnt[x]=1;
	}
	FORE(x,2,fibidx) {
		cnt[x]=(ll)cnt[x-1]*cnt[x-2]%MOD;
		REP(i,slen) FOR(j,i,slen) {
			inc(prefcnt[x][i][j],(ll)prefcnt[x-1][i][j]*cnt[x-2]);
			FOR(k,i,j) inc(prefcnt[x][i][j],(ll)eqcnt[x-1][i][k]*prefcnt[x-2][k+1][j]);
			inc(prefcnt[x][i][j],prefcnt[x-2][i][j]);

			inc(suffcnt[x][i][j],(ll)cnt[x-1]*suffcnt[x-2][i][j]);
			FOR(k,i,j) inc(suffcnt[x][i][j],(ll)suffcnt[x-1][i][k]*eqcnt[x-2][k+1][j]);
			inc(suffcnt[x][i][j],suffcnt[x-1][i][j]);

			inc(eqcnt[x][i][j],eqcnt[x-1][i][j]);
			FOR(k,i,j) inc(eqcnt[x][i][j],(ll)eqcnt[x-1][i][k]*eqcnt[x-2][k+1][j]);
			inc(eqcnt[x][i][j],eqcnt[x-2][i][j]);
		}
		inc(scnt[x],(ll)scnt[x-1]*cnt[x-2]);
		inc(scnt[x],(ll)cnt[x-1]*scnt[x-2]);
		REP(i,slen-1) inc(scnt[x],(ll)suffcnt[x-1][0][i]*prefcnt[x-2][i+1][slen-1]);

	}
	printf("%d\n",scnt[fibidx]);
}

int main() {
	run();
	return 0;
}