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
int n,m;
int ty[N],l[N],r[N],s[N],a[N];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		scanf("%d%d%d",ty+i,l+i,r+i);
		if (ty[i]==1) {
			rep(j,l[i],r[i]) s[j]=1;
		}
	}
	a[1]=1000000000;
	rep(i,1,n) if (s[i]) a[i+1]=a[i];
		else a[i+1]=a[i]-1;
	rep(i,0,m) {
		if (ty[i]==0) {
			bool ss=0;
			rep(j,l[i],r[i]) if (a[j]>a[j+1]) ss=1;
			if (!ss) {
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	rep(i,1,n+1) printf("%d%c",a[i]," \n"[i==n]);
}