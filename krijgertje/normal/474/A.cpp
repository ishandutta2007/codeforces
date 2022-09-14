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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

char keys[3][11]={"qwertyuiop","asdfghjkl;","zxcvbnm,./"};
char orig[256];
char s[101];

void run() {
	memset(orig,'?',sizeof(orig));
	char dir; scanf(" %c",&dir);
	REP(i,3) REP(j,10) orig[keys[i][j]]=dir=='R'?(j==0?'-':keys[i][j-1]):(j==9?'-':keys[i][j+1]);
	scanf("%s",s); int len=strlen(s);
	REP(i,len) printf("%c",orig[s[i]]); puts("");
}

int main() {
	run();
	return 0;
}