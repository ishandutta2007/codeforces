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

const int MAXN=500;

int n,k;
int ret[MAXN][MAXN];

void run() {
	scanf("%d%d",&n,&k),--k;
	memset(ret,-1,sizeof(ret));
	REP(i,n) {
		REP(j,k) ret[i][j]=1+i*k+j;
		FOR(j,k,n) ret[i][j]=1+n*k+i*(n-k)+j-k;
	}
	int sum=0; REP(i,n) sum+=ret[i][k]; printf("%d\n",sum);
	REP(i,n) { REP(j,n) { if(j!=0) printf(" "); printf("%d",ret[i][j]); } puts(""); }
}

int main() {
	run();
	return 0;
}