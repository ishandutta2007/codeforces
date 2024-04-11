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

const int MAXN=200000;

char s[MAXN+1]; int n;

int head[MAXN],nxt[MAXN],nhead;
int zero[MAXN],nzero;
int one[MAXN],none;
int cur[MAXN],ncur;

void run() {
	scanf("%s",s); n=strlen(s);
	nhead=nzero=none=0;
	REP(i,n) {
		if(s[i]=='0') {
			if(none>0) { int x=one[--none]; nxt[x]=i; zero[nzero++]=i; }
			else { head[nhead++]=i; zero[nzero++]=i; }
		} else {
			if(nzero>0) { int x=zero[--nzero]; nxt[x]=i; one[none++]=i; }
			else { printf("-1\n"); return; }
		}
	}
	if(none>0) { printf("-1\n"); return; }
	while(nzero>0) { int x=zero[--nzero]; nxt[x]=-1; }
	printf("%d\n",nhead);
	REP(i,nhead) { ncur=0; for(int x=head[i];x!=-1;x=nxt[x]) cur[ncur++]=x; printf("%d",ncur); REP(j,ncur) printf(" %d",cur[j]+1); puts(""); }

}

int main() {
	run();
	return 0;
}