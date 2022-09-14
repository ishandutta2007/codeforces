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

char s[100001]; int slen;

void run() {
	scanf("%s",s); slen=strlen(s);
	int firstsmaller=-1,lastgreater=-1;
	REP(i,slen-1) if((s[i]-'0')%2==0) {
		if(firstsmaller==-1&&s[i]<s[slen-1]) firstsmaller=i;
		if(s[i]>s[slen-1]) lastgreater=i;
	}
	if(firstsmaller!=-1) swap(s[firstsmaller],s[slen-1]);
	else if(lastgreater!=-1) swap(s[lastgreater],s[slen-1]);
	else { printf("-1\n"); return; }
	printf("%s\n",s);
}

int main() {
	run();
	return 0;
}