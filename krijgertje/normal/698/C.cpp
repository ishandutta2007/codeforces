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

const int MAXN=20;

int n,lim;
double x[MAXN];

int cnt[1<<MAXN];
double sum[1<<MAXN];
double ret[MAXN];
double p[1<<MAXN];

void run() {
	scanf("%d%d",&n,&lim); REP(i,n) scanf("%lf",&x[i]);

	REP(i,1<<n) { sum[i]=0; cnt[i]=0; REP(j,n) if(i&(1<<j)) sum[i]+=x[j],++cnt[i]; }
	REP(i,n) {
		ret[i]=0;
		if(x[i]==0) continue;
		p[0]=x[i];
		FOR(j,1,1<<n) {
			p[j]=0;
			if(j&(1<<i)) continue;
			REP(k,n) if(j&(1<<k)) {
				p[j]+=p[j-(1<<k)]*x[k]/(1-sum[j]);
			}
		}
		//printf("%d:",i); REP(j,1<<n) printf(" %.2lf",p[j]); puts("");
		REP(j,1<<n) if(cnt[j]+1<=lim) ret[i]+=p[j];
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%.9lf",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}