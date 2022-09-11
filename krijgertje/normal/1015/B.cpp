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

const int MAXLEN=50;
const int MAXRET=10000;

int n;
char s[MAXLEN+1];
char t[MAXLEN+1];

int ret[MAXRET],nret;

void run() {
	scanf("%d",&n); scanf("%s%s",s,t);

	nret=0;
	REP(i,n) {
		int j=-1; FOR(jj,i,n) if(s[jj]==t[i]) { j=jj; break; } if(j==-1) { printf("-1\n"); return; }
		for(int k=j-1;k>=i;--k) ret[nret++]=k,swap(s[k],s[k+1]); assert(s[i]==t[i]);
	}
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}