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
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=300;

int n;
int ans[MAXN][MAXN];

void solve() {
	int at=n*n;
	REP(col,n) {
		if(col%2==0) {
			REP(row,n) ans[row][col]=at--;
		} else {
			for(int row=n-1;row>=0;--row) ans[row][col]=at--;
		}
	}
}

void run() {
	scanf("%d",&n);
	solve();
	REP(i,n) { REP(j,n) { if(j!=0) printf(" "); printf("%d",ans[i][j]); } puts(""); }
}

int main() {
	run();
	return 0;
}