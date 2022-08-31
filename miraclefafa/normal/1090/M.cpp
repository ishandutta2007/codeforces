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

const int N=101000;
int n,k,a[N],ans;
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) scanf("%d",a+i);
	int cur=0;
	rep(i,1,n+1) {
		if (i==1||a[i]==a[i-1]) cur=1;
		else cur++;
		ans=max(ans,cur);
	}
	printf("%d\n",ans);
}