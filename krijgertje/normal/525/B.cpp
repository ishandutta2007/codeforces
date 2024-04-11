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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

char s[200001]; int slen;

int nchange;
bool rev[200001];

void run() {
	scanf("%s",s); slen=strlen(s);
	REPE(i,slen) rev[i]=false;
	scanf("%d",&nchange);
	REP(i,nchange) {
		int x; scanf("%d",&x); --x;
		rev[x]=!rev[x];
		rev[slen-x]=!rev[slen-x];
	}
	FORE(i,1,slen) if(rev[i-1]) rev[i]=!rev[i];
	//REPE(i,slen) printf("%c",rev[i]?'R':'.'); puts("");
	REP(i,slen) printf("%c",!rev[i]?s[i]:s[slen-i-1]); puts("");
}

int main() {
	run();
	return 0;
}