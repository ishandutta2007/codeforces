#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXN=200000;

int n;
char s[MAXN+1];
char ret[MAXN+1];

void solve() {
	int nret=0;
	REP(i,n-1) if(s[i]>s[i+1]) {
		REP(j,i) ret[nret++]=s[j]; FOR(j,i+1,n) ret[nret++]=s[j]; ret[nret]='\0'; return;
	}
	{
		REP(j,n-1) ret[nret++]=s[j]; ret[nret]='\0'; return;
	}
}

void run() {
	scanf("%d",&n); scanf("%s",s);
	solve();
	printf("%s\n",ret);
}

int main() {
	run();
	return 0;
}