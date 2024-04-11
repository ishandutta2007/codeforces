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
int n,a[N];
ll dp[N],s[N];
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",a+i);
	}
	dp[0]=1;
	stack<array<int,4>> st;
	st.push({0,0,0,0});
	ll sst=0;
	for (int i=1;i<=n;i++) {
		int l=i;
		ll tmp=0;
		while (!st.empty()&&st.top()[0]>a[i]) {
			int L=st.top()[1],R=st.top()[2];
			sst=(sst-st.top()[3])%mod;
			tmp=(tmp+a[i]*(s[R]-s[L-1]))%mod;
			l=L;
			auto x=st.top();
			//printf("pop V: %d L: %d R %d val: %d\n",x[0],x[1],x[2],x[3]);
			//printf("ss %lld\n",s[R]-s[L-1]);
			st.pop();
		}
		tmp=(tmp+a[i]*dp[i-1]*(i%2?-1:1))%mod;
		st.push({a[i],l,i,(int)tmp});
		auto x=st.top();
		dp[i]=(sst+tmp)*(i%2?-1:1)%mod;
		s[i]=(s[i-1]+dp[i-1]*(i%2?-1:1))%mod;
		sst=(sst+tmp)%mod;
	}
	if (dp[n]<0) dp[n]+=mod;
	printf("%lld\n",dp[n]);
}