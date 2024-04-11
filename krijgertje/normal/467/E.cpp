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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=500000;
const int MAXS=1<<20;

int n;
int a[MAXN];
int order[MAXN]; bool ordercmp(const int &p,const int &q) { if(a[p]!=a[q]) return a[p]<a[q]; return p<q; }
int prv[MAXN],nxt[MAXN];

int bst[MAXN];
int idx[MAXN][4];
int cnt[MAXN+1];
int cnxt[MAXN+1];

int sval[MAXS],sbase;
void sinit() {
	sbase=1; while(sbase<n) sbase*=2;
	FORE(i,1,sbase*2) sval[i]=INT_MAX;
}
void sset(int at,int val) {
	at+=sbase;
	sval[at]=val;
	while(at!=1) {
		at/=2;
		sval[at]=min(sval[2*at+0],sval[2*at+1]);
	}
}
int sget(int l,int r) {
	l+=sbase,r+=sbase; int ret=INT_MAX;
	while(l<=r) {
		if(l%2==1) ret=min(ret,sval[l]),++l;
		if(r%2==0) ret=min(ret,sval[r]),--r;
		l/=2; r/=2;
	}
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	REP(i,n) order[i]=i; sort(order,order+n,ordercmp);
	REP(i,n) {
		prv[order[i]]=i==0||a[order[i-1]]!=a[order[i]]?-1:order[i-1];
		nxt[order[i]]=i==n-1||a[order[i]]!=a[order[i+1]]?-1:order[i+1];
	}
	//if(n==20) REP(i,n) printf("%d ",order[i]); puts("");
	//if(n==20) REP(i,n) printf("%d ",prv[i]); puts(""); REP(i,n) printf("%d ",nxt[i]); puts("");
	sinit();
	REP(i,n) bst[i]=INT_MAX;
	REP(i,n) {
		if(prv[i]!=-1) {
			sset(prv[i],INT_MAX);
			if(prv[i]+1<=i-1) {
				int j=sget(prv[i]+1,i-1);
				if(j<bst[prv[i]]) { bst[prv[i]]=j; idx[prv[i]][0]=prv[i]; idx[prv[i]][1]=prv[j]; idx[prv[i]][2]=i; idx[prv[i]][3]=j; }
			}
		}
		if(nxt[i]!=-1) {
			sset(i,nxt[i]);
		}
	}
	REP(i,n) if(nxt[i]!=-1&&nxt[nxt[i]]!=-1&&nxt[nxt[nxt[i]]]!=-1&&nxt[nxt[nxt[i]]]<bst[i]) {
		bst[i]=nxt[nxt[nxt[i]]]; idx[i][0]=i; idx[i][1]=nxt[i]; idx[i][2]=nxt[nxt[i]]; idx[i][3]=nxt[nxt[nxt[i]]];
	}

	REPE(i,n) cnt[i]=0,cnxt[i]=-1;
	for(int i=n-1;i>=0;--i) {
		if(cnt[i+1]>cnt[i]) { cnt[i]=cnt[i+1]; cnxt[i]=cnxt[i+1]; }
		if(bst[i]!=INT_MAX&&cnt[bst[i]+1]+1>cnt[i]) { cnt[i]=cnt[bst[i]+1]+4; cnxt[i]=i; }
	}
	//if(n==20) REPE(i,n) printf("%d %d: %d %d %d %d / %d %d\n",i,bst[i]==INT_MAX?-1:bst[i],idx[i][0],idx[i][1],idx[i][2],idx[i][3],cnt[i],cnxt[i]);
	printf("%d\n",cnt[0]);
	for(int x=cnxt[0];x!=-1;x=cnxt[bst[x]+1]) { if(x!=cnxt[0]) printf(" "); printf("%d %d %d %d",a[idx[x][0]],a[idx[x][1]],a[idx[x][2]],a[idx[x][3]]); } puts("");


}

int main() {
	run();
	return 0;
}