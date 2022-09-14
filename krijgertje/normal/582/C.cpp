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

const int MAXN=200000;

int n;
int x[2*MAXN];

int g[MAXN];
int mx[MAXN];
int cnt[MAXN+1];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&x[i]);
	REP(i,n) x[n+i]=x[i];
	FOR(i,1,n) g[i]=gcd(i,n);

	
	bool same=true; FOR(i,1,n) if(x[i]!=x[0]) same=false;
	if(same) { printf("%I64d\n",(ll)n*(n-1)); return; }

	ll ret=0;
	FOR(p,1,n) if(n%p==0) {
		memset(cnt,0,sizeof(cnt));
		REP(i,p) {
			mx[i]=x[i];
			for(int j=p+i;j<n;j+=p) if(x[j]>mx[i]) mx[i]=x[j];
		}
		int a=0,b=0;
		//printf("%d\n",p); REP(i,p) printf("%d ",mx[i]); puts("");
		while(a<n) {
			while(b<a+n-1&&x[b]==mx[b%p]) ++b;
			cnt[b-a]++;
			++a; if(b<a) b=a;
		}
		for(int i=n;i>=1;--i) cnt[i-1]+=cnt[i];
		FOR(i,1,n) if(g[i]==p) ret+=cnt[i];
	}

	printf("%I64d\n",ret);
}


int main() {
	run();
	return 0;
}