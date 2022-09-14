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

const int MOD=1000000007;

int nq;


int calcrows(int k,int times,int mx,int have) {
	if(mx<=0) return 0;
	mx=min(mx,(1<<k));
	ll each=((ll)mx*(mx+1)/2+(ll)mx*have)%MOD;
	return (ll)times*each%MOD;
}

int calc(int x,int y,int mx,int have=0,int k=30) {
	if(mx<=0||x==0||y==0) return 0;
	ll ret=0;
	if(x>=(1<<k)&&(y>=(1<<k))) {
		ret+=calcrows(k,(1<<k),mx,have);
		ret+=calcrows(k,x-(1<<k),mx-(1<<k),have+(1<<k));
		ret+=calcrows(k,y-(1<<k),mx-(1<<k),have+(1<<k));
		ret+=calc(x-(1<<k),y-(1<<k),mx,have,k-1);
	} else if(x>=(1<<k)) {
		ret+=calcrows(k,y,mx,have);
		ret+=calc(x-(1<<k),y,mx-(1<<k),have+(1<<k),k-1);
	} else if(y>=(1<<k)) {
		ret+=calcrows(k,x,mx,have);
		ret+=calc(x,y-(1<<k),mx-(1<<k),have+(1<<k),k-1);
	} else {
		ret+=calc(x,y,mx,have,k-1);
	}
	//printf("calc(%d,%d,%d,%d,%d)=%lld\n",x,y,mx,have,k,ret);
	return ret%MOD;
}

void run() {
	scanf("%d",&nq);
	REP(qi,nq) {
		int lx,ly,hx,hy,mx; scanf("%d%d%d%d%d",&lx,&ly,&hx,&hy,&mx);
		ll cur=(ll)calc(hx,hy,mx)-calc(hx,ly-1,mx)-calc(lx-1,hy,mx)+calc(lx-1,ly-1,mx);
		cur=(cur%MOD+MOD)%MOD;
		printf("%lld\n",cur);
	}
}

int main() {
	run();
	return 0;
}