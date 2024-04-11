#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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

const int MAXN=30;

int mxdst,n;

bool truth[MAXN];

int query(int x) {
	printf("%d\n",x); fflush(stdout);
	int ret; scanf("%d",&ret); return ret;
}

void run() {
	scanf("%d%d",&mxdst,&n);

	REP(i,n) {
		int ans=query(1);
		if(ans==0) return;
		truth[i]=ans==+1;
	}
	int l=1,r=mxdst;
	for(int i=0;true;++i) {
		int m=l+(r-l)/2;
		int ans=query(m);
		if(ans==0) return;
		if(!truth[i%n]) ans=-ans;
		if(ans==-1) r=m-1; else l=m+1;
	}
}

int main() {
	run();
	return 0;
}