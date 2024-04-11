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
int n,m,l,r,a[N],p[N],q[N],f[N],ret;
void gao(int *p,int *g,int n) {
	int m=0;
	rep(i,0,n+1) f[i]=0;
	rep(i,1,n+1) {
		int j=upper_bound(f+1,f+m+1,p[i])-f;
		f[j]=p[i];
		g[i]=j;
		m=max(m,j);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%d%d",&l,&r);
		a[l]++;
		a[r+1]--;
	}
	rep(i,1,m+1) a[i]+=a[i-1];
	gao(a,p,m);
	reverse(a+1,a+m+1);
	gao(a,q,m);
	rep(i,0,m+1) ret=max(ret,p[i]+q[m-i]);
	printf("%d\n",ret);
}