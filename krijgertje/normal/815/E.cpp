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

ll n,want;

pair<ll,ll> calcdst(ll len,ll idx) {
	ll cnt=1,cntplus=0;
	while(true) {
		//printf("len=%lld cnt=%lld cntplus=%lld\n",len,cnt,cntplus);
		if(len%2==0) {
			if(idx<cntplus) return MP(len/2,idx); else idx-=cntplus;
			if(len==2) cnt=2*cnt+2*cntplus;
			if(idx<cnt) return MP((len-1)/2,idx); else idx-=cnt;
		} else {
			if(idx<cnt+cntplus) return MP((len-1)/2,idx); else idx-=cnt+cntplus;
		}
		ll nlen=(len-1)/2; ll ncnt=0,ncntplus=0;
		if(2*nlen+1==len) ncnt+=2*cnt+cntplus,ncntplus=cntplus; else ncnt=cnt,ncntplus=cnt+2*cntplus;
		if(nlen==1) ncnt+=2*ncntplus,ncntplus=0;
		len=nlen,cnt=ncnt,cntplus=ncntplus;
	}
}

map<ll,ll> mem;
ll cnt(ll len,ll dst) {
	if(len==0||len<dst) return 0;
	if(mem.count(len)) return mem[len];
	ll ret=0,l=(len-1)/2,r=len/2;
	if(l==dst) ret+=1; ret+=cnt(l,dst)+cnt(r,dst);
	//printf("cnt(%lld,%lld)=%lld\n",len,dst,ret);
	return mem[len]=ret;
}
ll go(ll at,ll len,ll dst,ll idx) {
	ll l=(len-1)/2,r=len/2;
	if(l==dst) if(idx==0) return at+l; else --idx;
	ll nl=cnt(l,dst); return idx<nl?go(at,l,dst,idx):go(at+l+1,r,dst,idx-nl);
}

ll solve() {
	if(want==0) return 0;
	if(want==1) return n-1;

	pair<ll,ll> dst=calcdst(n-2,want-2);
	//printf("n=%lld want=%lld -> dst=%lldth %lld\n",n,want,dst.second,dst.first);
	mem.clear();
	return go(1,n-2,dst.first,dst.second);
}

void run() {
	scanf("%lld%lld",&n,&want); --want;
	printf("%lld\n",solve()+1);
}

vector<ll> bf() {
	vector<ll> ret(n); ret[0]=0,ret[1]=n-1; int at=2;
	priority_queue<pair<ll,pair<ll,ll> > > q; q.push(MP((ll)(n-3)/1,MP(-1LL,(ll)n-2)));
	while(at<n) {
		assert(!q.empty());
		ll dst=q.top().first,a=-q.top().second.first,b=q.top().second.second; q.pop();
		ll len=b-a+1; ll l=(len-1)/2,r=len/2;
		ret[at++]=a+l;
		//printf("%d=%lld [dst=%lld,a=%lld,b=%lld]\n",at,a+l,dst,a,b);
		if(l>0) q.push(MP((l-1)/2,MP(-a,a+l-1))); if(r>0) q.push(MP((r-1)/2,MP(-(a+l+1),a+l+r)));
	}
	assert(SZ(q)==0);
	return ret;
}

void stress() {
	int nerr=0;
	for(n=3;;++n) {
		vector<ll> res=bf();
		for(want=0;want<n;++want) {
			ll ret=solve();
			ll chk=res[want];
			if(ret!=chk) { printf("n=%lld want=%lld: ret=%lld chk=%lld\n",n,want+1,ret,chk); ++nerr; if(nerr>10) return; }
		}
	}

}

int main() {
	run();
	//stress();
	return 0;
}