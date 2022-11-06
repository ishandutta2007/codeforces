#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
vector<ll> cube;
ll getb(ll x) {
	ll ans=0;
	while(x>0) {
		ll imin=0,imax=cube.size();
		while(imin<imax) {
			ll imid=(imin+imax)/2;
			if (cube[imid]<x) imin=imid+1;
			else imax=imid;
		}
		if (cube[imin]>x) imin--;
		//printf("x:%lld ci:%lld imin:%lld\n",x,cube[imin],imin);
		x-=cube[imin];
		ans++;
	}
	return ans;
}

pll solve1(ll m) {
	ll x=0;
	ll b=0,r=0;
	map<ll,ll, greater<ll> > h;
	for (ll y=1;;y++) {
		ll y3=y*y*y;
		ll z=y+1;
		ll z3=z*z*z;
		if (y3>m) break;
		ll t=0;
		while(1) {
			ll w=t*y3+x;
			if (w<z3&&w<=m) t++;
			else break;
		}
		t--;
		if(t)h[y]=t;
		r=t*y3+x;
		b+=t;
		x=r;
	}
	while(1) {
		bool found=false;
		vector<ll> er;
		for (auto it=h.begin();it!=h.end();++it) {
			auto w=*it;
			ll y=w.first,c=w.second;
			//printf("y:%lld c:%lld\n",y,c);
			if (c==0) continue;
			ll y3=y*y*y;
			ll z=y+1;
			ll z3=z*z*z;
			ll nr=r-y3+z3;
			if (nr<=m&&getb(nr)==b) {
				//printf("r:%lld -> nr:%lld\n",r,nr);
				it->second--;
				if (c==1) er.PB(y);
				h[z]++;
				found=true;
				r=nr;
				break;
			}
		}
		for (auto &y:er) h.erase(y);
		//printf("found %d\n",found);
		if (!found) break;
	}
	return MP(b,r);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll m; scanf("%lld",&m);
	cube.clear();
	for (ll c=1;;c++) {
		ll c3=c*c*c;
		cube.PB(c3);
		if (c3>m) break;
	}
	/*if (m<=500) {
		pll best=MP(-1ll,-1ll);
		for (ll q=m;q>=1;q--) {
			chkmax(best,MP(getb(q),q));
		}
		printf("%lld %lld\n",best.first,best.second);
		return 0;
	}*/
	pll got1=solve1(m);
	printf("%lld %lld\n",got1.first,got1.second);
}