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

const int MAXLEN=100;

int len,mod;

char s[MAXLEN+1];

bool inc() { for(int i=len-1;i>=0;--i) if(s[i]=='9') s[i]='0'; else { ++s[i]; return true; } return false; }
int calc() { int ret=0; REP(i,len) ret=(ret*10+(s[i]-'0'))%mod; return ret; }

void run() {
	scanf("%d%d",&len,&mod);

	REP(i,len) s[i]=i==0?'1':'0'; s[len]='\0';
	while(calc()!=0) if(!inc()) { printf("-1\n"); return; }
	printf("%s\n",s);
}

int main() {
	run();
	return 0;
}