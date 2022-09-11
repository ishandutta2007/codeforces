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

const int MAXN=200000;

int n;
int a[MAXN];
int ret[MAXN],nret;

pair<int,int> o[MAXN];

void solve() {
	REP(i,n) o[i]=MP(a[i],i);
	sort(o,o+n);
	nret=0;
	ll sum=0; REP(i,n) sum+=a[i];
	REP(i,n) {
		int idx=o[i].second; ll rem=sum-o[i].first;
		int largest=i!=n-1?o[n-1].first:o[n-2].first;
		//printf("idx=%d rem=%lld largest=%d\n",idx,rem,largest);
		if(rem==(ll)2*largest) ret[nret++]=idx;
	}
	sort(ret,ret+nret);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}