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
const int MAXQ=100000;

int n,nq,seed,vmax;
int a[MAXN];
int qkind[MAXQ],ql[MAXQ],qr[MAXQ],qx[MAXQ],qy[MAXQ];
int rnd() { int ret=seed; seed=((ll)seed*7+13)%1000000007; return ret; }

map<int,ll> vals;

map<int,ll>::iterator ensure(int idx) {
	auto it=vals.lower_bound(idx);
	if(it->first==idx) return it;
	assert(it!=vals.begin()); --it;
	return vals.insert(MP(idx,it->second)).first;
}

void incby(int l,int r,int by) {
	auto lit=ensure(l),rit=ensure(r+1);
	for(auto it=lit;it!=rit;++it) it->second+=by;
}

void setval(int l,int r,int val) {
	auto lit=ensure(l),rit=ensure(r+1);
	lit->second=val;
	++lit; for(auto it=lit;it!=rit;it=lit) { ++lit; vals.erase(it); }
}

vector<pair<ll,int> > lst;
ll getkth(int l,int r,int k) {
	lst.clear();
	auto lit=ensure(l),rit=ensure(r+1);
	for(auto it=lit;it!=rit;++it) lst.PB(MP(it->second,next(it)->first-it->first));
	//printf("lst:"); REPSZ(i,lst) printf(" %lld=%d",lst[i].first,lst[i].second); puts("");
	sort(lst.begin(),lst.end());
	//printf("lst:"); REPSZ(i,lst) printf(" %lld=%d",lst[i].first,lst[i].second); puts("");
	int idx=0; while(idx<SZ(lst)&&k>=lst[idx].second) k-=lst[idx++].second; assert(idx<SZ(lst)); return lst[idx].first;
}

int pw(int x,int n,int mod) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%mod; if((n>>=1)==0) return ret; x=(ll)x*x%mod; } }
int getsum(int l,int r,int x,int mod) {
	int ret=0;
	auto lit=ensure(l),rit=ensure(r+1);
	for(auto it=lit;it!=rit;++it) ret=(ret+(ll)(next(it)->first-it->first)*pw(it->second%mod,x,mod))%mod;
	return ret;
}


void run() {
	scanf("%d%d%d%d",&n,&nq,&seed,&vmax);
	REP(i,n) a[i]=rnd()%vmax+1;
	REP(i,nq) { qkind[i]=rnd()%4+1; ql[i]=rnd()%n; qr[i]=rnd()%n; if(ql[i]>qr[i]) swap(ql[i],qr[i]); qx[i]=rnd()%(qkind[i]==3?qr[i]-ql[i]+1:vmax)+1; if(qkind[i]==4) qy[i]=rnd()%vmax+1; }
	//printf("a:"); REP(i,n) printf(" %d",a[i]); puts("");
	//REP(i,nq) printf("%d: %d %d %d %d %d\n",i,qkind[i],ql[i]+1,qr[i]+1,qx[i],qy[i]);

	REP(i,n) vals[i]=a[i]; vals[n]=0;
	REP(i,nq) {
		int l=ql[i],r=qr[i],x=qx[i],y=qy[i];
		if(qkind[i]==1) incby(l,r,x);
		if(qkind[i]==2) setval(l,r,x);
		if(qkind[i]==3) printf("%lld\n",getkth(l,r,x-1));
		if(qkind[i]==4) printf("%d\n",getsum(l,r,x,y));
		//printf("vals:"); for(auto it=vals.begin();it!=vals.end();++it) printf(" %d=%lld",it->first+1,it->second); puts("");
	}
}

int main() {
	run();
	return 0;
}