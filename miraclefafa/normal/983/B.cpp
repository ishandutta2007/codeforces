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

const int N=5010;
int n,b[N],f[N][N],_,l,r;
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",b+i),f[i][i]=b[i];
	for (int d=1;d<n;d++) {
		for (int i=1;i+d<=n;i++) {
			int j=i+d;
			f[i][j]=f[i][j-1]^f[i+1][j];
//			printf("%d %d %d\n",i,j,f[i][j]);
		}
	}
	for (int d=1;d<n;d++) {
		for (int i=1;i+d<=n;i++) {
			int j=i+d;
			f[i][j]=max(f[i][j],max(f[i][j-1],f[i+1][j]));
		}
	}
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&l,&r);
		printf("%d\n",f[l][r]);
	}
}