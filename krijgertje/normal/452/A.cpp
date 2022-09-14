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

char ans[8][9]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int n;
char s[9];

void run() {
	scanf("%d%s",&n,s);
	REP(i,8) {
		bool ok=true;
		if(n!=strlen(ans[i])) ok=false;
		if(!ok) continue;
		REP(j,n) if(s[j]!='.'&&s[j]!=ans[i][j]) ok=false;
		if(!ok) continue;
		printf("%s\n",ans[i]);
		return;
	}
	printf("error\n");
}

int main() {
	run();
	return 0;
}