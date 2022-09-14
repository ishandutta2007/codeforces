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

int n,nq;
int a[MAXN];


void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]); sort(a,a+n);
	REP(qi,nq) {
		int x; scanf("%d",&x);
		int l=-1,h=n;
		while(l+1<h) {
			int m=l+(h-l)/2;
			if(a[m]<=x) l=m; else h=m;
		}
		if(qi!=0) printf(" "); printf("%d",l+1); if(qi==nq-1) printf("\n");
	}

}

int main() {
	run();
	return 0;
}