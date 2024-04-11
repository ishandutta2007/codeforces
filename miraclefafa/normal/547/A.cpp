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

bool vis[1010000];
int m,h1,a1,x1,y1;
ll gao(ll h,ll x,ll y) {
	memset(vis,0,sizeof(vis));
	int cnt=0;
	while (1) {
		if (vis[h]) return -1;
		vis[h]=1;
		h=(h*x+y)%m;
		++cnt;
		if (h==a1) return cnt;
	}
}
int main() {
	scanf("%d",&m);
	scanf("%d%d%d%d",&h1,&a1,&x1,&y1);
	ll t1=gao(h1,x1,y1),c1=gao(a1,x1,y1);
	scanf("%d%d%d%d",&h1,&a1,&x1,&y1);
	ll t2=gao(h1,x1,y1),c2=gao(a1,x1,y1);
	if (t1==-1||t2==-1) {
		puts("-1");
		return 0;
	}
	// t1!=-1&&t2!=-1
	if (c1==-1&&c2==-1) {
		if (t1==t2) printf("%I64d\n",t1);
		else puts("-1");
		return 0;
	}
	if (c1!=-1&&c2!=-1) {
		rep(i,0,2000001) if (t1+c1*i>=t2&&(t1+c1*i-t2)%c2==0) {
			printf("%I64d\n",t1+c1*i);
			return 0;
		}
		puts("-1");
		return 0;
	} else {
		if (c1==-1) swap(t1,t2),swap(c1,c2);
		// c1!=-1 c2=-1
		if (t2>=t1&&(t2-t1)%c1==0) printf("%I64d\n",t2);
		else puts("-1");
	}
}