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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;

int n;
int a[MAXN];

int pos[MAXN];

bool solve() {
	REP(i,n) pos[a[i]]=i;
	int l=pos[n-1],r=pos[n-1];
	for(int i=n-2;i>=0;--i) {
		int x=pos[i];
		if(x!=l-1&&x!=r+1) return false;
		l=min(l,x),r=max(r,x);
	}
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]),--a[i];
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}