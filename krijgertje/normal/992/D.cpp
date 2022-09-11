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

int n,want;
int a[MAXN];

int b[MAXN],nb;

void run() {
	scanf("%d%d",&n,&want); REP(i,n) scanf("%d",&a[i]);

	nb=0; REP(i,n) if(a[i]!=1) b[nb++]=i;
	ll ret=0;
	if(want==1) {
		for(int l=0,r=l;l<n;l=r) {
			while(r<n&&a[l]==a[r]) ++r;
			int cnt=r-l;
			if(a[l]==1) ret+=cnt;
		}
	}
	REP(i,nb) {
		int j=i;
		ll prod=a[b[j]],sum=a[b[j]];
		while(true) {
			ll num=prod-want*sum,den=want;
			//printf("%d..%d -> %lld/(%lld+x)=%d => %lld/%lld\n",b[i],b[j],prod,sum,want,num,den);
			if(num>=0&&num/den>n) break;
			if(num%den==0) {
				ll need=num/den,have=(b[j]-b[i])-(j-i),extra1=(i==0?b[i]:b[i]-b[i-1]-1),extra2=(j==nb-1?n-b[j]-1:b[j+1]-b[j]-1);
				//printf("\tneed=%lld have=%lld extra1=%lld extra2=%lld\n",need,have,extra1,extra2);
				if(need>=have&&need<=have+extra1+extra2) {
					ll rem=need-have;
					ll mn1=max(0LL,rem-extra2),mx1=min(extra1,rem);
					assert(mn1<=mx1); ret+=mx1-mn1+1;
				}
			}
			if(j==nb-1) break;
			++j; prod*=a[b[j]],sum+=a[b[j]];
		}
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}