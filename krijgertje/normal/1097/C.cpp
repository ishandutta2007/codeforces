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

const int MAXN=100000;
const int MAXSUMLEN=500000;

int n;
char s[MAXSUMLEN+1];
int offset[MAXN+1],len[MAXN];

int a[MAXN],na; // need closing
int b[MAXN],nb; // need opening
int nc; // balanced

int solve() {
	na=nb=nc=0;
	REP(i,n) {
		int bal=0,minbal=0;
		REP(j,len[i]) {
			if(s[offset[i]+j]=='(') ++bal; else --bal;
			minbal=min(minbal,bal);
		}
		int needopen=-minbal,needclose=bal-minbal;
		if(needopen==0&&needclose==0) ++nc; else if(needopen==0) a[na++]=needclose; else if(needclose==0) b[nb++]=needopen;
	}
	sort(a,a+na); sort(b,b+nb);
	int ret=nc/2,ai=0,bi=0;
	while(ai<na&&bi<nb) {
		if(a[ai]<b[bi]) ++ai; else if(a[ai]>b[bi]) ++bi; else ++ret,++ai,++bi;
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	offset[0]=0; REP(i,n) { scanf("%s",s+offset[i]); len[i]=strlen(s+offset[i]); offset[i+1]=offset[i]+len[i]; }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}