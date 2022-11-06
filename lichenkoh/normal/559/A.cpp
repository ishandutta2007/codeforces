#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
ld shoelace(vector<pld> ch) {
	ll n=ch.size();
	if (n<=2) return 0;
	ld ans=0;
	for (ll i=0;i<n;i++) {
		ans+=ch[i].fst*ch[(i+1)%n].snd;
		ans-=ch[i].fst*ch[(i-1+n)%n].snd;
	}
	ans=fabs(ans)/2;
	return ans;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ld vlen[6];
	for (ll i=0;i<6;i++) cin>>vlen[i];
	ld x=0,y=0;
	ld deg=0;
	vector<pld> v;
	for (ll i=0;i<6;i++) {
		ld len=vlen[i];
		ld dx=len*cos(deg);
		ld dy=len*sin(deg);
		x+=dx;
		y+=dy;
		//printf("x:%f y:%f\n",x,y);
		v.PB(MP(x,y));
		deg+=60.0*4.0*atan(1.0)/180.0;
	}
	ld area=shoelace(v);
	ld denom=sqrt(3)/4;
	//printf("area:%f\n denom%f\n",area,denom);
	ld ans=area/denom;
	ll final=round(ans);
	printf("%lld\n",final);
}