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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010;
int n,a[N],b[N],f[N];
char s[N];

int main() {
	scanf("%d",&n);
	scanf("%s",s);
	rep(i,0,n) f[i]=s[i]-'0';
	rep(i,0,n) {
		scanf("%d%d",a+i,b+i);
	}
	int ans=accumulate(f,f+n,0);
	rep(i,0,100000) {
		rep(j,0,n) if (i>=b[j]&&(i-b[j])%a[j]==0) f[j]^=1;
		ans=max(ans,accumulate(f,f+n,0));
	}
	printf("%d\n",ans);
}