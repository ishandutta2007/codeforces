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

char s[1001]; int slen;
char t[1000001]; int tlen;

void run() {
	scanf("%s%s",s,t); slen=strlen(s); tlen=strlen(t);
	int a=0;
	REP(i,slen) {
		while(a<tlen&&s[i]!=t[a]) ++a;
		if(a>=tlen) break;
		++a;
	}
	int b=tlen-1;
	for(int i=slen-1;i>=0;--i) {
		while(b>=0&&s[i]!=t[b]) --b;
		if(b<0) break;
		--b;
	}
	if(a>b+1) { printf("0\n"); return; }
	printf("%d\n",b-a+2);
}

int main() {
	run();
	return 0;
}