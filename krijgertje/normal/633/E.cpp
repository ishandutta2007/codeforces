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

const int MAXN=1000000;

int n,nq;
int v[MAXN],c[MAXN];

int mn[MAXN],mnhead,mntail;
int mx[MAXN],mxhead,mxtail;
int dp[MAXN];



void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&v[i]),v[i]*=100;
	REP(i,n) scanf("%d",&c[i]);

	mnhead=mntail=mxhead=mxtail=0;
	for(int i=n-1;i>=0;--i) {
		while(mntail<mnhead&&c[i]<=c[mn[mnhead-1]]) --mnhead; mn[mnhead++]=i;
		while(mxtail<mxhead&&v[i]>=v[mx[mxhead-1]]) --mxhead; mx[mxhead++]=i;
		while(mn[mntail]!=i||mx[mxtail]!=i) {
			int mnidx=mn[mntail],mxidx=mx[mxtail];
			if(c[mnidx]>v[mxidx]||c[mnidx<mxidx?mnidx:mn[mntail+1]]>v[mxidx<mnidx?mxidx:mx[mxtail+1]]) break;
			if(mnidx>=mxidx) ++mntail; if(mxidx>=mnidx) ++mxtail;
		}
		{
			int mnidx=mn[mntail],mxidx=mx[mxtail];
			int a=min(c[mnidx],v[mxidx]);
			if(mnidx!=i||mxidx!=i) {
				int b=min(c[mnidx<mxidx?mnidx:mn[mntail+1]],v[mxidx<mnidx?mxidx:mx[mxtail+1]]);
				dp[i]=max(a,b);
			} else {
				dp[i]=a;
			}
		}
		//printf("%d: %d\n",i,dp[i]);
	}

	sort(dp,dp+n);
	double ret=0,p=1;
	REP(i,n) {
		ret+=p*1.0*nq/(n-i)*dp[i];
		p*=1-1.0*nq/(n-i);
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}