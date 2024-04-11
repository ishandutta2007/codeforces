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

const int N=301000;

int n,a[N],ans[N],top;
PII st[N];

int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	if (*max_element(a,a+n)<=2*(*min_element(a,a+n))) {
		rep(i,0,n) printf("-1 ");
		puts("");
		return 0;
	}
	rep(i,0,n) ans[i]=30*n;
	rep(i,0,3*n) {
		int v=a[i%n],pos=i;
		while (top>0&&st[top-1].fi<v) top--;
		st[top++]=mp(v,pos);
		if (st[0].fi<=2*v) continue;
		int l=0,r=top;
		while (l+1<r) {
			int md=(l+r)>>1;
			if (st[md].fi>2*v) l=md;
			else r=md;
		}
		//printf("gg %d %d\n",i,st[l].se);
		ans[st[l].se%n]=min(ans[st[l].se%n],i-st[l].se);
	}
	per(i,0,2*n) ans[i%n]=min(ans[(i+1)%n]+1,ans[i%n]);
	rep(i,0,n) printf("%d ",ans[i]); puts("");
}