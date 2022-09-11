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

const int MAXN=140582;

int n;
int b[MAXN];

ll a[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&b[i]);

	int bmx=b[0]; FOR(i,1,n) bmx=max(bmx,b[i]);
	REP(i,n) {
		int j=(i+1)%n;
		if(b[i]>=b[j]) continue;
		printf("YES\n");
		a[j]=b[j];
		a[i]=(ll)(bmx-b[i]+b[j])/b[j]*b[j]+b[i];
		REP(k,n-2) {
			int x=(i+n-k-1)%n,y=(x+1)%n;
			a[x]=a[y]+b[x];
		}
		REP(k,n) { if(k!=0) printf(" "); printf("%lld",a[k]); } puts("");
		return;
	}
	bool allzero=true; REP(i,n) if(b[i]!=0) allzero=false;
	if(allzero) {
		printf("YES\n");
		REP(k,n) { if(k!=0) printf(" "); printf("1"); } puts("");
		return;
	}
	printf("NO\n");
}

int main() {
	run();
	return 0;
}