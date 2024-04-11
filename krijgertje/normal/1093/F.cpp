#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MOD=998244353;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n,nalph,len;
int a[MAXN];

int prv[MAXN+1];
int ways1[MAXN+1]; // ways1[i] = number of ways to fill in numbers for [i..n) with no restrictions
int ways2[MAXN+1]; // ways2[i] = number of ways to fill in numbers for [i..n) with the first number not equal to prv[i]

int nxtidx[MAXN]; // nxtidx[i] = first idx >= i such that a[idx]!=-1
int nxtidx2[MAXN]; // nxtidx2[i] = first idx >= i such that a[idx]!=-1&&a[idx]!=a[nxtidx[i]]

int w1sum[MAXN+1];
int w2sum[MAXN+1];

int ways1sum(int l,int r) {
	//int ret=0; FORE(i,l,r) inc(ret,ways1[i]); return ret;
	return (w1sum[l]+MOD-w1sum[r+1])%MOD;
}
int ways2sum(int l,int r) {
	//int ret=0; FORE(i,l,r) inc(ret,ways2[i]); return ret;
	return (w2sum[l]+MOD-w2sum[r+1])%MOD;
}

int solve() {
	prv[0]=-1; FORE(i,1,n) prv[i]=a[i-1]!=-1?a[i-1]:prv[i-1];

	for(int i=n-1;i>=0;--i) {
		nxtidx[i]=a[i]!=-1?i:i+1<n?nxtidx[i+1]:-1;
		nxtidx2[i]=i+1>=n||nxtidx[i+1]==-1?-1:a[i]==-1||a[i]==a[nxtidx[i+1]]?nxtidx2[i+1]:nxtidx[i+1];
	}

	w1sum[n]=w2sum[n]=0;
	for(int i=n-1;i>=0;--i) {
		ways1[i]=ways2[i]=0; int val=a[i];

		if(n<i+len) {
			if(nxtidx[i]==-1) inc(ways1[i],nalph),inc(ways2[i],prv[i]==-1?nalph:nalph-1);
			if(nxtidx[i]!=-1&&nxtidx2[i]==-1) inc(ways1[i],1),inc(ways2[i],a[nxtidx[i]]!=prv[i]?1:0);
		}
		int la=i+1,ra=min(min(n-1,i+len-1),nxtidx[i]==-1?INT_MAX:nxtidx[i]);
		inc(ways1[i],(ll)ways1sum(la,ra)*(nalph-1)%MOD);
		inc(ways2[i],(ll)ways2sum(la,ra)*max(0,nalph-2)%MOD);
		inc(ways2[i],(ll)(ways1sum(la,ra)+MOD-ways2sum(la,ra))*(nalph-1)%MOD);
		if(nxtidx[i]!=-1&&nxtidx[i]+1<n&&nxtidx[i]+1<i+len) {
			int lb=nxtidx[i]+1,rb=min(min(n-1,i+len-1),nxtidx2[i]==-1?INT_MAX:nxtidx2[i]);
			inc(ways1[i],ways2sum(lb,rb));
			if(a[nxtidx[i]]!=prv[i]) inc(ways2[i],ways2sum(lb,rb));

		}
		w1sum[i]=(ways1[i]+w1sum[i+1])%MOD;
		w2sum[i]=(ways2[i]+w2sum[i+1])%MOD;
		//printf("%d: prv=%d ways1=%d ways2=%d\n",i,prv[i],ways1[i],ways2[i]);
	}
	return ways1[0];
}

void run() {
	scanf("%d%d%d",&n,&nalph,&len);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}