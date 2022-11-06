#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=2e5+2;
const ll PUSH=1,POP=0;
ll LEFT=0,RIGHT=1,NONE=-1;
struct SS {
   ll leftpop;
   ll rightpush;
   ll topstack;
};
typedef struct SS S;
S identity = {
	0,0,NONE
};
void ps(S a) {
	printf("(%d %d)",a.leftpop,a.rightpush);
}
S combine(S &a, S &b) {
  S c;
  ll match=min(a.rightpush,b.leftpop);
  c.leftpop=a.leftpop+b.leftpop-match;
  c.rightpush=b.rightpush+a.rightpush-match;
  if (b.topstack!=NONE) {
  	c.topstack=RIGHT;
  }
  else if (a.rightpush>b.leftpop) {
  	c.topstack=LEFT;
  }
  else c.topstack=NONE;
  //ps(a); ps(b); ps(c);
  //printf("\n");
  return c;
}
S t[2*mn];
void build(ll n) {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}
void modify(int p, const S& value, ll n) {
	//printf("modify p:%d\n",p);
    for (t[p += n] = value; p >>= 1; ) {
    	//printf("Writing to p:%d from %d %d\n",p,p<<1,(p<<1)|1);
    	t[p] = combine(t[p<<1], t[p<<1|1]);
    }
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll m; scanf("%d",&m);
	ll segn=1;
	while(segn<m) segn*=2;
	for (ll i=0;i<2*segn;i++) t[i]=identity;
	for (ll i=0;i<m;i++) {
		ll p,ty,valx;
		scanf("%d %d",&p, &ty);
		if (ty==PUSH) scanf("%d",&valx);
		S s;
		if (ty==PUSH) s={
			0,
			1,
			valx
		};
		else  s={
			1,
			0,
			-1
		};
		modify(p-1,s,segn);
		ll x=1;
		ll sumpops=0;
		ll final=0;
		while(x<segn) {
			//printf("x:%d ",x); ps(t[x]); printf("\n");
			//printf("Writing to x:%lld\n",x);
			//t[x]=combine(t[x<<1],t[(x<<1)|1]);
			ll rightpush=t[x].rightpush,leftpop=t[x].leftpop;
			//printf("x:%d leftpop:%d rightpush:%d sumpops:%lld\n",x,leftpop,rightpush,sumpops);
			if (t[x].rightpush>0) {
				// Go right
				ll leftchild=x<<1,rightchild=(x<<1)|1;
				//printf("%lld %lld\n",t[rightchild].rightpush,sumpops);
				ll onright=max(0,sumpops-t[rightchild].rightpush);
				onright+=t[rightchild].leftpop;
				if (t[rightchild].rightpush>sumpops) {
					//printf("Right\n");
					x=rightchild;
				}
				else if (t[leftchild].rightpush>onright) {
					//printf("Left\n");
					sumpops=onright;
					x=leftchild;
				}
				else {
					final=-1;
					break;
				}
			}
			else {
				final=-1;
				break;
			}
		}
		if (final!=-1) final=t[x].topstack;
		printf("%d\n",final);
	}
}