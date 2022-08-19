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

const int N=10100;
int n,a[N],cnt[N],rnt[N],tot;
ll ret;
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	sort(a,a+n);
	rep(i,0,n) rep(j,i+1,n) cnt[a[j]-a[i]]++;
	per(i,0,10001) rnt[i]=rnt[i+1]+cnt[i];
	rep(i,1,5000) rep(j,1,5000) {
		ret+=(ll)cnt[i]*cnt[j]*rnt[i+j+1];
	}
	tot=n*(n-1)/2;
	printf("%.10f\n",1.*ret/tot/tot/tot);
}