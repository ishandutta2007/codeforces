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

const int MAXN=5000;

int n;
int a[MAXN];


int cur[MAXN];
int b[MAXN][MAXN]; // b[i][j] is f(a[i..j])
int c[MAXN][MAXN]; // c[i][j] is max(b[ii][jj],i<=ii<=jj<=j)

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	REP(i,n) cur[i]=a[i];
	FORE(len,1,n) {
		//printf("cur:"); REPE(i,n-len) printf(" %d",cur[i]); puts("");
		REPE(i,n-len) b[i][i+len-1]=cur[i];
		if(len==n) break;
		REP(i,n-len) cur[i]^=cur[i+1]; cur[n-len]=0;
	}
	REP(i,n) c[i][i]=b[i][i];
	FORE(len,2,n) REPE(i,n-len) c[i][i+len-1]=max(b[i][i+len-1],max(c[i][i+len-2],c[i+1][i+len-1]));

	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		int l,r; scanf("%d%d",&l,&r); --l,--r;
		printf("%d\n",c[l][r]);
	}



}

int main() {
	run();
	return 0;
}