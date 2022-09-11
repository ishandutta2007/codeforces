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

const int MAXLEN=100000;

char s[MAXLEN+1]; int slen;

int trans[11][10];
ll ways[11];
ll nways[11];


ll solve() {
	REP(k,11) REP(d,10) {
		if(d>=k) { trans[k][d]=-1; continue; }
		trans[k][d]=(k*(k-1)/2+d+10)%11;
	}
	//REP(k,11) { printf("trans%2d:",k); REP(d,10) printf(" %2d",trans[k][d]); puts(""); }

	ll ret=0;
	REP(k,11) ways[k]=0;
	REP(i,slen) {
		int d=s[i]-'0';
		REP(k,11) nways[k]=0;
		REP(k,11) if(trans[k][d]!=-1) nways[trans[k][d]]+=ways[k];
		REP(k,11) ways[k]=nways[k];
		if(d!=0) ++ways[d];
		REP(k,11) ret+=ways[k];
		//printf("%d: ",d); REP(k,11) printf(" %lld",ways[k]); puts("");
	}
	return ret;
}

void run() {
	scanf("%s",s); slen=strlen(s);
	printf("%lld\n",solve());
}


int main() {
	run();
	return 0;
}