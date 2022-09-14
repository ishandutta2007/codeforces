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

const int MAXLEN=106;

char s[MAXLEN+1];

void run() {
	scanf("%s",s);
	int len=0,at,exp=0,incexp=0; bool afterdot=false;
	for(at=0;s[at]!='e';++at) {
		if(s[at]=='.') { afterdot=true; continue; }
		if(len!=0||s[at]!='0') s[len++]=s[at]; if(afterdot) --exp;
	}
	while(len>0&&s[len-1]=='0') --len,++exp;
	for(++at;s[at]!='\0';++at) incexp=10*incexp+s[at]-'0';
	exp+=incexp; if(len==0) exp=0;
	if(exp+len<=0) printf("0"); else REP(i,exp+len) printf("%c",i<len?s[i]:'0');
	if(exp<0) {	printf("."); REP(i,-exp) printf("%c",exp+len+i>=0?s[exp+len+i]:'0'); }
	puts("");
}

int main() {
	run();
	return 0;
}