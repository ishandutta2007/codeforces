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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

map<ll,ll> dp[20];
ll M=10004205361450474ll;
ll x;
ll count(int d,ll w) {
	if (d==1) return min(w,10000ll);
	if (w>=10000) {
		ll c=count(d-1,w);
		return c*10001+10000;
	} else {
		ll cw=count(d-1,w);
		rep(i,0,w) {
			cw++;
			cw+=count(d-1,w+cw);
		}
		return cw;
	}
}

int query(vector<ll> c) {
	printf("%d",SZ(c));
	rep(i,0,SZ(c)) {
		printf(" %lld",c[i]);
		assert(c[i]>=1&&c[i]<=M);
		assert(i==0||c[i]>c[i-1]);
	}
	puts("");
	fflush(stdout);
/*
	rep(i,0,SZ(c)) if (c[i]==x) return -1;
	rep(i,0,SZ(c)) if (x<c[i]) return i;
	return SZ(c);*/
	int y;
	scanf("%d",&y);
	return y;
}
void query(int d,ll w) {
	if (d==1) {
		int d=min(w,10000ll);
		vector<ll> c;
		rep(i,0,d) c.pb(w+i);
		assert(query(c)==-1);
		return;
	}
	if (w>=10000) {
		ll c=count(d-1,w);
		vector<ll> cc;
		ll x=c;
		rep(i,0,10000) {
			cc.pb(w+x);
			x+=c+1;
		}
		int y=query(cc);
		if (y==-1) return;
		if (y==0) return query(d-1,w);
		else return query(d-1,cc[y-1]+1);
	} else {
		vector<ll> cc;
		ll x=count(d-1,w);
		rep(i,0,w) {
			cc.pb(w+x);
			x++;
			x+=count(d-1,w+x);
		}
		int y=query(cc);
		if (y==-1) return;
		if (y==0) return query(d-1,w);
		else return query(d-1,cc[y-1]+1);		
	}
}

int main() {
//	printf("%lld\n",count(5,1));
//	x=10004205361450474ll;
	query(5,1);
}