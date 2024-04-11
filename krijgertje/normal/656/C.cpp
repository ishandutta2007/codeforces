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

const int MAXLEN=50;


char s[MAXLEN+1]; int len;

void run() {
	scanf("%s",s); len=strlen(s);
	int ret=0;
	REP(i,len) {
		char c=s[i];
		int x0='@'<c?1:0,x1='[' >c?1:0,x2='`'<c?1:0,x3='{'>c?1:0;
		int y0=x0&x1,y1=tolower(c)-'a'+1,y2=x2&x3;
		ret=ret+y0*y1-y1*y2;
		//printf("\t%d %d %d %d | %d %d %d | %d-%d\n",x0,x1,x2,x3,y0,y1,y2,y0*y1,y1*y2);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}