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

int n,mod,cnt;
int a[MAXN];

void run() {
	scanf("%d%d%d",&n,&mod,&cnt);
	REP(i,n) scanf("%d",&a[i]);

	sort(a,a+n);
	int l2=0,r2=0; ll ret=0;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&a[l]==a[r]) ++r;
		int nxt=(a[l]+mod-1)/mod*mod;
		ll lbound,rbound;
		if(cnt==0) {
			lbound=a[l],rbound=nxt-1;
		} else {
			lbound=nxt+(ll)(cnt-1)*mod,rbound=lbound+mod-1;
		}
		while(l2<n&&a[l2]<lbound) ++l2;
		while(r2<n&&a[r2]<=rbound) ++r2;
		ret+=(ll)(r-l)*(r2-l2);
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}