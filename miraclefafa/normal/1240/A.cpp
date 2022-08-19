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

const int N=201000;
int _,n,p[N],x,a,y,b,c[N];
ll k;
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		rep(i,0,n) scanf("%d",p+i),p[i]/=100;
		sort(p,p+n); reverse(p,p+n);
		scanf("%d%d",&x,&a);
		scanf("%d%d",&y,&b);
		scanf("%lld",&k);
		int l=0,r=n+1;
		while (l+1<r) {
			int md=(l+r)>>1;
			rep(i,1,md+1) {
				int z=0;
				if (i%a==0) z+=x;
				if (i%b==0) z+=y;
				c[i-1]=z;
			}
			sort(c,c+md); reverse(c,c+md);
			ll tot=0;
			rep(i,0,md) tot+=(ll)c[i]*p[i];
			if (tot>=k) r=md; else l=md;
		}
		if (r==n+1) puts("-1"); else printf("%d\n",r);
	}
}