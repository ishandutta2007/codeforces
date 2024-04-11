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

const int MAXN=100000;

int n; char s[MAXN+1],t[MAXN+1];

int mask[26];
int a[26],na;

char ret[26][2]; int nret;

void run() {
	scanf("%d%s%s",&n,s,t);

	REP(i,26) mask[i]=1<<i;
	REP(i,n) { int a=s[i]-'a',b=t[i]-'a'; mask[a]|=1<<b; mask[b]|=1<<a; }
	REP(k,26) REP(i,26) if(mask[i]&(1<<k)) mask[i]|=mask[k];
	na=0; REP(i,26) a[na++]=mask[i]; sort(a,a+na); na=unique(a,a+na)-a;
	nret=0; REP(i,na) { int cur=a[i]; int fst=-1; REP(j,26) if(cur&(1<<j)) if(fst==-1) fst=j; else ret[nret][0]='a'+fst,ret[nret][1]='a'+j,++nret;}
	printf("%d\n",nret); REP(i,nret) printf("%c %c\n",ret[i][0],ret[i][1]);
}

int main() {
	run();
	return 0;
}