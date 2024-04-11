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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
struct Seg { int l,r,id; };
bool operator<(const Seg &a,const Seg &b) { return a.l<b.l; }

int n;
Seg seg[MAXN];
int ans[MAXN];

bool solve() {
	sort(seg,seg+n);
	int upto=seg[0].r;
	REP(i,n) {
		if(seg[i].l>upto) { REP(j,n) ans[seg[j].id]=seg[j].r<=upto?1:2; return true; }
		upto=max(upto,seg[i].r);
	}
	return false;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&seg[i].l,&seg[i].r),seg[i].id=i;
	if(!solve()) { printf("-1\n"); return; }
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	int n; scanf("%d",&n); REP(i,n) run();
	return 0;
}