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

typedef struct G {
	ll len;
	map<ll,ll> hor,ver;

	void init(ll _len) {
		len=_len; hor.clear(); ver.clear(); hor[0]=0; ver[0]=0;
		//printf("init:"); for(auto it=hor.begin();it!=hor.end();++it) printf(" (%lld,%lld)",it->first,it->second); puts("");
	}
	void resize(ll _len) {
		len=_len; auto it=hor.lower_bound(len); while(it!=hor.end()) { ver.erase(it->second); auto prv=it++; hor.erase(prv); }
		//printf("resize(%lld):",_len); for(auto it=hor.begin();it!=hor.end();++it) printf(" (%lld,%lld)",it->first,it->second); puts("");
	}
	void update(ll x,ll y) {
		//printf("updating(%lld,%lld)\n",x,y);
		ll sx,py,ny,nx; auto it=ver.lower_bound(y); py=it==ver.end()?LLONG_MAX:it->first; if(it==ver.begin()) return; --it; sx=it->second; if(sx>x) return;
		while(it!=ver.begin()&&it->second<=x) { ny=it->first; hor.erase(it->second); auto prv=it--; ver.erase(prv); }
		if(it==ver.begin()&&it->second<=x) { ny=it->first; hor.erase(it->second); ver.erase(it); nx=len; } else nx=it->second;
		if(y!=py) hor[sx]=y,ver[y]=sx;
		if(x+1!=nx) hor[x+1]=ny,ver[ny]=x+1;
		//printf("update(%lld,%lld):",x,y); for(auto it=hor.begin();it!=hor.end();++it) printf(" (%lld,%lld)",it->first,it->second); puts("");
	}
	vector<pair<ll,ll> > getfrom(ll x) {
		vector<pair<ll,ll> > ret;
		auto it=hor.lower_bound(x); if(it==hor.end()||it->first>x) --it;
		ret.PB(MP(x,it->second)); ++it; while(it!=hor.end()) { ret.PB(MP(it->first,it->second)); ++it; }
		ret.PB(MP(len,0LL));
		//printf("getfrom(%lld):",x); REPSZ(i,ret) printf(" (%lld,%lld)",ret[i].first,ret[i].second); puts("");
		return ret;
	}
	ll calc(int mlt) {
		ll ret=LLONG_MIN;
		for(auto it=hor.begin();it!=hor.end();++it) {
			ll y=it->second; auto nxt=it; ++nxt; ll x=nxt==hor.end()?len-1:nxt->first-1;
			//printf("x=%lld y=%lld\n",x,y);
			ll cur=y+x*mlt; if(cur>ret) ret=cur;
		}
		return ret;
	}
	void print(int a) {
		printf("hor%d:",a); for(auto it=hor.begin();it!=hor.end();++it) printf(" (%lld,%lld)",it->first,it->second); puts("");
		printf("ver%d:",a); for(auto it=ver.begin();it!=ver.end();++it) printf(" (%lld,%lld)",it->first,it->second); puts("");
	}



	
	/*vector<ll> val;
	void init(ll _len) { len=_len; val=vector<ll>(len,0); }
	void resize(ll _len) { len=_len; while(SZ(val)>len) val.pop_back(); }
	void update(ll x,ll y) { REPE(xx,x) val[xx]=max(val[xx],y); }
	vector<pair<ll,ll> > getfrom(ll x) {
		vector<pair<ll,ll> > ret;
		ret.PB(MP(x,val[x]));
		FORSZ(xx,x+1,val) if(val[xx]!=val[xx-1]) ret.PB(MP(xx,val[xx]));
		ret.PB(MP(len,0));
		return ret;
	}
	ll calc(int mlt) { ll ret=LLONG_MIN; REPSZ(i,val) ret=max(ret,val[i]+(ll)i*mlt); return ret; }
	void print(int a) { printf("%d:",a); REPSZ(i,val) printf(" %lld",val[i]); puts(""); }
	*/

} G;

int n;
ll a[MAXN];

G g;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%lld",&a[i]);
	g.init(a[0]);
	FOR(i,1,n) if(a[i]<g.len) {
		vector<pair<ll,ll> > p=g.getfrom(a[i]);
		g.resize(a[i]);
		FORSZ(j,1,p) {
			ll px=p[j-1].first,x=p[j].first-1,y=p[j-1].second;
			g.update(x%a[i],y+(x/a[i])*i*a[i]);
			if(px/a[i]!=x/a[i]) g.update(a[i]-1,y+((x/a[i])-1)*i*a[i]);
		}
		//g.print(i);
	}
	ll ret=g.calc(n);
	printf("%lld\n",ret);

	/*vector<ll> best(a[0],0); REPSZ(j,best) best[j]+=j;
	FOR(i,1,n) {
		if(a[i]>=SZ(best)) {
			REPSZ(j,best) best[j]+=j;
		} else {
			vector<ll> nbest(a[i],0); REPSZ(j,best) { int nj=j%a[i]; nbest[nj]=max(nbest[nj],best[j]+nj); } best=nbest;
		}
		printf("%d:",i); ll prv=LLONG_MIN; REPSZ(j,best) { ll cur=best[j]-(i+1)*j; if(cur!=prv) printf(" (%lld,%lld)",(ll)j,cur); prv=cur; } puts("");
	}*/
}

int main() {
	run();
	return 0;
}