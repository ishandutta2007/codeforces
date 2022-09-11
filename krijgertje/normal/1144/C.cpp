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

int x[MAXN],nx;
int y[MAXN],ny;

bool solve() {
	sort(a,a+n);
	nx=ny=0;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&a[l]==a[r]) ++r;
		int cnt=r-l,val=a[l];
		if(cnt>=3) return false;
		if(cnt>=1) x[nx++]=val;
		if(cnt>=2) y[ny++]=val;
	}
	reverse(y,y+ny);
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n",nx); REP(i,nx) { if(i!=0) printf(" "); printf("%d",x[i]); } puts("");
	printf("%d\n",ny); REP(i,ny) { if(i!=0) printf(" "); printf("%d",y[i]); } puts("");
}

int main() {
	run();
	return 0;
}