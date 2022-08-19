#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
int n,lh[N],w[N],h[N],rh[N],sw;
int main() {
	scanf("%d",&n);
	lh[0]=0;
	rep(i,1,n+1) {
		scanf("%d%d",w+i,h+i);
		sw+=w[i];
		lh[i]=max(lh[i-1],h[i]);
	}
	per(i,1,n+1) rh[i]=max(rh[i+1],h[i]);
	rep(i,1,n+1) {
		printf("%d ",(sw-w[i])*max(lh[i-1],rh[i+1]));
	}
}