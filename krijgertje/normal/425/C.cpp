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

int na,nb,have,cost;
int a[100000];
int b[100000];
int fst[100001],cnt[100001];
int c[100000];
bool bcmp(const int &p,const int &q) { if(b[p]!=b[q]) return b[p]<b[q]; return p<q; }

int findb(int val,int minidx) {
	if(cnt[val]==0||c[fst[val]+cnt[val]-1]<minidx) return -1;
	int l=fst[val]-1,h=fst[val]+cnt[val]-1; // (l,h]
	while(l+1<h) {
		int m=(l+h)/2;
		int cidx=c[m];
		if(c[m]<minidx) l=m; else h=m;
	}
	return c[h];
}

int dp[301]; // dp[i]=first available idx in b if we make i dollars before

void run() {
	scanf("%d%d%d%d",&na,&nb,&have,&cost);
	REP(i,na) scanf("%d",&a[i]);
	REP(i,nb) scanf("%d",&b[i]);
	REP(i,nb) c[i]=i; sort(c,c+nb,bcmp);
	memset(cnt,0,sizeof(cnt));
	REP(i,nb) cnt[b[i]]++;
	for(int i=nb-1;i>=0;--i) fst[b[c[i]]]=i;
	//REP(i,100) if(cnt[i]!=0) printf("%d: %d (%d)\n",i,cnt[i],fst[i]);

	int ret=0;
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	REP(i,na) {
		for(int j=299;j>=0;--j) if(dp[j]!=-1) {
			int bi=findb(a[i],dp[j]);
			//printf("%d,%d [%d] -> %d\n",i,j,dp[j],bi);
			if(bi==-1) continue;
			if(dp[j+1]==-1||bi+1<dp[j+1]) {
				dp[j+1]=bi+1;
				if(j+1>ret&&cost*(j+1)+(bi+1)+(i+1)<=have) ret=j+1;
			}
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}