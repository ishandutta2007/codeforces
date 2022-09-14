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
int a[200000];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	int ret=0,at=0;
	while(at<n) {
		int to=at;
		int p=-1,q=-1; ll dy=0; bool running=false;
		for(;to<n;++to) {
			if(a[to]==-1) {
				if(p!=-1&&q!=-1&&a[p]+(to-p)*dy<=0) break;
				if(!running) running=true,++ret;
				continue;
			}
			if(p==-1) {
				p=to;
				if(!running) running=true,++ret;
				continue;
			}
			if(q==-1) {
				q=to;
				if((a[q]-a[p])%(q-p)!=0) break;
				dy=(a[q]-a[p])/(q-p);
				if(a[p]+(at-p)*dy<=0) break;
				if(!running) running=true,++ret;
				continue;
			}
			if(a[p]+(to-p)*dy!=a[to]) break;
			if(!running) running=true,++ret;
			continue;
		}
		at=to;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}