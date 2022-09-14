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

int n,m;
int a[100][100];

bool test(int h) {
	REP(i,h) REP(j,m) if(a[i][j]!=a[2*h-i-1][j]) return false;
	return true;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) REP(j,m) scanf("%d",&a[i][j]);
	while(n%2==0&&test(n/2)) n/=2;
	printf("%d\n",n);
}

int main() {
	run();
	return 0;
}