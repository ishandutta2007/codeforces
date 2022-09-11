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

const int MAXN=1000;

int n,a,b;
int adj[MAXN][MAXN];

bool solve() {
	memset(adj,0,sizeof(adj));
	if(a==1&&b==1) {
		if(n==1) return true;
		if(n<=3) return false;
		REP(i,n-1) adj[i][i+1]=adj[i+1][i]=1; return true;
	}
	if(a==1) {
		REP(i,n) REP(j,n) if(i!=j) adj[i][j]=1;
		REP(i,n-b) adj[i][i+1]=adj[i+1][i]=0; return true;
	}
	if(b==1) {
		REP(i,n-a) adj[i][i+1]=adj[i+1][i]=1; return true;
	}
	return false;
}

void run() {
	scanf("%d%d%d",&n,&a,&b);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n"); REP(i,n) { REP(j,n) printf("%d",adj[i][j]); puts(""); }
}

int main() {
	run();
	return 0;
}