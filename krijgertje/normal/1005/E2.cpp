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

const int MAXN=200000;

int n,want;
int val[MAXN];

int a[MAXN+1];
int b[MAXN+1];
int c[MAXN+1];
int d[MAXN+1];

pair<int,int> p[MAXN+1];

int bit[MAXN+2];
int bget(int idx) { ++idx; int ret=0; while(idx<=n+1) { ret+=bit[idx]; idx+=idx&-idx; } return ret; }
void bmod(int idx,int by) { ++idx; while(idx>0) { bit[idx]+=by; idx-=idx&-idx; } }

void run() {
	scanf("%d%d",&n,&want); REP(i,n) scanf("%d",&val[i]);

	a[0]=b[0]=c[0]=0; REP(i,n) a[i+1]=a[i]+(val[i]<want?1:0),b[i+1]=b[i]+(val[i]>want?1:0),c[i+1]=c[i]+(val[i]==want?1:0);
	REPE(i,n) d[i]=b[i]-a[i];
	
	REPE(i,n) p[i]=MP(c[i]-d[i],c[i]+d[i]);
	sort(p,p+n+1);
	int ymn=p[0].second,ymx=p[0].second; REPE(i,n) ymn=min(ymn,p[i].second),ymx=max(ymx,p[i].second);
	REPE(i,n) p[i].second-=ymn; ymx-=ymn; assert(ymx<=n);

	ll ret=0;
	memset(bit,0,sizeof(bit));
	for(int i=n;i>=0;--i) {
		ret+=bget(p[i].second+1);
		bmod(p[i].second,+1);
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}