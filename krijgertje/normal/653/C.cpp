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

const int MAXN=150000;

int n;
int x[MAXN];

int err[MAXN],nerr;
bool inerr[MAXN];

bool ok(int idx,int u,int v) {
	return idx%2==0&&v>u||idx%2==1&&v<u;
}
bool test(int a,int b) {
	if(a==b) return false;
	if(a>b) swap(a,b);
	if(a-1>=0&&!ok(a-1,x[a-1],x[b])) return false;
	if(a+1<b&&!ok(a,x[b],x[a+1])) return false;
	if(b-1>a&&!ok(b-1,x[b-1],x[a])) return false;
	if(b+1<n&&!ok(b,x[a],x[b+1])) return false;
	REP(i,nerr) if(!ok(err[i],x[err[i]==a?b:err[i]==b?a:err[i]],x[err[i]+1==a?b:err[i]+1==b?a:err[i]+1])) return false;
	//printf("%d %d\n",a,b);
	return true;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);

	nerr=0; memset(inerr,false,sizeof(inerr)); REP(i,n-1) if(!ok(i,x[i],x[i+1])) err[nerr++]=i,inerr[i]=inerr[i+1]=true;
	if(nerr>4) { printf("0\n"); return; }
	int ret=0;
	if(nerr==1) REP(ax,2) REP(b,n) if(!inerr[b]&&test(err[0]+ax,b)) ++ret;
	if(nerr==2&&err[1]==err[0]+1) REP(b,n) if(!inerr[b]&&test(err[1],b)) ++ret;
	REP(ai,nerr) REP(ax,2) FOR(bi,ai,nerr) FOR(bx,ai==bi?ax+1:0,2) {
		if(ai>0&&ax==0&&err[ai-1]+1==err[ai]) continue;
		if(bi>0&&bx==0&&err[bi-1]+1==err[bi]) continue;
		int a=err[ai]+ax,b=err[bi]+bx;
		if(test(a,b)) ++ret;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}