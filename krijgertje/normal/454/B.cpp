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

int n;
int a[100000];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	bool same=true; FOR(i,1,n) if(a[i]!=a[i-1]) same=false;
	if(same) { printf("%d\n",0); return; }
	int x=0; FOR(i,1,n) if(a[i]<a[x]||a[i]==a[x]&&x==0&&a[i-1]!=a[i]) x=i;
	bool ok=true; REP(i,n) if(i!=x&&a[i==0?n-1:i-1]>a[i]) ok=false;
	if(!ok) { printf("%d\n",-1); return; }
	printf("%d\n",x==0?0:n-x);
}


int main() {
	run();
	return 0;
}