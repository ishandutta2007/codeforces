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

const int MAXN=50;
const int MOD=1000000007;
void inc(int &a,ll b) { a=(a+b)%MOD; }

int n;
int d[MAXN];

int ways[MAXN+1][MAXN+1][MAXN+1]; // ways[a][b][c] = # ways to connect a remaining 1's and b remaining 2's on the previous level with c items on the current level

int sum2[MAXN+1];
int sum3[MAXN+1];
int mem[MAXN][MAXN+1]; // mem[a][b] = # ways to complete graph if previous level starts at a and current level starts at b

int go(int a,int b) {
	int &ret=mem[a][b];
	if(ret==-1) {
		ret=0;
		int n1=sum2[b]-sum2[a],n2=sum3[b]-sum3[a];
		if(b==n) {
			inc(ret,ways[n1][n2][0]);
		} else {
			FORE(c,b+1,n) {
				int x=c-b;
				inc(ret,(ll)ways[n1][n2][x]*go(b,c));
			}
		}
		//printf("go(%d,%d)=%d [n1=%d,n2=%d]\n",a,b,ret,n1,n2);
	}
	return ret;
}

int solve() {
	if(n==3&&d[0]==3) return 0;
	memset(ways,0,sizeof(ways));
	REPE(sumprev,n) REPE(b,sumprev/2) {
		int a=sumprev-2*b;
		REPE(c,n) {
			if(c>0) {
				if(a>=1) inc(ways[a][b][c],(ll)a*ways[a-1][b][c-1]);
				if(b>=1) inc(ways[a][b][c],(ll)b*ways[a+1][b-1][c-1]);
			} else if(a>0) {
				if(a>=2) inc(ways[a][b][c],(ll)(a-1)*ways[a-2][b][c]);
				if(b>=1) inc(ways[a][b][c],(ll)b*ways[a][b-1][c]);
			} else if(b>0) {
				if(b>=3) inc(ways[a][b][c],(ll)(b-1)*(b-2)/2%MOD*ways[a+2][b-3][c]);
			} else {
				ways[a][b][c]=1;
			}
		}
	}
	//REPE(a,n) REPE(b,n) REPE(c,n) if(ways[a][b][c]>0) printf("(%d,%d,%d)=%d\n",a,b,c,ways[a][b][c]);

	sum2[0]=0; REP(i,n) sum2[i+1]=sum2[i]+(d[i]==2?1:0);
	sum3[0]=0; REP(i,n) sum3[i+1]=sum3[i]+(d[i]==3?1:0);
	//REPE(i,n) printf("%d: %d %d\n",i,sum2[i],sum3[i]);
	memset(mem,-1,sizeof(mem));
	return go(1,1+d[0]);
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&d[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}