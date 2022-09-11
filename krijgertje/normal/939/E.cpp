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

const int MAXN=500000;

int n,nq;

int a[MAXN];
ll sum[MAXN+1];

void run() {
	n=0; scanf("%d",&nq);
	sum[0]=0;
	int nsmall=0;
	REP(i,nq) {
		int kind; scanf("%d",&kind);
		if(kind==1) {
			int x; scanf("%d",&x); a[n]=x; sum[n+1]=sum[n]+a[n]; ++n;
		}
		if(kind==2) {
			while(nsmall+1<=n-1&&1.0*(sum[nsmall+1]+a[n-1])/(nsmall+2)<=1.0*(sum[nsmall]+a[n-1])/(nsmall+1)) ++nsmall;
			//printf("a:"); REP(j,n) printf(" %d",a[j]); printf(" (%d)\n",nsmall);
			printf("%.15lf\n",a[n-1]-1.0*(sum[nsmall]+a[n-1])/(nsmall+1));
		}
	}
}

int main() {
	run();
	return 0;
}