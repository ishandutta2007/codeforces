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

const int MAXN=100000;

int n,dmx,each;
int a[MAXN];
int b[MAXN];
int bsum[MAXN+1];

int solve(int x) {
	//printf("%d:",x); REP(i,n) printf(" %d",b[i]); puts("");
	bsum[0]=0; REP(i,n) bsum[i+1]=bsum[i]+b[i];
	int ret=0,here=0,l=0;
	REP(i,x) {
		int r=(int)min((ll)n-1,i+(ll)(i+1)*dmx);
		here+=bsum[r+1]-bsum[l]; l=r+1;
		if(here>=each) here-=each; else ++ret;
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&n,&dmx,&each); REP(i,n) scanf("%d",&a[i]);

	int n1=(n+1)/2,n2=n-n1;
	int rem1=n1*each; REP(i,n) { int cur=min(a[i],rem1); rem1-=cur; b[i]=cur; } int x1=solve(n1);
	int rem2=n2*each; REP(i,n) { int cur=min(a[n-i-1],rem2); rem2-=cur; b[i]=cur; } int x2=solve(n2);
	printf("%d\n",max(x1,x2));
}

int main() {
	run();
	return 0;
}