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
typedef struct R { int val,idx; } R;
bool operator<(const R &a,const R &b) { if(a.val!=b.val) return a.val<b.val; return a.idx<b.idx; }

int n,cap,cf,cm; ll have;
R x[MAXN];
ll ans[MAXN];

void run() {
	scanf("%d%d%d%d%I64d",&n,&cap,&cf,&cm,&have);
	REP(i,n) scanf("%d",&x[i].val),x[i].idx=i; sort(x,x+n);

	ll left=have; int b=n;
	while(b>0&&left>=cap-x[b-1].val) left-=cap-x[--b].val;
	if(b==0) { printf("%I64d\n",(ll)n*cf+(ll)cap*cm); REP(i,n) { if(i!=0) printf(" "); printf("%d",cap); } puts(""); return; }

	int a=0; ll ret=-1,retmn=-1; int reta=0,retb=0;
	while(true) {
		while(a+1<b&&left>=(ll)(a+1)*(x[a+1].val-x[a].val)) left-=(ll)(a+1)*(x[a+1].val-x[a].val),++a;
		ll mn=x[a].val+left/(a+1);
		ll cur=(ll)(n-b)*cf+(ll)mn*cm; if(cur>ret) ret=cur,reta=a,retb=b,retmn=mn;
		if(b==n) break; else left+=cap-x[b++].val;
	}

	REPE(i,reta) ans[x[i].idx]=retmn; FOR(i,reta+1,retb) ans[x[i].idx]=x[i].val; FOR(i,retb,n) ans[x[i].idx]=cap;

	printf("%I64d\n",ret);
	REP(i,n) { if(i!=0) printf(" "); printf("%I64d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}