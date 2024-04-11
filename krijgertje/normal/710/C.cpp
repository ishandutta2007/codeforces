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

const int MAXN=49;

int n;
int a[MAXN][MAXN];
bool have[MAXN*MAXN+1];

void run() {
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	int z=(n-1)/2;
	REP(i,n) a[z][i]=a[i][z]=1;
	if(z%2==1) REP(x,z-1) REP(y,n) a[x][y]=1;
	if(z%2==0) REP(x,z) REP(y,z) a[x][y]=1; REP(x,z-2) REP(y,z) a[x][z+y+1]=1;

	memset(have,false,sizeof(have)); have[0]=true;
	REP(x,n) REP(y,n) { while(have[a[x][y]]) a[x][y]+=2; have[a[x][y]]=true; }

	REP(x,n) { int sum=0; REP(y,n) sum+=a[x][y]; assert(sum%2==1); }
	REP(y,n) { int sum=0; REP(x,n) sum+=a[y][x]; assert(sum%2==1); }
	{ int sum=0; REP(z,n) sum+=a[z][z]; assert(sum%2==1); }
	{ int sum=0; REP(z,n) sum+=a[z][n-z-1]; assert(sum%2==1); }

	REP(x,n) { REP(y,n) { if(y!=0) printf(" "); printf("%d",a[x][y]); } puts(""); }
}

int main() {
	run();
	return 0;
}