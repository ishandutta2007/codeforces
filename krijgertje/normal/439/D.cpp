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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int a[100000],na;
int b[100000],nb;

void run() {
	scanf("%d%d",&na,&nb);
	REP(i,na) scanf("%d",&a[i]);
	REP(i,nb) scanf("%d",&b[i]);
	sort(a,a+na);
	sort(b,b+nb);

	int bound=0;
	int ai=0; // a[0..ai-1]<=bound, a[ai..na-1]>bound
	int bi=0; // b[0..bi-1]<=bound, b[bi..nb-1]>bound
	ll asum=0; // sum(bound-a[0..ai-1])
	ll bsum=0; REP(i,nb) bsum+=b[i]-bound; // sum(b[bi..nb-1]-bound)
	ll ret=asum+bsum;
//	printf("init: %lld / %lld\n",asum,bsum);
	while(ai<na||bi<nb) {
		int nbound=(ai<na&&(bi>=nb||a[ai]<=b[bi]))?a[ai]:b[bi];
		asum+=(ll)(nbound-bound)*ai;
		bsum-=(ll)(nbound-bound)*(nb-bi);
		while(ai<na&&a[ai]==nbound) ++ai;
		while(bi<nb&&b[bi]==nbound) ++bi;
		bound=nbound;
		if(asum+bsum<ret) ret=asum+bsum;
//		printf("%d: %lld / %lld\n",bound,asum,bsum);
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}