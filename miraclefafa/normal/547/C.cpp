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

const int N=501000;
int n,q,a[N],cnt[N],mu[N],vis[N],v[N];
VI d[N];
ll ans;
int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) {
		scanf("%d",a+i);
		v[a[i]]=1;
	}
	rep(i,1,500001) {
		if (i==1) mu[i]=1;
		for (int j=i;j<=500000;j+=i) {
			if (v[j]) d[j].pb(i);
			if (j!=i) mu[j]-=mu[i];
		}
	}
	rep(j,0,q) {
		int i;
		scanf("%d",&i);
		if (!vis[i]) {
			vis[i]=1;
			for (int p:d[a[i]]) {
				ans+=mu[p]*(cnt[p]++);
			}
		} else {
			vis[i]=0;
			for (int p:d[a[i]]) {
				ans-=mu[p]*(--cnt[p]);
			}
		}
		printf("%I64d\n",ans);
	}
}