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

int n;
int x[MAXN],sx;
int calc(int a,int b) {
	return min(abs(x[b]-sx)+abs(x[b]-x[a]),abs(x[a]-sx)+abs(x[b]-x[a]));
}

void run() {
	scanf("%d%d",&n,&sx); REP(i,n) scanf("%d",&x[i]); sort(x,x+n);
	if(n==1) { printf("0\n"); return; }
	int ret=min(calc(0,n-2),calc(1,n-1));
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}