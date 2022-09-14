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

int w,h;

char a[100][100];
char b[100][100];
char c[100][100];
char d[200][200];


void run() {
	scanf("%d%d",&w,&h);
	REP(x,h) REP(y,w) scanf(" %c",&a[x][y]);
	REP(x,h) REP(y,w) b[y][h-x-1]=a[x][y]; swap(w,h);
	REP(x,h) REP(y,w) c[x][w-y-1]=b[x][y];
	REP(x,h) REP(y,w) d[2*x+0][2*y+0]=d[2*x+0][2*y+1]=d[2*x+1][2*y+0]=d[2*x+1][2*y+1]=c[x][y]; h*=2; w*=2;
	REP(x,h) { REP(y,w) printf("%c",d[x][y]); puts(""); }

}

int main() {
	run();
	return 0;
}