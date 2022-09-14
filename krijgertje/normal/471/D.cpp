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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int pat[200000],patlen;
int txt[200000],txtlen;
int nxt[200001]; // nxt[i]=max j<i such that first j characters of pat are same as last j characters from i

int calc() {
	nxt[0]=nxt[1]=0;
	FOR(i,1,patlen) {
		int at=nxt[i];
		while(at!=0&&pat[at]!=pat[i]) at=nxt[at];
		if(pat[at]==pat[i]) ++at;
		nxt[i+1]=at;
	}
	int ret=0,at=0;
	REP(i,txtlen) {
		while(at!=0&&pat[at]!=txt[i]) at=nxt[at];
		if(pat[at]==txt[i]) ++at;
		if(at==patlen) ++ret,at=nxt[at];
	}
	return ret;
}

int n,w;
int a[200000];
int b[200000];

void run() {
	scanf("%d%d",&n,&w); REP(i,n) scanf("%d",&a[i]); REP(i,w) scanf("%d",&b[i]);
	if(w==1) { printf("%d\n",n); return; }
	patlen=w-1; REP(i,patlen) pat[i]=b[i+1]-b[i];
	txtlen=n-1; REP(i,txtlen) txt[i]=a[i+1]-a[i];
	int ret=calc();
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}