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
int n,a[N];
ll b[N];
void gao(ll &a,ll b,ll c) {
//	printf("%lld %lld %lld\n",a,b,c);
	if (a==0) a=b;
	if (a>c) return;
	a+=(c-a+b)/b*b;
	assert(a>c&&a-b<=c);
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d",a+i);
//		a[i]=rand()%100000;
	}
	if (*max_element(a,a+n)==0) {
		puts("YES");
		rep(i,0,n) printf("%d%c",1," \n"[i==n-1]);
		return 0;
	}
	rep(i,0,n) if (a[i]<a[(i+1)%n]) {
		b[(i+1)%n]=a[(i+1)%n];
		rep(j,0,n-1) {
			int cur=(i-j+n)%n;
			b[cur]=a[cur];
			gao(b[cur],b[(cur+1)%n],a[(cur+n-1)%n]);
		}
		puts("YES");
		rep(i,0,n) printf("%lld%c",b[i]," \n"[i==n-1]);
		return 0;
	}
	puts("NO");
}