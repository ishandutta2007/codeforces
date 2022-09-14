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

char a[MAXLEN+1]; int alen;
char b[MAXLEN+1]; int blen;

int ldp[MAXLEN+1]; // ldp[i] is minimum j such that b[0..i) is a subsequence of a[0..j)
int rdp[MAXLEN+1]; // rdp[i] is maximum j such that b[i..blen) is a subsequence of a[j..alen)

int nxt[MAXLEN+1][26];
int prv[MAXLEN+1][26];

void run() {
	scanf("%s%s",a,b); alen=strlen(a); blen=strlen(b);

	REP(j,26) nxt[alen][j]=INT_MAX;
	for(int i=alen-1;i>=0;--i) REP(j,26) nxt[i][j]=a[i]-'a'==j?i:nxt[i+1][j];
	REP(j,26) prv[0][j]=INT_MIN;
	REP(i,alen) REP(j,26) prv[i+1][j]=a[i]-'a'==j?i:prv[i][j];

	ldp[0]=0; REP(i,blen) { int cur=nxt[ldp[i]][b[i]-'a']; ldp[i+1]=cur==INT_MAX?INT_MAX:cur+1; }
	rdp[blen]=alen; for(int i=blen-1;i>=0;--i) rdp[i]=prv[rdp[i+1]][b[i]-'a'];

	int ret=0,retl=0,retr=blen;
	int curl=0,curr=blen;
	while(curr>=0) {
		while(curl+1<curr&&ldp[curl+1]<=rdp[curr]) ++curl;
		while(curl-1>=0&&ldp[curl]>rdp[curr]) --curl;
		if(ldp[curl]>rdp[curr]) break;
		int cur=curl+blen-curr; if(cur>ret) ret=cur,retl=curl,retr=curr;
		--curr; if(curl>curr) curl=curr;
	}
	if(ret==0) printf("-\n"); else { REP(i,retl) printf("%c",b[i]); FOR(i,retr,blen) printf("%c",b[i]); puts(""); }
}

int main() {
	run();
	return 0;
}