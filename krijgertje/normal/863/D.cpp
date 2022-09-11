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
const int MAXQ=200000;
const int MAXM=100;

int n,nq,m;
int x[MAXN];
int qkind[MAXQ],ql[MAXQ],qr[MAXQ];
int ans[MAXM];

void run() {
	scanf("%d%d%d",&n,&nq,&m); REP(i,n) scanf("%d",&x[i]); REP(i,nq) scanf("%d%d%d",&qkind[i],&ql[i],&qr[i]),--ql[i],--qr[i];
	REP(i,m) {
		int idx; scanf("%d",&idx); --idx;
		for(int j=nq-1;j>=0;--j) {
			if(qkind[j]==1&&ql[j]<=idx&&idx<=qr[j]) {
				idx=idx==ql[j]?qr[j]:idx-1;
			}
			if(qkind[j]==2&&ql[j]<=idx&&idx<=qr[j]) {
				idx=qr[j]-(idx-ql[j]);
			}
		}
		ans[i]=x[idx];
	}
	REP(i,m) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}