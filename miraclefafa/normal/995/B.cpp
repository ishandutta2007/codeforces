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

int n,p,ans;
VI v[1010];
int main() {
	scanf("%d",&n);
	rep(i,0,2*n) {
		scanf("%d",&p); --p;
		v[p].pb(i);
	}
	rep(i,0,n) rep(j,i+1,n) {
		auto p1=v[i],p2=v[j];
		if (p1[0]>p2[0]) swap(p1,p2);
		if (p1[1]<p2[0]) ans+=0;
		else if (p1[1]>p2[1]) ans+=2;
		else ans+=1;
	}
	printf("%d\n",ans);
}