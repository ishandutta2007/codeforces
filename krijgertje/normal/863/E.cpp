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
int l[MAXN],r[MAXN];

int x[3*MAXN],nx;

int cnt[3*MAXN+1];
int one[3*MAXN+1],none;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&l[i],&r[i]);
	nx=0; REP(i,n) { x[nx++]=l[i]; x[nx++]=r[i]+1; if(l[i]+1<=r[i]) x[nx++]=l[i]+1; } sort(x,x+nx); nx=unique(x,x+nx)-x;
	REP(i,n) l[i]=lower_bound(x,x+nx,l[i])-x,r[i]=lower_bound(x,x+nx,r[i]+1)-x;
	REPE(i,nx) cnt[i]=0; REP(i,n) ++cnt[l[i]],--cnt[r[i]];
	REP(i,nx) cnt[i+1]+=cnt[i];
	none=0; REPE(i,nx) if(cnt[i]==1) one[none++]=i;
	REP(i,n) {
		int fst=lower_bound(one,one+none,l[i])-one; if(fst<none&&one[fst]<r[i]) continue;
		printf("%d\n",i+1); return;
	}
	printf("-1\n");
}

int main() {
	run();
	return 0;
}