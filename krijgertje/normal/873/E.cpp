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

const int MAXN=3000;
typedef struct R { int val,id; } R;
bool operator<(const R &a,const R &b) { if(a.val!=b.val) return a.val>b.val; return a.id<b.id; }
typedef struct Opt { int na,nb,mn,mx; Opt() {} Opt(int na,int nb,int mn,int mx):na(na),nb(nb),mn(mn),mx(mx) {} } Opt;

int n;
int a[MAXN];

R r[MAXN];
int d[MAXN+1];

int ways[MAXN+2];

int ret[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	REP(i,n) r[i].val=a[i],r[i].id=i; sort(r,r+n);
	REP(i,n) d[i+1]=r[i].val-(i+1>=n?0:r[i+1].val);
	
	int besta=INT_MIN,bestb=INT_MIN; vector<Opt> opt;
	FORE(na,1,n) FORE(nb,1,n-na) {
		if(na>2*nb||nb>2*na) continue;
		int mn=max((na+1)/2,(nb+1)/2);
		int mx=min(2*min(na,nb),n-na-nb);
		if(mn>mx) continue;
		int a=d[na],b=d[na+nb];
		if(a<besta||a==besta&&b<bestb) continue;
		if(a>besta||a==besta&&b>bestb) besta=a,bestb=b,opt.clear();
		opt.PB(Opt(na,nb,mn,mx));
	}
	//printf("besta=%d bestb=%d opt=",besta,bestb); REPSZ(i,opt) printf(" (%d,%d,%d..%d)",opt[i].na,opt[i].nb,opt[i].mn,opt[i].mx); puts("");

	memset(ways,0,sizeof(ways));
	REPSZ(i,opt) ++ways[opt[i].na+opt[i].nb+opt[i].mn],--ways[opt[i].na+opt[i].nb+opt[i].mx+1];
	REPE(i,n) ways[i+1]+=ways[i];
	int bestc=INT_MIN,anssum=-1; REPE(i,n) if(ways[i]>0&&d[i]>bestc) bestc=d[i],anssum=i;
	int ansna=-1,ansnb=-1,ansnc=-1; REPSZ(i,opt) if(opt[i].na+opt[i].nb+opt[i].mn<=anssum&&anssum<=opt[i].na+opt[i].nb+opt[i].mx) { ansna=opt[i].na,ansnb=opt[i].nb,ansnc=anssum-ansna-ansnb; break; }

	REP(i,n) ret[i]=-1; REP(i,ansna) ret[r[i].id]=1; REP(i,ansnb) ret[r[ansna+i].id]=2; REP(i,ansnc) ret[r[ansna+ansnb+i].id]=3;
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}