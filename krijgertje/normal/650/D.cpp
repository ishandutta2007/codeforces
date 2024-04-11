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

const int MAXN=400000;
const int MAXQ=400000;

int n,nq;
int x[MAXN];
int qx[MAXQ],qi[MAXQ],qhead[MAXN],qnxt[MAXQ],mret[MAXQ];
bool onmn[MAXN],onmx[MAXN];


int a[MAXN],ai[MAXN],p[MAXN],na;
int find(int b) { // first position with a[i]>=b
	int l=-1,h=na; // (l,h]
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(a[m]>=b) h=m; else l=m;
	}
	return h;
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&x[i]);
	REP(i,n) qhead[i]=-1,onmn[i]=onmx[i]=false;
	REP(i,nq) {
		int idx; scanf("%d%d",&idx,&qx[i]); --idx; qi[i]=idx;
		qnxt[i]=qhead[idx]; qhead[idx]=i; mret[i]=1;
	}

	na=0;
	REP(i,n) {
		for(int j=qhead[i];j!=-1;j=qnxt[j]) {
			int qidx=find(qx[j]); mret[j]+=qidx;
		}
		int idx=find(x[i]); a[idx]=x[i],ai[idx]=i,p[i]=idx==0?-1:ai[idx-1]; if(idx>=na) ++na;
	}
	for(int i=ai[na-1];i!=-1;i=p[i]) onmx[i]=true;

	na=0;
	for(int i=n-1;i>=0;--i) {
		for(int j=qhead[i];j!=-1;j=qnxt[j]) {
			int qidx=find(-qx[j]); mret[j]+=qidx;
		}
		int idx=find(-x[i]); a[idx]=-x[i],ai[idx]=i,p[i]=idx==0?-1:ai[idx-1]; if(idx>=na) ++na;
	}
	for(int i=ai[na-1];i!=-1;i=p[i]) onmn[i]=true;

	//REP(i,nq) printf("%d: %d %d %d\n",i,mret[i],onmn[qi[i]],onmx[qi[i]]);
	REP(i,nq) {
		int cur=max(mret[i],na-(onmn[qi[i]]&&onmx[qi[i]]?1:0));
		printf("%d\n",cur);
	}
}

int main() {
	run();
	return 0;
}