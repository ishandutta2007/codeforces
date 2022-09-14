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

int n;
int x[MAXN],y[MAXN],r[MAXN];

void solve(int *z) {
	REP(i,n-1) printf("(");
	printf("%d",z[0]);
	int at=z[0];
	FOR(i,1,n) {
		int dz=z[i]-at; if(dz%2!=0) ++dz;
		printf("%c(%d*(((t-%d)+abs((t-%d)))-((t-%d)+abs((t-%d))))))",dz>=0?'+':'-',abs(dz/2),i-1,i-1,i,i);
		at+=dz;
	}
	puts("");
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d%d",&x[i],&y[i],&r[i]);
	solve(x);
	solve(y);
}

int main() {
	run();
	return 0;
}