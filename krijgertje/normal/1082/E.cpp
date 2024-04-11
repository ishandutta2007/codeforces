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
#include <bitset>
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

const int MAXN=500000;

int n,want;
int a[MAXN];

int sum[MAXN+1];
pair<int,int> o[MAXN];

int cur[MAXN],ncur;

int calc() {
	//printf("calc:"); REP(i,ncur) printf(" %d",cur[i]); puts("");
	int lval=INT_MIN,ret=0;
	REP(i,ncur) {
		lval=max(lval,sum[cur[i]]-i);
		int rval=i+1-sum[cur[i]+1];
		int now=sum[n]+lval+rval;
		//printf("\t%d\n",now);
		ret=max(ret,now);
	}
	return ret;
}

int solve() {
	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+(a[i]==want?1:0);
	REP(i,n) o[i]=MP(a[i],i);
	sort(o,o+n);
	int ret=sum[n];
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&o[l].first==o[r].first) ++r;
		ncur=0; FOR(i,l,r) cur[ncur++]=o[i].second;
		int now=calc();
		ret=max(ret,now);
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&want);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}