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

const int MAXLEN=1000000;

char s[MAXLEN+1]; int len;

void run() {
	scanf("%s",s); len=strlen(s);

	int exp=0;
	REP(i,len) if(s[i]=='.') { FOR(j,i+1,len) s[j-1]=s[j],--exp; --len; }
	int a=0; while(a<len&&s[a]=='0') ++a;
	if(a>=len) { printf("0\n"); return; }
	int b=len; while(b>a&&s[b-1]=='0') --b;
	printf("%c",s[a]); exp+=len-a-1;
	if(b>a+1) { printf("."); FOR(i,a+1,b) printf("%c",s[i]); }
	if(exp!=0) printf("E%d",exp);
	puts("");
}

int main() {
	run();
	return 0;
}