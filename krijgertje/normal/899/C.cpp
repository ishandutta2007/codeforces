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

const int MAXN=60000;

int a[MAXN],na;
int b[MAXN],nb;
ll asum,bsum;

void solve(int n) {
	na=0,nb=0;
	int l=1,h=n;
	if(n%4==1) a[na++]=l++;
	if(n%4==2) a[na++]=l++,b[nb++]=l++;
	if(n%4==3) a[na++]=l++,a[na++]=l++,b[nb++]=l++;
	assert((h-l+1)%4==0);
	while(l<=h) {
		a[na++]=l++,a[na++]=h--;
		b[nb++]=l++,b[nb++]=h--;
	}
	asum=0; REP(i,na) asum+=a[i];
	bsum=0; REP(i,nb) bsum+=b[i];
}

int n;

void run() {
	scanf("%d",&n);
	solve(n);
	printf("%lld\n",abs(asum-bsum)); printf("%d",na); REP(i,na) printf(" %d",a[i]); puts("");
}

int main() {
	run();
	return 0;
}