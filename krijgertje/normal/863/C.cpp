#include <algorithm>  /
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


ll n; int sa,sb;
int ta[3][3],tb[3][3];

void run() {
	scanf("%lld%d%d",&n,&sa,&sb); --sa,--sb;
	REP(i,3) REP(j,3) scanf("%d",&ta[i][j]),--ta[i][j];
	REP(i,3) REP(j,3) scanf("%d",&tb[i][j]),--tb[i][j];
	//printf("ta:"); REP(i,3) REP(j,3) printf(" %d",ta[i][j]+1); puts(""); printf("sa=%d\n",sa+1);
	//printf("tb:"); REP(i,3) REP(j,3) printf(" %d",tb[i][j]+1); puts(""); printf("sb=%d\n",sb+1);
	map<pair<int,int>,pair<ll,pair<ll,ll> > > been; ll t=0;
	int a=sa,b=sb; ll awin=0,bwin=0;
	while(!been.count(MP(a,b))&&t<n) {
		been[MP(a,b)]=MP(t,MP(awin,bwin));
		int na=ta[a][b],nb=tb[a][b];
		if(a==(b+1)%3) ++awin; if(b==(a+1)%3) ++bwin;
		a=na,b=nb,++t;
		//printf("%lld: %d %d [%lld %lld]\n",t,a+1,b+1,awin,bwin);
	}
	if(t<n) {
		ll per=t-been[MP(a,b)].first; ll dawin=awin-been[MP(a,b)].second.first,dbwin=bwin-been[MP(a,b)].second.second;
		ll rep=(n-t)/per;
		//printf("per=%lld dawin=%lld dbwin=%lld -> rep=%lld\n",per,dawin,dbwin,rep);
		t+=rep*per,awin+=rep*dawin,bwin+=rep*dbwin;
	}
	while(t<n) {
		int na=ta[a][b],nb=tb[a][b];
		if(a==(b+1)%3) ++awin; if(b==(a+1)%3) ++bwin;
		a=na,b=nb,++t;
	}
	printf("%lld %lld\n",awin,bwin);
}

int main() {
	run();
	return 0;
}