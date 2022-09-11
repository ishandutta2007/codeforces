#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=700;

int n;
int val[MAXN];

bool adj[MAXN][MAXN];

bool lcan[MAXN][MAXN];
bool rcan[MAXN][MAXN];

bool solve() {
	REP(i,n) REP(j,n) adj[i][j]=gcd(val[i],val[j])!=1;

	REP(i,n) lcan[i][i]=rcan[i][i]=true;
	FORE(d,2,n) {
		REPE(i,n-d) {
			int j=i+d-1;
			lcan[i][j]=rcan[i][j]=false;
			FORE(k,i+1,j) if(adj[i][k]&&rcan[i+1][k]&&lcan[k][j]) { lcan[i][j]=true; break; }
			FORE(k,i,j-1) if(adj[j][k]&&rcan[i][k]&&lcan[k][j-1]) { rcan[i][j]=true; break; }
		}
	}
	REP(i,n) {
		bool lok=false,rok=false;
		if(i==0) lok=true; else FORE(j,0,i-1) if(adj[i][j]&&rcan[0][j]&&lcan[j][i-1]) { lok=true; break; }
		if(i==n-1) rok=true; else FORE(j,i+1,n-1) if(adj[i][j]&&rcan[i+1][j]&&lcan[j][n-1]) { rok=true; break; }
		if(lok&&rok) return true;
	}
	return false;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&val[i]);
	printf("%s\n",solve()?"Yes":"No");
}

int main() {
	run();
	return 0;
}