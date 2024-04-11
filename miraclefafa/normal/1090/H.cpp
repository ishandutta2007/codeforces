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

const int N=201000;
int n,bit[N],ss[22][N],_,l,r;
char s[N];
int main() {
	scanf("%d",&n);
	scanf("%s",s);
	rep(i,1,n) bit[i]=s[i]!=s[i-1];
	int step=0;
	auto query=[&](int s,int z) {
		if (z>n) return 0;
		return ss[s][z];
	};
	for (int z=1;z<=n;z=z+z) {
		per(i,1,n+1) {
			ss[step][i]=bit[i]+query(step,i+z+z);
		}
		step++;
	}
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&l,&r);
		int ans=0; step=0;
		for (int z=1;z<r-l+1;z=z+z) {
			int c=query(step,l+z)-query(step,r+1+z);
			ans+=min(c,(r-l+1)/z/2-c);
			step+=1;
		}
		printf("%d\n",(ans+1)/2);
	}
}