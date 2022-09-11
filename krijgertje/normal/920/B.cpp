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

const int MAXN=1000;

int n;
int l[MAXN],r[MAXN];

int q[MAXN],qhead,qtail;
int ret[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&l[i],&r[i]);
	qhead=qtail=0;
	int t=0,at=0; REP(i,n) ret[i]=0;
	while(qtail<qhead||at<n) {
		if(at<n&&l[at]==t) { q[qhead++]=at++; continue; }
		if(qtail<qhead&&r[q[qtail]]<t) { ++qtail; continue; }
		if(qtail<qhead) ret[q[qtail++]]=t;
		++t;
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}