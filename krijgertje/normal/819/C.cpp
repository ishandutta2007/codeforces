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

int nn[3],mm[3],ss[3];

map<int,int> factorize(int xx[3]) {
	map<int,int> ret; REP(i,3) { int x=xx[i]; for(int j=2;j*j<=x;++j) while(x%j==0) ++ret[j],x/=j; if(x!=1) ++ret[x]; } return ret;
}
map<int,int> gcd(map<int,int> a,map<int,int> b) {
	map<int,int> ret; for(auto it=a.begin();it!=a.end();++it) { int c=min(it->second,b[it->first]); if(c!=0) ret[it->first]=c; } return ret;
}
vector<ll> divisors(map<int,int> f) {
	if(SZ(f)==0) return vector<ll>(1,1);
	auto it=f.begin(); int times=it->second,val=it->first; f.erase(it);
	vector<ll> sub=divisors(f);
	vector<ll> ret;
	REPSZ(i,sub) { ll cur=sub[i]; ret.PB(cur); REP(i,times) { cur*=val; ret.PB(cur); } }
	return ret;
}

void rec(vector<ll> &cnt,vector<ll> &orig,int idx,vector<int> &cur,vector<int> &sz,vector<int> &szprod,int at,ll val) {
	if(at>=SZ(sz)) {
		//printf("\t%d\n",idx);
		cnt[idx]+=val;
	} else {
		rec(cnt,orig,idx,cur,sz,szprod,at+1,val);
		if(cur[at]+1<sz[at]) rec(cnt,orig,idx+szprod[at],cur,sz,szprod,at+1,-val);
	}
}

void run() {
	REP(i,3) scanf("%d",&nn[i]);
	REP(i,3) scanf("%d",&mm[i]);
	REP(i,3) scanf("%d",&ss[i]);
	ll n=(ll)nn[0]*nn[1]*nn[2];
	ll m=(ll)mm[0]*mm[1]*mm[2];
	ll s=(ll)ss[0]*ss[1]*ss[2];
	//printf("n=%lld m=%lld s=%lld\n",n,m,s);
	map<int,int> fs=factorize(ss); fs[2]++;
	vector<ll> ds=divisors(fs);
	map<int,int> fn=factorize(nn);

	ll ret=0;
	{
		vector<ll> out;
		for(auto it=fn.begin();it!=fn.end();++it) {
			ll now=1; REP(j,it->second) {  now*=it->first; if(2*s%now!=0) { out.PB(now); break; } }
		}
		REP(i,1<<SZ(out)) {
			int cnt=0; ll prod=1; REPSZ(j,out) if(i&(1<<j)) { ++cnt; prod*=out[j]; }
			if(cnt%2==0) ret+=m/prod; else ret-=m/prod;
		}
		//for(ll a=m;a>0;--a) if(2*s%gcd(a,n)==0) ++ret;
	}
	{
		REPSZ(i,ds) if(ds[i]<=n) ++ret;
		//for(ll b=n;b>0;--b) if(2*s%b==0) ++ret;
	}
	printf("%lld\n",ret);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}