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

const int MAXLEN=200000;

char s[MAXLEN+1]; int slen;
char t[MAXLEN+1]; int tlen;
int p[MAXLEN];
bool avail[MAXLEN];

bool ok(int x) {
	REP(i,slen) avail[i]=true; REP(i,x) avail[p[i]]=false;
	int at=0;
	REP(i,slen) if(avail[i]) { if(at<tlen&&s[i]==t[at]) ++at; }
	return at>=tlen;
}

void run() {
	scanf("%s%s",s,t); slen=strlen(s),tlen=strlen(t);
	REP(i,slen) scanf("%d",&p[i]),--p[i];
	int l=0,h=slen;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(ok(m)) l=m; else h=m;
	}
	printf("%d\n",l);
}

int main() {
	run();
	return 0;
}