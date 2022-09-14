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

const int MAXN=1000000;

int n;
int p[MAXN];

bool done[MAXN];
int cur[MAXN],ncur;
int evn[MAXN+1];
int q[MAXN];


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&p[i]),--p[i];
	
	memset(q,-1,sizeof(q));
	memset(done,false,sizeof(done));
	memset(evn,-1,sizeof(evn));
	REP(i,n) if(!done[i]) {
		ncur=0;
		for(int at=i;!done[at];at=p[at]) { done[at]=true; cur[ncur++]=at; }
		if(ncur%2==1) {
			REP(j,ncur) q[cur[j]]=cur[(j+(ncur+1)/2)%ncur];
		} else if(evn[ncur]==-1) {
			evn[ncur]=i;
		} else {
			int a=i,b=evn[ncur]; evn[ncur]=-1;
			REP(j,ncur) q[a]=b,q[b]=p[a],a=p[a],b=p[b];
		}
	}
	REP(i,n) if(q[i]==-1) { printf("-1\n"); return; }
	REP(i,n) { if(i!=0) printf(" "); printf("%d",q[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}