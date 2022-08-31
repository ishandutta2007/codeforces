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

const int N=1201000;
int n,L;
ll a[N],b[N];
pair<ll,int> pos[N],s[N],q[N];

bool check(int x) {
	if (2*x>=L) return 1;
	int tot=0;
	rep(i,1,3*n+1) pos[tot++]=mp(a[i]+x,-1);
	rep(i,1,3*n+1) pos[tot++]=mp(b[i],1);
	inplace_merge(pos,pos+3*n,pos+6*n);
	int cur=0;
	int m=0;
	s[m++]=mp(-1,cur);
	rep(i,0,tot) {
		cur+=pos[i].se;
		if (pos[i].fi!=pos[i+1].fi) s[m++]=mp(pos[i].fi,cur);
	}
	int r1=0,r2=0;
	int h=0,t=-1;

	rep(i,n+1,2*n+1) {
		while (a[r1+1]<=b[i]+x) r1++;
		while (r2<m&&s[r2].fi<=b[i]) {
			while (h<=t&&s[r2].se<q[t].se) --t;
			q[++t]=s[r2++];
		}
		while (h+1<=t&&q[h+1].fi<b[i]+2*x-L) ++h;
		if (i-r1>q[h].se) return 0;
	}
	return 1;
}

bool checkbf(int x) {
	if (2*x>=L) return 1;
	int h=0,t=-1;
	int r1=0,r2=0;
	rep(i,1,n+1) {
		while (a[r2+1]<=b[i]-x-1) r2++;
		int val=i-r2-1;
		while (h<=t&&val<q[t].se) --t;
//		printf("gg %d %d\n",i,val);
		q[++t]=mp(b[i],val);
	}
	rep(i,n+1,2*n+1) {
		while (a[r1+1]<=b[i]+x) r1++;

		while (a[r2+1]<=b[i]-x-1) r2++;
		int val=i-r2-1;
//		printf("gg %d %d\n",i,val);
		while (h<=t&&val<q[t].se) --t;
		q[++t]=mp(b[i],val);

		while (h<=t&&q[h].fi<b[i]+2*x-L) ++h;
//		printf("ff %d %d %d\n",i,r1,q[h].se);
		if (i-r1>q[h].se) return 0;
	}
	return 1;

}
int main() {
	while (scanf("%d%d",&n,&L)!=EOF) {
		rep(i,1,n+1) scanf("%lld",a+i);
		sort(a+1,a+n+1);
		rep(i,1,n+1) scanf("%lld",b+i);
		sort(b+1,b+n+1);

		rep(i,n+1,3*n+1) b[i]=b[i-n]+L;
		rep(i,n+1,3*n+1) a[i]=a[i-n]+L;
		int l=-1,r=L+1;
		while (l+1<r) {
			int md=(l+r)>>1;
//			printf("%d %d %d\n",md,check(md),checkbf(md));
//			assert(check(md)==checkbf(md));
			if (checkbf(md)) r=md; else l=md;
		}
		printf("%d\n",r);
	}
}