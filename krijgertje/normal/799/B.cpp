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

int n,nq;
int p[MAXN];
int a[MAXN];
int b[MAXN];
int ret[MAXQ];

vector<int> rem[3][3];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&p[i]);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&b[i]);
	REP(i,n) rem[a[i]-1][b[i]-1].PB(p[i]);
	REP(i,3) REP(j,3) { sort(rem[i][j].begin(),rem[i][j].end()); reverse(rem[i][j].begin(),rem[i][j].end()); }
	scanf("%d",&nq);
	REP(qi,nq) {
		int x; scanf("%d",&x); --x;
		int bi=-1,bj=-1,bval=INT_MAX;
		REP(i,3) REP(j,3) if(SZ(rem[i][j])>0&&(i==x||j==x)) { int cur=rem[i][j].back(); if(cur<bval) bval=cur,bi=i,bj=j; }
		if(bval==INT_MAX) ret[qi]=-1; else ret[qi]=bval,rem[bi][bj].pop_back();
	}
	REP(i,nq) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}