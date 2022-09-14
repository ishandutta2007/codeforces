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

int n;
char s[300][301];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%s",s[i]);
	char x=s[0][0],y=s[1][0];
	bool ok=x!=y;
	REP(i,n) REP(j,n) { char want=(i==j||i==n-j-1)?x:y; if(s[i][j]!=want) ok=false; }
	printf("%s\n",ok?"YES":"NO");
}

int main() {
	run();
	return 0;
}