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
const int MAXVAL=70;
const int MAXP=19; // 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67
const int MOD=1000000007;

vector<int> p;

int n;
int a[MAXN];
int mask[MAXN];

void gausselim() {
	//printf("before:"); REP(i,n) printf(" %x",mask[i]); puts("");
	int r=0,c=0;
	while(r<n&&c<SZ(p)) {
		{ int rr=r; while(rr<n&&(mask[rr]&(1<<c))==0) ++rr; if(rr>=n) { ++c; continue; } swap(mask[r],mask[rr]); }
		FOR(rr,r+1,n) if(mask[rr]&(1<<c)) mask[rr]^=mask[r];
		++r,++c;
	}
	//printf("after:"); REP(i,n) printf(" %x",mask[i]); puts("");
}


void run() {
	p.clear(); FORE(i,2,MAXVAL) { bool isp=true; for(int j=2;j*j<=i;++j) if(i%j==0) isp=false; if(isp) p.PB(i); }
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	REP(i,n) { mask[i]=0; int x=a[i]; REPSZ(j,p) if(x%p[j]==0) { int cnt=0; while(x%p[j]==0) x/=p[j],++cnt; if(cnt%2==1) mask[i]|=1<<j; } assert(x==1); }
	gausselim();
	int nfree=0; REP(i,n) if(mask[i]==0) ++nfree;
	int ret=1; REP(i,nfree) ret=(ll)2*ret%MOD; ret=(ret+MOD-1)%MOD; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}