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

// x[i](t+1)=a*x[i](t)+b=c[i] % mod
int mod,sx[2],a[3],b[3],c[2];

int nx(int x,int i) { return  ((ll)a[i]*x+b[i])%mod; }

void run() {
	scanf("%d%d%d%d%d%d%d%d%d",&mod,&sx[0],&c[0],&a[0],&b[0],&sx[1],&c[1],&a[1],&b[1]);

	int x0=sx[0],x1=sx[1],t=0;
	while(x0!=c[0]&&t<mod) ++t,x0=nx(x0,0),x1=nx(x1,1);
	if(x0!=c[0]) { printf("-1\n"); return; }
	if(x1==c[1]) { printf("%d\n",t); return; }
	int pt=0; a[2]=1,b[2]=0;
	while(pt==0||x0!=c[0]&&pt<mod) ++pt,x0=nx(x0,0),a[2]=(ll)a[1]*a[2]%mod,b[2]=((ll)a[1]*b[2]+b[1])%mod;
	if(x0!=c[0]) { printf("-1\n"); return; }
	int np=0;
	while(x1!=c[1]&&np<mod) ++np,x1=nx(x1,2);
	if(x1!=c[1]) { printf("-1\n"); return; }
	ll ret=(ll)np*pt+t;
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}