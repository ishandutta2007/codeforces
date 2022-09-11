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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MOD=998244353;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }
const int MAXN=300000;
struct C { int a,b; };
bool operator<(const C &x,const C &y) { if(x.a!=y.a) return x.a<y.a; return x.b<y.b; }
bool operator==(const C &x,const C &y) { return x.a==y.a&&x.b==y.b; }

int n;
int a[MAXN];
int b[MAXN];
C c[MAXN];

int fac[MAXN+1];

int solve() {
	fac[0]=1; FORE(i,1,n) fac[i]=(ll)fac[i-1]*i%MOD;
	sort(a,a+n); int aways=1; for(int l=0,r=l;l<n;l=r) { while(a[r]==a[l]) ++r; aways=(ll)aways*fac[r-l]%MOD; }
	sort(b,b+n); int bways=1; for(int l=0,r=l;l<n;l=r) { while(b[r]==b[l]) ++r; bways=(ll)bways*fac[r-l]%MOD; }
	sort(c,c+n);
	int abways=1; REP(i,n-1) if(c[i].a>c[i+1].a||c[i].b>c[i+1].b) abways=0;
	if(abways==1) for(int l=0,r=l;l<n;l=r) { while(c[r]==c[l]) ++r; abways=(ll)abways*fac[r-l]%MOD; }
	int ret=fac[n];
	dec(ret,aways);
	dec(ret,bways);
	inc(ret,abways);
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&c[i].a,&c[i].b),a[i]=c[i].a,b[i]=c[i].b;
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}