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
int x[MAXN-1];

ll sum[MAXN];

int bmx[MAXN+1];
int bidx[MAXN+1];

int bget(int idx) {
	int ret=-1;
	for(++idx;idx>0;idx-=idx&-idx) {
		//printf("\t\tbget(%d) [%d,%d]\n",idx,bidx[idx],bmx[idx]);
		if(bidx[idx]!=-1&&(ret==-1||bmx[idx]>bmx[ret+1])) ret=bidx[idx];
	}
	return ret;
}
void bset(int idx,int val) {
	int oidx=idx;
	for(++idx;idx<=n;idx+=idx&-idx) {
		//printf("\t\tbset(%d,%d) [%d,%d]\n",idx,val,bidx[idx],bmx[idx]);
		if(bidx[idx]==-1||val>bmx[idx]) bmx[idx]=val,bidx[idx]=oidx;
	}
}

void run() {
	scanf("%d",&n); REP(i,n-1) scanf("%d",&x[i]),--x[i];

	ll ret=0;
	sum[n-1]=0;
	memset(bidx,-1,sizeof(bidx));
	for(int i=n-2;i>=0;--i) {
		sum[i]=n-i-1;
		if(x[i]!=n-1) {
			int j=bget(x[i]); // maximizes x[j] s.t. i+1<=j<=x[i] (x[j]>x[i])
			//printf("\t%d: %d\n",i,j);
			sum[i]+=sum[j]-(x[i]-j);
		}
		ret+=sum[i];
		//printf("%d = %lld\n",i,sum[i]);
		bset(i,x[i]);
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}