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

const int N=1010;

int n,m,f[N];
char s[N][N];

int find(int x) { return f[x]==x?x:x=find(f[x]); }

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n+m) f[i]=i;
	rep(i,0,n) {
		scanf("%s",s[i]);
		rep(j,0,m) if (s[i][j]=='#') f[find(i)]=find(j+n);
	}
	rep(i,0,n) rep(j,0,m) if ((find(i)==find(j+n))!=(s[i][j]=='#')) {
		puts("No");
		return 0;
	}
	puts("Yes");
}