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

const int N=101000;
int n,a[N],ans;
int gao(int x) {
	if (x>=(1<<n)) return 0;
	else {
		int l=gao(x+x)+a[x+x],r=gao(x+x+1)+a[x+x+1];
		ans+=abs(r-l);
		return max(r,l);
	}
}
int main() {
	scanf("%d",&n);
	rep(i,2,(1<<(n+1))) scanf("%d",a+i);
	gao(1);
	printf("%d\n",ans);
}