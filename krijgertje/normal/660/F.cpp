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
int x[MAXN];
ll sum[MAXN+1];
ll psum[MAXN+1];

int m;
int a[MAXN]; ll b[MAXN];

ll cmp(ll a,ll b,ll c,ll d) {
	if(a<0&&c<0) return cmp(-c,d,-a,b);
	if(a<0) return -1; if(c<0) return +1;
	while(true) {
		ll diff=a/b-c/d; if(diff!=0) return diff;
		a%=b; c%=d; if(a==0||c==0) return a-c;
		swap(a,d); swap(b,c);
	}
}

void add(int aa,ll bb) { // ax+b
	//printf("add(%d,%I64d)\n",aa,bb);
	//(bb-b[m-1])/(a[m-1]-aa) vs (b[m-1]-b[m-2])/(a[m-2]-a[m-1])
	while(m>=2&&cmp(bb-b[m-1],a[m-1]-aa,b[m-1]-b[m-2],a[m-2]-a[m-1])>=0) --m;
	a[m]=aa,b[m]=bb,++m;
	//REP(i,m) printf("\t%d*x+%lld\n",a[i],b[i]);
}
ll solve(ll x) {
	int l=-1,h=m-1;
	while(l+1<h) {
		int mid=l+(h-l)/2;
		//printf("\t%lld vs %lf\n",x,1.0*(b[mid+1]-b[mid])/(a[mid]-a[mid+1]));
		if(cmp(x,1,b[mid+1]-b[mid],a[mid]-a[mid+1])>=0) h=mid; else l=mid;
	}
	ll ret=a[h]*x+b[h];
	//printf("solve(%lld)=%lld (%d)\n",x,ret,h);
	return ret;
}

// s(a,b)=(psum(b+1)-psum(a))-a*(sum(b+1)-sum(a))=-a*sum[b+1]+a*sum[a]-psum[a]+psum[b+1]
void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+x[i];
	psum[0]=0; REP(i,n) psum[i+1]=psum[i]+(ll)(i+1)*x[i];
	//REP(i,n) FOR(j,i,n) printf("s(%d,%d)=%lld\n",i,j,(psum[j+1]-psum[i])-i*(sum[j+1]-sum[i]));

	ll ret=0; m=0;
	REP(i,n) {
		add(-i,i*sum[i]-psum[i]);
		ll cur=psum[i+1]+solve(sum[i+1]);
		//printf("->%lld\n",cur);
		if(cur>ret) ret=cur;
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}