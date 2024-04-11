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

const int MAXN=4000;
const int MOD=1000000007;

int n;
// [i][j] -> i items left, have j groups
int a[MAXN+1][MAXN+1]; //sum+trans+equiv
int b[MAXN+1][MAXN+1]; //sum+trans

void run() {
	scanf("%d",&n);

	REPE(j,n) a[0][j]=1;
	FORE(i,1,n) REPE(j,n-i) a[i][j]=((ll)j*a[i-1][j]+a[i-1][j+1])%MOD;
	REPE(j,n) b[0][j]=1;
	FORE(i,1,n) REPE(j,n-i) b[i][j]=((ll)j*b[i-1][j]+b[i-1][j+1]+b[i-1][j])%MOD;
	int ret=b[n][0]-a[n][0]; if(ret<0) ret+=MOD; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}