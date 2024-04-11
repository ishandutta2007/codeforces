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

const int MAXH=59;
const int MAXQLEN=100000;

ll n; int nq;
int h;

char q[MAXQLEN+1]; int qlen;

ll getid(ll x,ll rt,int h) { ll mid=1LL<<(h-1); if(x==mid) return rt; return x<mid?getid(x,2*rt,h-1):getid(x-mid,2*rt+1,h-1); }
ll getnr(ll id,int h) { ll ret=0; for(int i=h-1;i>=0;--i) { if(id<(1LL<<i)) continue; if(id%2==0) ret-=1LL<<(h-i-1); else ret+=1LL<<(h-i-1); id/=2; } return ret; }

void run() {
	scanf("%lld%d",&n,&nq);
	h=1; while((1LL<<h)<n+1) ++h; assert((1LL<<h)==n+1);
	//FOR(i,1,(1<<h)) printf("%d -> %lld -> %lld\n",i,getid(i,1,h),getnr(getid(i,1,h),h));
	REP(i,nq) { 
		ll x; scanf("%lld%s",&x,q); qlen=strlen(q);
		ll id=getid(x,1,h);
		REP(j,qlen) {
			bool isleaf=id>=(1LL<<(h-1));
			if(q[j]=='L'&&!isleaf) id=2*id+0;
			if(q[j]=='R'&&!isleaf) id=2*id+1;
			if(q[j]=='U'&&id!=1) id/=2;
		}
		ll ret=getnr(id,h); printf("%lld\n",ret);
	}
}

int main() {
	run();
	return 0;
}