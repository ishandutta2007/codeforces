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

int n;
char s[MAXLEN+1];

char stck[MAXLEN]; int nstck;

bool isopen(char c) { return c=='('||c=='['||c=='{'||c=='<'; }
bool ismatch(char a,char b) { return a=='('&&b==')'||a=='['&&b==']'||a=='<'&&b=='>'||a=='{'&&b=='}'; }

void run() {
	scanf("%s",s); n=strlen(s);

	nstck=0; int ret=0;
	REP(i,n) {
		if(isopen(s[i])) stck[nstck++]=s[i];
		else if(nstck==0) { printf("Impossible\n"); return; }
		else if(!ismatch(stck[--nstck],s[i])) ++ret;
	}
	if(nstck!=0) { printf("Impossible\n"); return; }
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}