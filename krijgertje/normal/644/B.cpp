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

int n,lim;
int t[MAXN],d[MAXN];
int q[MAXN],qhead,qtail;
ll ret[MAXN];

void run() {
	scanf("%d%d",&n,&lim);
	REP(i,n) scanf("%d%d",&t[i],&d[i]);

	int at=0; ll tstart=0; qhead=qtail=0;
	while(at<n||qtail<qhead) {
		if(qtail<qhead&&(at>=n||tstart+d[q[qtail]]<=t[at])) {
			ret[q[qtail]]=tstart+d[q[qtail]];
			tstart+=d[q[qtail++]];
		} else {
			if(qtail==qhead) tstart=t[at];
			if(qhead-qtail>=lim+1) ret[at++]=-1;
			else q[qhead++]=at++;
		}
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%I64d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}