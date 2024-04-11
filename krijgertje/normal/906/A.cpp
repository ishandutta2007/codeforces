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

int nq;
char s[MAXLEN+1];



void run() {
	scanf("%d",&nq);
	int can=(1<<26)-1,ret=0; bool know=false;
	REP(i,nq) {
		char kind; scanf(" %c",&kind);
		if(kind=='.'||kind=='!') {
			scanf("%s",s); int slen=strlen(s);
			int cur=0;
			REP(j,slen) cur|=1<<(s[j]-'a');
			if(kind=='.') { can&=~cur; } else { if(know) ++ret; can&=cur; }
		}
		if(kind=='?') {
			char c; scanf(" %c",&c);
			if(i!=nq-1) { int cur=1<<(c-'a'); if(know) ++ret; can&=~cur; }
		}
		if((can&(can-1))==0) know=true;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}