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

int MOD,n;
int a[MAXN];
int aa[MAXN];

int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int inv(int x) { return pw(x,MOD-2); }
int calctimes(int x) {
	int ret=0;
	int at=0;
	REP(i,n) {
		while(at<2*n) {
			int cur=at<n?a[at]:a[at-n]+MOD;
			if(cur-a[i]>x) break;
			if(cur-a[i]==x) ++ret;
			++at;
		}
	}
	return ret;
}
bool have(int x) {
	return (*lower_bound(a,a+n,x))==x;
}

pair<int,int> solve() {
	int g=a[1]-a[0];
	int t=calctimes(g);
	int k=n-t;
	int d=(ll)g*inv(k)%MOD;
	//printf("g=%d t=%d k=%d d=%d\n",g,t,k,d);
	//printf("a:"); REP(i,n) printf(" %d",a[i]); puts("");
	FORE(i,-(n-1),+(n-1)) {
		int x=(a[0]+(ll)i*d%MOD+MOD)%MOD; 
		if(!have(x)) continue;
		REP(j,n) {
			int xj=(x+(ll)j*d)%MOD;
			if(!have(xj)) return MP(-1,-1);
		}
		return MP(x,d);
	}
	return MP(-1,-1);
}

void run() {
	scanf("%d%d",&MOD,&n); REP(i,n) scanf("%d",&a[i]); sort(a,a+n);
	if(n==1) {
		printf("%d %d\n",a[0],1);
	} else if(2*n-2<MOD) {
		pair<int,int> ret=solve();
		if(ret.first==-1||ret.second==-1) printf("-1\n"); else printf("%d %d\n",ret.first,ret.second);
	} else if(n==MOD) {
		printf("%d %d\n",0,1);
	} else if(n==MOD-1) {
		REP(i,MOD) if(!have(i)) { printf("%d %d\n",(i+1)%MOD,1); break; }
	} else {
		int nn=0; REP(i,MOD) if(!have(i)) aa[nn++]=i; n=nn; REP(i,n) a[i]=aa[i];
		pair<int,int> ret=solve();
		if(ret.first==-1||ret.second==-1) printf("-1\n"); else printf("%d %d\n",(int)((ret.first+(ll)n*ret.second)%MOD),ret.second);
	}
}

int main() {
	run();
	return 0;
}