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
#include <random>
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
const int MAXA=100000;
const int MOD=1000000007;

int n;
int a[MAXN];

int mndv[MAXA+1];
int mu[MAXA+1];
int p2[MAXN+1];

int cnt[MAXA+1];


void run() {
	p2[0]=1; FORE(i,1,MAXN) p2[i]=2*p2[i-1]%MOD;
	memset(mndv,-1,sizeof(mndv));
	FORE(i,2,MAXA) if(mndv[i]==-1) for(int j=i;j<=MAXA;j+=i) if(mndv[j]==-1) mndv[j]=i;
	mu[1]=1; FORE(i,2,MAXA) mu[i]=mndv[i]==mndv[i/mndv[i]]?0:-mu[i/mndv[i]];
	//FORE(i,1,100) printf("%d: %d\n",i,mu[i]);

	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	memset(cnt,0,sizeof(cnt));
	REP(i,n) {
		for(int x=1;x*x<=a[i];++x) if(a[i]%x==0) {
			++cnt[x];
			if(x*x!=a[i]) ++cnt[a[i]/x];
		}
	}
	int ret=0;
	FORE(i,1,MAXA) if(cnt[i]!=0) {
		//printf("%d: %d -> %d*%d\n",i,cnt[i],mu[i],p2[cnt[i]]-1);
		ret=(ret+(ll)mu[i]*(p2[cnt[i]]-1))%MOD;
	}
	if(ret<0) ret+=MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}