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

const int MAXN=300000;

int n,lim;
int x[MAXN];

void run() {
	scanf("%d%d",&n,&lim); REP(i,n) scanf("%d",&x[i]);
	int at=0,to=0,need=0,ret=0,sret=-1;
	while(to<n) {
		if(x[to++]==0) ++need;
		while(need>lim) if(x[at++]==0) --need;
		int cnt=to-at; if(cnt>ret) ret=cnt,sret=at;
	}
	printf("%d\n",ret);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",i>=sret&&i<sret+ret?1:x[i]); } puts("");
}

int main() {
	run();
	return 0;
}