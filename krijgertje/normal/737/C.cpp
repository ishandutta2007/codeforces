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

int n,root;
int x[MAXN];
int cnt[MAXN];

int solve() {
	if(n==1) return x[0]==0?0:1;
	memset(cnt,0,sizeof(cnt)); REP(i,n) ++cnt[x[i]];
	int ret=INT_MAX,croot=0;
	if(x[root]!=0) { --cnt[x[root]]; ++cnt[0]; ++croot; }
	int mx=1,nalways=cnt[0]-1,nmay=0,nneed=0,nleft=n-cnt[0];
	FORE(mx,1,n-1) {
		if(nalways+nmay+nleft<nneed) break;
		if(cnt[mx]==0) ++nneed; else nmay+=cnt[mx]-1,nleft-=cnt[mx];
		int cur=croot+nalways+nleft+max(0,nneed-nalways-nleft); if(cur<ret) ret=cur;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&root),--root; REP(i,n) scanf("%d",&x[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}