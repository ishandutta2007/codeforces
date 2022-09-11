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

const int MAXN=500000;

int n,mnsz,mxdiff;
int a[MAXN];

bool ok[MAXN+1];

int bit[MAXN+2];
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
void bmod(int idx,int by) { ++idx; while(idx<=n+1) { bit[idx]+=by; idx+=idx&-idx; } }

bool solve() {
	sort(a,a+n);
	//printf("a:"); REP(i,n) printf(" %d",a[i]); printf(" mnsz=%d mxdiff=%d\n",mnsz,mxdiff);
	memset(bit,0,sizeof(bit));
	ok[n]=true; bmod(n,+1);
	int r=n-1;
	for(int i=n-1;i>=0;--i) {
		ok[i]=false;
		while(a[r]-a[i]>mxdiff) --r;
		int l=i+mnsz;
		// [i..r] can be in same box -> [l..r+1] can be first of next box
		if(l<=r+1) {
			int cnt=bget(r+1)-bget(l-1);
			//printf("%d: [%d..%d] -> [%d..%d] -> %d\n",i,i,r,l,r+1,cnt);
			ok[i]=cnt>0;
			if(ok[i]) bmod(i,+1);
		}
	}
	return ok[0];
}

void run() {
	scanf("%d%d%d",&n,&mnsz,&mxdiff); REP(i,n) scanf("%d",&a[i]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}