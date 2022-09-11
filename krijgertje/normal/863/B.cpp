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

const int MAXN=50;

int n;
int w[2*MAXN];

void run() {
	scanf("%d",&n); REP(i,2*n) scanf("%d",&w[i]); sort(w,w+2*n);
	int ret=INT_MAX;
	REP(i,2*n) FOR(j,i+1,2*n) {
		int prv=-1,cur=0;
		REP(k,2*n) if(k!=i&&k!=j) {
			if(prv==-1) prv=w[k]; else cur+=w[k]-prv,prv=-1;
		}
		//printf("%d %d -> %d\n",i,j,cur);
		if(cur<ret) ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}