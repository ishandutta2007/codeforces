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

int have;
int a[3],b[3];
int sa,sb;

void run() {
	REP(i,3) scanf("%d",&a[i]); sa=0; REP(i,3) sa+=a[i];
	REP(i,3) scanf("%d",&b[i]); sb=0; REP(i,3) sb+=b[i];
	scanf("%d",&have);
	int need=(sa+4)/5+(sb+9)/10;
	printf("%s\n",have>=need?"YES":"NO");
}

int main() {
	run();
	return 0;
}