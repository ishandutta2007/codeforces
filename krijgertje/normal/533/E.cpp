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

const int MAXN=100000;

int n;
char s[MAXN+1],t[MAXN+1];
// orig=A+x+B+y+C -> s=A+B+y+C,t=A+x+B+C or s=A+x+B+C,t=A+B+y+C
// so #(s[a..b]==B+y,t[a..b]==x+B)+#(s[a..b]==x+B,t[a..b]=B+y)

void run() {
	scanf("%d%s%s",&n,s,t);
	int a=0; while(s[a]==t[a]) ++a;
	int b=n-1; while(s[b]==t[b]) --b;
	bool ok1=true; FORE(c,a+1,b) if(s[c]!=t[c-1]) { ok1=false; break; }
	bool ok2=true; FORE(c,a+1,b) if(s[c-1]!=t[c]) { ok2=false; break; }
	int ret=(ok1?1:0)+(ok2?1:0);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}