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

int n;

int solve() {
	int a=1,b=2;
	while(true) {
		//printf("a=%d b=%d\n",a,b);
		if(n==a||n==b) return 1;
		if(a>n&&b>n) return 0;
		a=2*b,b=a+1;
		//printf("a=%d b=%d\n",a,b);
		if(n==a||n==b) return 1;
		if(a>n&&b>n) return 0;
		b=2*b,a=b-1;
	}
}

void run() {
	scanf("%d",&n);
	printf("%d\n",solve());
}

map<ll,int> mem;

int rec(int n,int dep,bool samepar,bool root) {
	ll key=100*n+2*dep+(samepar?1:0);
	if(mem.count(key)) return mem[key];
	int ret=0;
	if(n==1&&samepar&&(dep==1||dep==2)) ++ret;
	if(n==2&&dep==2&&!samepar) ++ret;
	FORE(i,2,n-1) {
		if(samepar&&i%2==0) continue;
		if(!samepar&&i%2==1) continue;
		int cur=rec(i-1,dep-1,i%2==0,false)*rec(n-i,dep-1,false,false);
		//if(cur>0&&root) printf("\tn=%d dep=%d samepar=%s -> root=%d -> %d\n",n,dep,samepar?"yes":"no",i,cur);
		ret+=cur;
	}
	return mem[key]=ret;
}

void research() {
	FORE(n,1,1000) {
		int dep=1; while((1<<dep)-1<n) ++dep;
		int a=rec(n,dep,true,true),b=rec(n,dep,false,true);
		if(a+b>0) printf("%d: dep=%d tot=%d\n",n,dep,a+b);
	}
}

int main() {
	//research();
	run();
	return 0;
}