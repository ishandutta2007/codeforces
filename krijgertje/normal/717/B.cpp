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

const int CMAX=1000;

int n,c0,c1;
int C[CMAX+1][CMAX+1];

// a*c0+b*c1<=c, a>=0,b>=0 -> sum C[a+b][a] for all possible (a,b)
int calccnt(ll c) {
	if(c0==0) return n;
	int ret=0;
	for(int b=0;(ll)b*c1<=c;++b) {
		ll mxa=(c-(ll)c1*b)/c0;
		if(ret+mxa+1>=n) return n;
		if(b==0) { ret+=mxa+1; continue; }
		if(ret+(mxa+2)*(mxa+1)/2>=n) return n;
		if(b==1) { ret+=(mxa+2)*(mxa+1)/2; continue; }
		if(ret+(mxa+1)*(mxa+2)*(mxa+3)/6>=n) return n;
		if(b==2) { ret+=(mxa+1)*(mxa+2)*(mxa+3)/6; continue; }
		assert(mxa+b<=CMAX);
		REPE(a,mxa) if((ret+=C[a+b][a])>=n) return n;
	}
	return ret;
}
ll calcsum(ll c) {
	ll ret=0;
	for(int b=0;(ll)b*c1<=c;++b) {
		ll mxa=(c-(ll)c1*b)/c0;
		if(b==0) { ret+=0*c1*(mxa+1)+c0*mxa*(mxa+1)/2; continue; }
		if(b==1) { ret+=1*c1*(mxa+2)*(mxa+1)/2+2*c0*mxa*(mxa+1)*(mxa+2)/6; continue; }
		if(b==2) { ret+=2*c1*(mxa+1)*(mxa+2)*(mxa+3)/6+3*c0*(mxa+3)*(mxa+2)*(mxa+1)*(mxa)/24; continue; }
		assert(mxa+b<=CMAX);
		REPE(a,mxa) ret+=C[a+b][a]*((ll)a*c0+(ll)b*c1);
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&n,&c0,&c1); if(c0>c1) swap(c0,c1);
	REPE(i,CMAX) { C[i][0]=C[i][i]=1; FOR(j,1,i) if((C[i][j]=C[i-1][j-1]+C[i-1][j])>=n) C[i][j]=n; }

	ll l=-1,h=(ll)(n-2)*min(c0,c1);
	while(l+1<h) {
		ll m=l+(h-l)/2;
		if(calccnt(m)>=n-1) h=m; else l=m;
	}
	ll splitmx=h;
	ll ret=(ll)(n-1)*(c0+c1);
	if(splitmx!=0) {
		ll cntmx=n-1-calccnt(splitmx-1);
		//printf("max splitcost = %lld (%lld times)\n",splitmx,cntmx);
		ret+=cntmx*splitmx;
		ret+=calcsum(splitmx-1);
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}