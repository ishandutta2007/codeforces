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

const int MAXN=200000;

int n;
int a[MAXN];

int ret[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);

	REP(i,n) ret[i]=0;
	FOR(i,1,n) {
		int k=1;
		while(k<n) {
			int p=(i-1)/k;
			int nk=p==0?n:1+(i-1)/p;
			//printf("%d: k=%d, p=%d, nk=%d\n",i,k,p,nk); fflush(stdout);
			if(a[i]<a[p]) {
				++ret[k];
				if(nk<n) --ret[nk];
			}
			k=nk;
		}
	}
	FOR(i,1,n) ret[i]+=ret[i-1];
	FOR(i,1,n) { if(i!=1) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}