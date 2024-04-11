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

const int MAXN=200000;

int n;
int a[MAXN];

int h,w;
bool solve() {
	w=-1;
	REP(i,n-1) {
		int diff=abs(a[i+1]-a[i]);
		if(diff==0) return false;
		if(diff==1) continue;
		if(w!=-1&&diff!=w) return false;
		w=diff;
	}
	int amx=a[0]; REP(i,n) amx=max(amx,a[i]);
	if(w==-1) {
		h=1; w=amx; return true;
	} else {
		h=(amx+w-1)/w;
		REP(i,n-1) {
			int diff=abs(a[i+1]-a[i]);
			if(diff!=1) continue;
			if((a[i]-1)/w!=(a[i+1]-1)/w||(a[i]-1)/w!=(a[i+1]-1)/w) return false;
		}
		return true;
	}
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n"); printf("%d %d\n",h,w);
}

int main() {
	run();
	return 0;
}