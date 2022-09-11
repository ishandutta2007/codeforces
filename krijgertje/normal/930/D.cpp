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
const int MAXXY=200000+10;
const int MAXUV=2*MAXXY;

int n;
int x[MAXN],y[MAXN];
int u[MAXN],v[MAXN];

int a[MAXUV+1];
int b[MAXUV+1];
int c[MAXUV+1];
int d[MAXUV+1];

ll calc(int par) {
	//REP(i,n) if((x[i]+y[i])%2==par) printf("(%d,%d)",v[i],u[i]); puts("");

	REPE(i,MAXUV) a[i]=INT_MIN;
	REP(i,n) if((x[i]+y[i])%2==par&&v[i]!=0) a[v[i]-1]=max(a[v[i]-1],u[i]-1);
	for(int i=MAXUV-1;i>=0;--i) a[i]=max(a[i],a[i+1]);
	//printf("a:"); REPE(i,MAXUV) if(a[i]==INT_MIN) printf(" XX"); else printf(" %2d",a[i]); puts("");

	REPE(i,MAXUV) b[i]=INT_MIN;
	REP(i,n) if((x[i]+y[i])%2==par&&v[i]!=MAXUV) b[v[i]+1]=max(b[v[i]+1],u[i]-1);
	FORE(i,1,MAXUV) b[i]=max(b[i],b[i-1]);
	//printf("b:"); REPE(i,MAXUV) if(b[i]==INT_MIN) printf(" XX"); else printf(" %2d",b[i]); puts("");

	REPE(i,MAXUV) c[i]=INT_MAX;
	REP(i,n) if((x[i]+y[i])%2==par&&v[i]!=0) c[v[i]-1]=min(c[v[i]-1],u[i]+1);
	for(int i=MAXUV-1;i>=0;--i) c[i]=min(c[i],c[i+1]);
	//printf("c:"); REPE(i,MAXUV) if(c[i]==INT_MAX) printf(" XX"); else printf(" %2d",c[i]); puts("");

	REPE(i,MAXUV) d[i]=INT_MAX;
	REP(i,n) if((x[i]+y[i])%2==par&&v[i]!=MAXUV) d[v[i]+1]=min(d[v[i]+1],u[i]+1);
	FORE(i,1,MAXUV) d[i]=min(d[i],d[i-1]);
	//printf("d:"); REPE(i,MAXUV) if(d[i]==INT_MAX) printf(" XX"); else printf(" %2d",d[i]); puts("");

	ll ret=0;
	REPE(i,MAXUV) if(i%2!=par) {
		int mx=min(a[i],b[i]),mn=max(c[i],d[i]);
		if(mn>mx) continue;
		//printf("%d: %d..%d (%d vs %d)\n",i,mn,mx,mx%2,(par+i)%2);
		if(mx!=INT_MIN&&mx%2!=i%2) --mx;
		if(mn!=INT_MAX&&mn%2!=i%2) ++mn;
		if(mn>mx) continue;
		int cur=(mx-mn)/2+1;
		//printf("%d: %d..%d -> %d\n",i,mn,mx,cur);
		ret+=cur;
	}
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&x[i],&y[i]),x[i]+=MAXXY/2,y[i]+=MAXXY/2;

	REP(i,n) u[i]=x[i]+y[i],v[i]=y[i]-x[i]+MAXUV/2;
	
	ll ret=0;
	ret+=calc(0);
	ret+=calc(1);
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}