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
int cnt[MAXN];
ll sum[MAXN+1];
int l,r;

ll calc(int l,int r) {
	if(r<0) return calc(l+n,r+n);
	if(l<0) return calc(l+n,n-1)+calc(0,r);
	return sum[r+1]-sum[l];
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&cnt[i]); scanf("%d%d",&l,&r); --r;
	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+cnt[i];
	ll retres=-1; int retidx=-1;
	FORE(curidx,1,n) {
		ll curres=calc(l-curidx,r-curidx);
		if(curres>retres) retres=curres,retidx=curidx;
		//printf("%d: %lld\n",curidx,curres);
	}
	printf("%d\n",retidx);
}

int main() {
	run();
	return 0;
}