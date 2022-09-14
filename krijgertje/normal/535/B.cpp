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

int n;
char s[20],slen;

void run() {
	scanf("%d",&n);
	slen=0; for(int x=n;x>0;x/=10) s[slen++]='0'+(x%10); reverse(s,s+slen); s[slen]='\0';
	int ret=1;
	FOR(i,1,slen) ret+=1<<i;
	REP(i,slen) if(s[i]!='4') ret+=1<<(slen-i-1);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}