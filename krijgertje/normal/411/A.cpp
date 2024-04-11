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
char s[101];

bool ok() {
	if(n<5) return false;
	bool anyup=false; REP(i,n) if('A'<=s[i]&&s[i]<='Z') anyup=true; if(!anyup) return false;
	bool anylow=false; REP(i,n) if('a'<=s[i]&&s[i]<='z') anylow=true; if(!anylow) return false;
	bool anydig=false; REP(i,n) if('0'<=s[i]&&s[i]<='9') anydig=true; if(!anydig) return false;
	return true;
}

void run() {
	scanf("%s",s); n=strlen(s);
	printf("%s\n",ok()?"Correct":"Too weak");
}

int main() {
	run();
	return 0;
}