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
int a[MAXN];
int b[MAXN],nb;

int bit[MAXN+1];
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret=max(ret,bit[idx]); idx-=idx&-idx; } return ret; }
void bmod(int idx,int val) { ++idx; while(idx<=nb) { bit[idx]=max(bit[idx],val); idx+=idx&-idx; } }

int l[MAXN],r[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	REP(i,n) a[i]-=i;
	nb=0; REP(i,n) b[nb++]=a[i]; sort(b,b+nb); nb=unique(b,b+nb)-b; REP(i,n) a[i]=lower_bound(b,b+nb,a[i])-b;
	//printf("a:"); REP(i,n) printf(" %d",a[i]); puts("");

	memset(bit,0,sizeof(bit));
	REP(i,n) {
		int pos=a[i];
		l[i]=bget(pos)+1;
		bmod(pos,l[i]);
	}

	memset(bit,0,sizeof(bit));
	int ans=INT_MAX;
	for(int i=n-1;i>=0;--i) {
		if(i-1>=0) { // suppose we use i-1 and remove i
			int pos=a[i-1]==0||b[a[i-1]-1]<b[a[i-1]]-1?a[i-1]:a[i-1]-1; pos=nb-pos-1;
			int keep=l[i-1]+bget(pos);
			ans=min(ans,n-1-keep);
		}
		{ // suppose we remove i and don't use anything before
			int keep=bget(nb-1);
			ans=min(ans,n-1-keep);
		}
		{
			int pos=nb-a[i]-1;
			r[i]=bget(pos)+1;
			bmod(pos,r[i]);
		}
	}
	printf("%d\n",ans);
}

int main() {
	run();
	return 0;
}