#include <bits/stdc++.h>
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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
 
const int N=35100;
int a[N],l[N],r[N],n;

struct pq {
	ll q[2*N];
	int sz=0;
	ll offset=0;
	void init(ll val) {
		sz=n+1;
		rep(i,0,sz) q[i]=-val;
	}
	ll top() {
		return -q[0]+offset;
	}
	void push(ll x) {
		q[sz++]=-(x-offset);
		push_heap(q,q+sz);
	}
	void shift(ll x) {
		offset+=x;
	}
	void pop() {
		pop_heap(q,q+sz); --sz;
	}
};

ll solve(ll t) {
	pq L,R;
	L.init(-t); R.init(t);
	ll key=abs(t);
	rep(i,0,n) {
		L.shift(a[i]-l[i]); R.shift(r[i]-a[i]);
		if (i!=n-1) {
			ll pL=L.top(),pR=R.top();
			if (pL>=0&&pR>=0) {
				L.push(0); R.push(0);
			} else if (pR<0) {
				key+=-pR;
				L.push(-pR); R.pop();
				R.push(0); R.push(0);
			} else {
				key+=-pL;
				R.push(-pL); L.pop();
				L.push(0); L.push(0);
			}
		}
	}
	L.shift(t); R.shift(-t);
	ll pL=L.top(),pR=R.top();
	if (pL>=0&&pR>=0) return key;
	if (pR<0) {
		int k=0;
		while (1) {
			R.pop();
			ll cR=R.top(); ++k;
			if (cR>=0) return key+k*(-pR);
			key+=k*(cR-pR); pR=cR;
		}
	} else {
		int k=0;
		while (1) {
			L.pop();
			ll cL=L.top(); ++k;
			if (cL>=0) return key+k*(-pL);
			key+=k*(cL-pL); pL=cL;
		}
	}
	assert(0);
	return 0;
}
 
int sa;
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d%d%d",a+i,l+i,r+i),sa+=a[i];
	int pL=-sa,pR=sa;
	while (pL+4<pR) {
		int fl=(pL+pR)/2,fr=fl+1;
		if (solve(fl)>solve(fr)) pL=fl;
		else pR=fr;
	}
	ll ans=1ll<<60;
	rep(i,pL,pR+1) {
		ans=min(ans,solve(i));
	}
	printf("%lld\n",ans);
}