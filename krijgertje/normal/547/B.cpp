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

int n;
int x[MAXN];
int l[MAXN],r[MAXN];

int stck[MAXN],nstck;

int ret[MAXN+1];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&x[i]);

	nstck=0;
	REP(i,n) {
		while(nstck>0&&x[stck[nstck-1]]>=x[i]) --nstck;
		l[i]=nstck==0?0:stck[nstck-1]+1;
		stck[nstck++]=i;
	}
	nstck=0;
	for(int i=n-1;i>=0;--i) {
		while(nstck>0&&x[stck[nstck-1]]>=x[i]) --nstck;
		r[i]=nstck==0?n-1:stck[nstck-1]-1;
		stck[nstck++]=i;
	}

	memset(ret,0,sizeof(ret));
	REP(i,n) { int sz=r[i]-l[i]+1; if(x[i]>ret[sz]) ret[sz]=x[i]; }
	for(int i=n-1;i>=1;--i) if(ret[i+1]>=ret[i]) ret[i]=ret[i+1];

	FORE(i,1,n) { if(i!=1) printf(" "); printf("%d",ret[i]); } puts("");
}


int main() {
	run();
	return 0;
}