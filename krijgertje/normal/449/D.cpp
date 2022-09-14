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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

// ret = #sets for which a[i1]&a[i2]&...&a[ik]=0
// f(x) = #sets for which a[i1]&a[i2]&...&a[ik]&x=x
// ret=sum(f(x)*(-1)^bitcnt(x))
// g(x) = #items for which a[i]&x=x
// f(x) = 2^g(x)-1
// hk(y,x) = #items for which (a[i]>>(20-k))=y && a[i]&x=x		y<(1<<(20-k)),x<(1<<k)
// g(x)=h20(0,x)
// h0(y,0) = #items for which a[i]=y
// hk(y,x) = h{k-1}(y,x)+h{k-1}(y+(1<<(k-1)),x)					x<(1<<(k-1))
//         = h{k-1}(y+(1<<(k-1)),x-(1<<(k-1)))					x>=(1<<(k-1))


const int MOD=1000000007;

int n;
int a[1000000];
int p2[1000000];
int cnt[1<<20];
int h[1<<20];

void calc(int k,int y) {
	if(k==0) { h[y]=cnt[y]; return; }
	calc(k-1,y); calc(k-1,y+(1<<(k-1)));
	REP(i,1<<(k-1)) h[y+i]+=h[y+i+(1<<(k-1))];
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	memset(cnt,0,sizeof(cnt));
	REP(i,n) ++cnt[a[i]];
	p2[0]=1; FORE(i,1,n) { p2[i]=p2[i-1]+p2[i-1]; if(p2[i]>=MOD) p2[i]-=MOD; }
	calc(20,0);
	int ret=0;
	REP(i,1<<20) {
		int g=h[i];
		int f=p2[g]-1; if(f<0) f+=MOD;
		int sign=+1; REP(j,20) if(i&(1<<j)) sign=-sign;
		if(sign==+1) { ret=ret+f; if(ret>=MOD) ret-=MOD; } else { ret=ret-f; if(ret<0) ret+=MOD; }
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}