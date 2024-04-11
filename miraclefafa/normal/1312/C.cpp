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
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int _,n,k;
ll a[1010];
bool check() {
	set<int> pos;
	rep(i,0,n) {
		ll x=a[i];
		int d=0;
		while (x) {
			if (x%k!=0&&x%k!=1) {
				return 0;
			}
			if (x%k==1) {
				//printf("dd %d\n",d);
				if (pos.count(d)) return 0;
				pos.insert(d);
			}
			d+=1;
			x/=k;
		}
	}
	return 1;
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&k);
		rep(i,0,n) scanf("%lld",a+i);
		puts(check()?"YES":"NO");
	}
}