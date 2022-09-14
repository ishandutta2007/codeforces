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

const int MAXLEN=100000;

int n;
char pref[MAXLEN+1];
int pw;
char s[MAXLEN+1];

void run() {
	scanf("%d",&n); pref[0]='1',pref[1]='\0'; pw=0;

	REP(i,n) {
		scanf("%s",s); int len=strlen(s);
		if(len==1&&s[0]=='0') { printf("0\n"); return; }
		bool ok=true; REP(j,len) if(s[j]!=(j==0?'1':'0')) ok=false;
		if(ok) pw+=len-1; else strcpy(pref,s);
	}
	printf("%s",pref); REP(i,pw) printf("0"); puts("");
}

int main() {
	run();
	return 0;
}