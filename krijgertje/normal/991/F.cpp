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

const ll LIM=10000000000LL;
struct SA { int p,x; ll val; int olen,nlen; SA(int p,int x,ll val,int olen,int nlen):p(p),x(x),val(val),olen(olen),nlen(nlen) {} };
bool operator<(const SA &a,const SA &b) { if(a.val!=b.val) return a.val<b.val; return a.nlen<b.nlen; }

ll mlt(ll a,ll b) { return a>LLONG_MAX/b?LLONG_MAX:a*b; }
ll inc(ll a,ll b) { return a>LLONG_MAX-b?LLONG_MAX:a+b; }
ll pw(int a,int b) { ll ret=1; REP(i,b) ret=mlt(ret,a); return ret; }

vector<SA> sa;
//map<ll,vector<SA> > mp;

int digits(ll x) { if(x==0) return 1; int ret=0; while(x>0) ++ret,x/=10; return ret; }


void gensa() {
	for(int p=2;(1LL<<p)<=LIM;++p) {
		//printf("p=%d\n",p);
		for(int x=2;;++x) {
			ll cur=1; REP(i,p) cur=mlt(cur,x); if(cur>LIM) break;
			int olen=digits(cur),nlen=digits(x)+1+digits(p);
			if(nlen<olen) sa.PB(SA(p,x,cur,olen,nlen));
			//printf("\tx=%d\n",x);
		}
	}
	sort(sa.begin(),sa.end());
	int nsa=0; REPSZ(i,sa) if(nsa==0||sa[i].val!=sa[nsa-1].val) sa[nsa++]=sa[i]; while(SZ(sa)>nsa) sa.pop_back();
	//REP(i,min(100,SZ(sa))) printf("%d^%d=%lld\n",sa[i].x,sa[i].p,sa[i].val);
	//REPSZ(i,sa) mp[sa[i].val].PB(sa[i]);
	//printf("SZ(sa)=%d\n",SZ(sa));
}

void solve(ll x) {
	vector<string> opt;
	FOR(a,1,10) FOR(b,1,10) FORE(c,1,10) FOR(d,1,10) FOR(e,1,10) {
		ll val1=mlt(mlt(a,pw(b,c)),pw(d,e)); if(val1==x) { char buff[20]; sprintf(buff,"%d*%d^%d*%d^%d",a,b,c,d,e); opt.PB(buff); }
		ll val2=inc(a,mlt(pw(b,c),pw(d,e))); if(val2==x) { char buff[20]; sprintf(buff,"%d+%d^%d*%d^%d",a,b,c,d,e); opt.PB(buff); }
		ll val3=inc(inc(a,pw(b,c)),pw(d,e)); if(val3==x) { char buff[20]; sprintf(buff,"%d+%d^%d+%d^%d",a,b,c,d,e); opt.PB(buff); }
		ll val4=inc(mlt(a,pw(b,c)),pw(d,e)); if(val4==x) { char buff[20]; sprintf(buff,"%d*%d^%d+%d^%d",a,b,c,d,e); opt.PB(buff); }
	}
	{ char buff[20]; sprintf(buff,"%lld",x); opt.PB(buff); }
	REPSZ(i,sa) if(sa[i].val==x) { char buff[20]; sprintf(buff,"%d^%d",sa[i].x,sa[i].p); opt.PB(buff); }
	REPSZ(i,sa) REP(j,i) {
		ll cur=mlt(sa[i].val,sa[j].val); if(cur>LIM) break;
		if(cur==x) { char buff[20]; sprintf(buff,"%d^%d*%d^%d",sa[j].x,sa[j].p,sa[i].x,sa[i].p); opt.PB(buff); }
	}
	REPSZ(i,sa) if(x%sa[i].val==0) {
		ll c=x/sa[i].val; char buff[20]; sprintf(buff,"%lld*%d^%d",c,sa[i].x,sa[i].p); opt.PB(buff);
	}
	REPSZ(i,sa) if(x>sa[i].val) {
		ll c=x-sa[i].val; char buff[20]; sprintf(buff,"%lld+%d^%d",c,sa[i].x,sa[i].p); opt.PB(buff);
	}
	{
		int l=0,r=SZ(sa)-1;
		while(l<=r) {
			ll cur=inc(sa[l].val,sa[r].val);
			if(cur==x) { char buff[20]; sprintf(buff,"%d^%d+%d^%d",sa[l].x,sa[l].p,sa[r].x,sa[r].p); opt.PB(buff); ++l,--r; } else if(cur<x) ++l; else --r;
		}
	}
	REPSZ(i,sa) if(sa[i].nlen==3) {
		FOR(c,1,1000) FOR(d,1,1000) {
			ll val=inc(mlt(c,sa[i].val),d); if(val==x) { char buff[20]; sprintf(buff,"%d*%d^%d+%d",c,sa[i].x,sa[i].p,d); opt.PB(buff); }
		}
	}
	REPSZ(i,sa) if(sa[i].nlen==4) {
		FOR(c,1,100) FOR(d,1,100) {
			ll val=inc(mlt(c,sa[i].val),d); if(val==x) { char buff[20]; sprintf(buff,"%d*%d^%d+%d",c,sa[i].x,sa[i].p,d); opt.PB(buff); }
		}
	}
	REPSZ(i,sa) if(sa[i].nlen==5) {
		FOR(c,1,10) FOR(d,1,10) {
			ll val=inc(mlt(c,sa[i].val),d); if(val==x) { char buff[20]; sprintf(buff,"%d*%d^%d+%d",c,sa[i].x,sa[i].p,d); opt.PB(buff); }
		}
	}
	//printf("SZ(opt)=%d\n",SZ(opt));
	//REPSZ(i,opt) printf("%s\n",opt[i].c_str());

	string ret=opt[0]; REPSZ(i,opt) if(SZ(opt[i])<SZ(ret)) ret=opt[i];
	printf("%s\n",ret.c_str());
}

void run() {
	ll x; scanf("%lld",&x);
	solve(x);

}

int main() {
	gensa();
	run();
	return 0;
}