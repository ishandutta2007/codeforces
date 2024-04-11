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

const int N=201000,M=200000;
int n,l[N],r[N],cnt[N],gor[N],a[N],f[N],ans;

int main() {
	scanf("%d%*d",&n);
	rep(i,1,M+1) l[i]=n+1,r[i]=0;
	rep(i,1,n+1) {
		scanf("%d",a+i);
		l[a[i]]=min(l[a[i]],i);
		r[a[i]]=max(r[a[i]],i);
		cnt[a[i]]++;
	}
	rep(i,1,n+1) gor[i]=r[a[i]];
	int p=1;
	while (p<=n) {
		int mr=gor[p];
		int md=0;
		while (p<=mr) {
			md=max(md,cnt[a[p]]);
			mr=max(mr,gor[p]);
			p++;
		}
		ans+=md;
	}
	printf("%d\n",n-ans);
}