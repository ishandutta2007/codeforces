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

int n,len;
int x[MAXN];

bool ok(int z) {
	REP(d0,2) REP(d1,2) {
		int a,b; if(d0==0) a=x[0]-z,b=x[0]; else a=x[0],b=x[0]+z;
		int at=0,to=1;
		if(d0==0) { while(at-1+n>=to&&a+len<=x[at-1+n]) --at; if(at==0&&d1==1) continue; if(at!=0&&d1==0) a=x[at+n]-len-z;  if(at!=0&&d1==1) b=x[at+n]-len+z; if(at!=0&&at!=-1&&d1==0) b=x[at+1+n]-len+z;}
		if(d0==1) { while(to<n&&x[to]<=b) ++to; if(to==1&&d1==1) continue; if(to!=1&&d1==0) a=x[to-1]-z; if(to!=1&&d1==1) b=x[to-1]+z; if(to!=1&&to!=2) a=x[to-2]-z; }
		//printf("%d %d -> %d..%d | %d..%d\n",d0,d1,at,to,a,b);
		bool res=true;
		for(int i=to;i<at+n;++i) {
			if(b+1>=x[i]) b=x[i]+z;
			else if(i+1<at+n&&b+1>=x[i+1]-z&&x[i+1]>x[i]+1) b=x[i]+z,++i;
			else if(b+1>=x[i]-z) b=x[i];
			else { res=false; break; }
			//printf("\tafter %d: %d\n",i,b);
		}
		if(res&&b-a+1>=len) return true;
	}
	return false;
}

void run() {
	scanf("%d%d",&len,&n); REP(i,n) scanf("%d",&x[i]),--x[i];

	//REP(i,n) printf("%d ",x[i]); puts("");
	//printf("ret=%d\n",ok(3)?1:0); exit(0);

	int l=-1,h=len-1;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(ok(m)) h=m; else l=m;
	}
	printf("%d\n",h);
}

int main() {
	run();
	return 0;
}