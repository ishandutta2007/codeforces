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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=501000;
int n,h[N],b[N];
ll dp[N];

struct node {
	ll fg,mx;
}nd[4*N];
void upd(int p) {
	nd[p].mx=max(nd[p+p].mx,nd[p+p+1].mx);
}
void setf(int p,ll v) {
	nd[p].fg+=v;
	nd[p].mx+=v;
}

void push(int p) {
	if (nd[p].fg) {
		setf(p+p,nd[p].fg);
		setf(p+p+1,nd[p].fg);
		nd[p].fg=0;
	}
}
ll query(int p,int l,int r,int tl,int tr) {
	if (tl==l&&tr==r) return nd[p].mx;
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return max(query(p+p,l,md,tl,md),query(p+p+1,md+1,r,md+1,tr));
	}
}
void modify(int p,int l,int r,int tl,int tr,ll v) {
	if (tl>tr) return;
	if (tl==l&&tr==r) return setf(p,v);
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,v);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,v);
		else modify(p+p,l,md,tl,md,v),modify(p+p+1,md+1,r,md+1,tr,v);
		upd(p);
	}
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",h+i);
	rep(i,1,n+1) scanf("%d",b+i);
	stack<array<int,4>> st;
	st.push({0,0,0,0});
	for (int i=1;i<=n;i++) {
		int l=i;
		while (!st.empty()&&st.top()[0]>h[i]) {
			int L=st.top()[1],R=st.top()[2];
			l=L;
			modify(1,1,n,L,R,-st.top()[3]);
			st.pop();
		}
		st.push({h[i],l,i,b[i]});
		modify(1,1,n,l,i,b[i]);
		dp[i]=query(1,1,n,1,i);
		if (i!=n) modify(1,1,n,i+1,i+1,dp[i]);
		//printf("dd %d %lld\n",i,dp[i]);
	}
	printf("%lld\n",dp[n]);
}