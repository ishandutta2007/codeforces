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

#define y1 asfsafds
const int N=101000;
int n,m,c1,c2,v,a[N],b[N],q,x1,y1,x2,y2;
int gao(int *a,int n,int x1,int x2) {
	if (n==0) return 1<<30;
	int p=lower_bound(a,a+n,x1)-a;
	int ret=1<<30;
	for (int v1=max(p-5,0);v1<min(p+5,n);v1++) ret=min(ret,abs(a[v1]-x1)+abs(a[v1]-x2));
	p=lower_bound(a,a+n,x2)-a;
	for (int v1=max(p-5,0);v1<min(p+5,n);v1++) ret=min(ret,abs(a[v1]-x1)+abs(a[v1]-x2));
	return ret;
}
int main() {
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&c1,&c2,&v);
	rep(i,0,c1) scanf("%d",a+i);
	sort(a,a+c1);
	rep(i,0,c2) scanf("%d",b+i);
	sort(b,b+c2);
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
		if (x1>x2) swap(x1,x2);
		if (y1>y2) swap(y1,y2);
		if (y1==y2) {
			printf("%d\n",x2-x1);
		} else {
			printf("%d\n",min(gao(a,c1,x1,x2)+y2-y1,gao(b,c2,x1,x2)+(y2-y1+v-1)/v));
		}
	}
}