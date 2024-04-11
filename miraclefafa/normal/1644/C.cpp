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

const int N=5010;
const int inf=1e9;
int n,x,a[N],ret[N],seg[N];
void solve() {
	scanf("%d%d",&n,&x);
	rep(i,1,n+1) {
		scanf("%d",a+i);
		ret[i]=0;
	}
	ret[0]=0;
	rep(i,0,n+1) seg[i]=-inf;
	rep(i,1,n+1) {
		int s=0;
		rep(j,i,n+1) {
			s+=a[j];
			seg[j-i+1]=max(seg[j-i+1],s);
		}
	}
	seg[n+1]=-inf;
	per(i,0,n+1) {
		seg[i]=max(seg[i+1],seg[i]);
		ret[i]=max(seg[i]+x*i,0);
		//printf("%d %d %d\n",i,seg[i],ret[i]);
	}
	rep(i,1,n+1) ret[i]=max(ret[i],ret[i-1]);
	rep(i,0,n+1) printf("%d%c",ret[i]," \n"[i==n]);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}