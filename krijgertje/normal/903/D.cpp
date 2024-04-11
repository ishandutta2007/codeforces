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

ll sum[MAXN+1];
int bcnt[MAXN+1];
ll bsum[MAXN+1];
pair<int,int> o[MAXN];

void bmod(int idx,int by) { ++idx; while(idx<=n) { ++bcnt[idx]; bsum[idx]+=by; idx+=idx&-idx; } }
pair<int,ll> bget(int idx) { ++idx; pair<int,ll> ret=MP(0,0LL); while(idx>0) { ret.first+=bcnt[idx]; ret.second+=bsum[idx]; idx-=idx&-idx; } return ret; }

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	//n=MAXN; REP(i,n) a[i]=i<n/2?1000000000:1;

	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+a[i];
	REP(i,n) o[i]=MP(a[i],i); sort(o,o+n);
	ull pos=0,neg=0;

	// sum(aj-ai|i<=j&&ai<=aj-2)
	memset(bcnt,0,sizeof(bcnt)); memset(bsum,0,sizeof(bsum));
	for(int k=0,at=0;k<n;++k) {
		int j=o[k].second;
		while(at<n&&o[at].first<=a[j]-2) bmod(o[at].second,o[at].first),++at;
		pair<int,ll> cur=bget(j);
		pos+=(ll)cur.first*a[j]; neg+=cur.second;
	}

	// sum(aj-ai|i<=j&&ai>=aj+2)
	memset(bcnt,0,sizeof(bcnt)); memset(bsum,0,sizeof(bsum));
	for(int k=n-1,at=n-1;k>=0;--k) {
		int j=o[k].second;
		while(at>=0&&o[at].first>=a[j]+2) bmod(o[at].second,o[at].first),--at;
		pair<int,ll> cur=bget(j);
		pos+=(ll)cur.first*a[j]; neg+=cur.second;
	}

	if(pos>=neg) printf("%llu\n",pos-neg); else printf("-%llu\n",neg-pos);
}

int main() {
	run();
	return 0;
}