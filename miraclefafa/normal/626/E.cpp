#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

struct frac {
	ll a,b;
};
bool operator < (const frac &a,const frac &b) {
	if (fabs((double)a.b*b.a-(double)a.a*b.b)>=1e17) {
		return (double)a.a*b.b<(double)a.b*b.a;
	} else return a.a*b.b-a.b*b.a<0;
}
const int N=1010000;
int n,x[N];
frac ans;
ll s[N];
PII ansp;
VI ret;
void gao(int l,int r,int tl,int tr) {
	int md=(l+r)>>1;
	frac c=(frac){-1,1}; int pj=-1;
	rep(j,tl,tr+1) if (md>=j&&n-(md-j)>=md) {
		frac r=(frac){s[n]-s[n-(md-j)]+s[md]-s[j-1],2*(md-j)+1};
		if (c<r) c=r,pj=j;
	}
	c.a-=x[md]*c.b;
	if (ans<c) ans=c,ansp=mp(pj,md);
	if (pj==-1) return;
	if (l<md) gao(l,md-1,tl,pj);
	if (md<r) gao(md+1,r,pj,tr);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",x+i);
	sort(x+1,x+n+1);
	rep(i,1,n+1) s[i]=s[i-1]+x[i];
	ans=(frac){-1,1};
	gao(1,n,1,n);
	rep(i,ansp.fi,ansp.se+1) ret.pb(x[i]);
	rep(i,n-(ansp.se-ansp.fi)+1,n+1) ret.pb(x[i]);
	printf("%d\n",SZ(ret));
	for (auto x:ret) printf("%d ",x);
	puts("");
}