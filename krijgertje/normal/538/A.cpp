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

char s[101];
char t[]="CODEFORCES";
int slen,tlen;

void run() {
	scanf("%s",s); slen=strlen(s),tlen=strlen(t);
	int a=0; while(a<slen&&a<tlen&&s[a]==t[a]) ++a;
	int b=0; while(b<slen&&b<tlen&&s[slen-b-1]==t[tlen-b-1]) ++b;
	printf("%s\n",a+b>=tlen?"YES":"NO");
}

int main() {
	run();
	return 0;
}