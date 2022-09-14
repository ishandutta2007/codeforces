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

char bus[6][30]={	"+------------------------+",
					"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
					"|#.#.#.#.#.#.#.#.#.#.#.|.|",
					"|#.......................|",
					"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
					"+------------------------+"};

void run() {
	int n; scanf("%d",&n);
	int left=n; for(int j=0;left>0;++j) REP(i,6) if(bus[i][j]=='#'&&left>0) { bus[i][j]='O'; --left; }
	REP(i,6) printf("%s\n",bus[i]);
}

int main() {
	run();
	return 0;
}