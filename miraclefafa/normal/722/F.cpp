#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
map<int,int> s[50];
int n,m,t[N],x;
vector<PII> v[N];
void init() {
	rep(i,1,41) s[i].clear();
}
void add(int m,int v)  {
	s[m][v]++;
}
void del(int m,int v) {
	s[m][v]--;
	if (s[m][v]==0) s[m].erase(v);
}
ll Inv(ll q,ll m) {
	if (q==0) return 0;
	assert(q>=0);
	ll a1=m,b1=0,a2=q,b2=1,a3,b3,t;
	while (a2!=1) {	t=a1/a2,a3=a1-t*a2,b3=b1-(t*b2)%m,
		a1=a2,a2=a3,b1=b2,b2=b3;if (b2<0) b2+=m;}
	return b2;
}
ll merge(ll a,ll b,ll c,ll d) { // x=a (mod b) x=c (mod d)
	c-=a;
	ll dd=__gcd(b,d);
	if (c%dd!=0) return -1;
	b/=dd; c/=dd; d/=dd;
	ll t=c*Inv(b,d)%d;
	if (t<0) t+=d;
	return b*t*dd+a;
}
int pp,rr;
bool CRT(const vector<pair<ll,ll> > &d) { // x= d[i].fi (mod d[i].se)
	ll r=1,x=0;
	rep(i,0,SZ(d)) {
		x=merge(x,r,d[i].fi,d[i].se);
		if (x==-1) return 0;
		r=r/__gcd(r,d[i].se)*d[i].se;
	}
	return 1;
}
bool valid() {
	rep(i,1,41) if (SZ(s[i])>=2) return 0;
	vector<pair<ll,ll> > d;
	rep(i,1,41) if (SZ(s[i])) {
		d.pb(mp(s[i].begin()->fi,i));
	}
	return CRT(d);
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%d",t+i);
		rep(j,0,t[i]) {
			scanf("%d",&x);
			v[x].pb(mp(i,j));
		}
	}
	rep(i,1,m+1) {
		int l=0,ret=0;
		pp=i;
		rep(r,0,SZ(v[i])) {
			if (r==0||v[i][r].fi!=v[i][r-1].fi+1)  {
				l=r; init();
			}
			add(t[v[i][r].fi],v[i][r].se);
			while (!valid()) {
				del(t[v[i][l].fi],v[i][l].se);
				++l;
			}
			ret=max(ret,r-l+1);
		}
		printf("%d\n",ret);
	}
}