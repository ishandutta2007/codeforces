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
typedef struct R { int a,b,h; } R;
bool operator<(const R &p,const R &q) { if(p.b!=q.b) return p.b>q.b; return p.a>q.a; }

int n;
R r[MAXN];
int a[MAXN],na;

ll bit[MAXN+1];
ll bget(int idx) { ++idx; ll ret=0; while(idx>0) { ret=max(ret,bit[idx]); idx-=idx&-idx; } return ret; }
void bset(int idx,ll val) { ++idx; while(idx<=na) { bit[idx]=max(bit[idx],val); idx+=idx&-idx; } }

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d%d",&r[i].a,&r[i].b,&r[i].h);
	sort(r,r+n);
	na=0; REP(i,n) a[na++]=r[i].a; sort(a,a+na); na=unique(a,a+na)-a;
	memset(bit,0,sizeof(bit));
	REP(i,n) {
		int apos=lower_bound(a,a+na,r[i].a)-a; assert(apos<na&&a[apos]==r[i].a);
		int bpos=lower_bound(a,a+na,r[i].b-1)-a; if(bpos>=na||a[bpos]>=r[i].b) --bpos; assert(bpos>=0&&a[bpos]<r[i].b&&(bpos+1>=na||a[bpos+1]>=r[i].b));
		ll cur=bget(bpos);
		//printf("%d: %d,%d,%d -> apos=%d bpos=%d cur=%lld\n",i,r[i].a,r[i].b,r[i].h,apos,bpos,cur);
		cur+=r[i].h;
		bset(apos,cur);
	}
	ll ret=bget(na-1);
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}