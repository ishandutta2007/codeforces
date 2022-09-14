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

int n;
int x[MAXN];
int y[MAXN];


pair<int,ll> bt[MAXN+1];
pair<int,ll> bget(int idx) { ++idx; pair<int,ll> ret=MP(0,0LL); while(idx>0) { ret.first+=bt[idx].first,ret.second+=bt[idx].second; idx-=idx&-idx; } return ret; }
void bmod(int idx,ll by) { ++idx; while(idx<=n) { bt[idx].first++,bt[idx].second+=by; idx+=idx&-idx; } }

/*double pall[MAXN],pbefore[MAXN];
void bf() {
	ll ways=(ll)n*(n+1)/2; memset(pall,0,sizeof(pall)); memset(pbefore,0,sizeof(pbefore));
	REP(i,n) FOR(j,i,n) {
		FORE(a,i,j) FORE(b,a+1,j) {
			pall[a]+=1.0/ways; pall[b]+=1.0/ways;
		}
		REP(a,n) FOR(b,a+1,n) if(x[a]>x[b]&&!(a>=i&&b<=j)) pbefore[b]+=1.0/ways;
	}
}*/

ll sm(int a,int b) { return (ll)(a+b)*(b-a+1)/2; }
void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]),--x[i]; REP(i,n) y[x[i]]=i;

	//bf();
	double ret=0; ll ways=(ll)n*(n+1)/2;
	memset(bt,0,sizeof(bt));
	for(int i=n-1;i>=0;--i) {
		int at=y[i];
		ll all=(ll)(n-at)*sm(1,at)+(ll)(at+1)*sm(1,n-at-1);
		pair<int,ll> before=bget(at); bmod(at,at+1);
		ll inv=ways*before.first-(ll)(n-at)*before.second;
		ret+=0.25*all/ways+1.0*inv/ways;
		//ret+=0.25*pall[at]+1.0*pbefore[at];
		//printf("%d: sum(p)=%lf sum(1-p|to<at)=%lf [%lf,%lf] <%lld*%d-%d*%lld>\n",at,1.0*all/ways,1.0*inv/ways,pall[at],pbefore[at],ways,before.first,n-at,before.second);
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}