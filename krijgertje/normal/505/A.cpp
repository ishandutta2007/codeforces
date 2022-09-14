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

char s[12]; int n;

bool ok(int a,int b) {
	for(;a<=b;++a,--b) if(s[a]!=s[b]) return false;
	return true;
}

void run() {
	scanf("%s",s); n=strlen(s);
	for(int x=0;;++x) {
		if(2*x>=n) { for(int i=n;i>=x;--i) s[i+1]=s[i]; s[x]='a'; break; }
		if(2*x+1==n) { for(int i=n;i>=x+1;--i) s[i+1]=s[i]; s[x+1]=s[x]; break; }
		if(s[x]==s[n-x-1]) continue;
		if(ok(x+1,n-x-1)) { for(int i=n;i>=n-x;--i) s[i+1]=s[i]; s[n-x]=s[x]; break; }
		if(ok(x,n-x-2)) { for(int i=n;i>=x;--i) s[i+1]=s[i]; s[x]=s[n-x]; break; }
		printf("NA\n"); return;
	}
	printf("%s\n",s);
}

int main() {
	run();
	return 0;
}