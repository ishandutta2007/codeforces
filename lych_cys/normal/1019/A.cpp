#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 3009
using namespace std;

int n,m,b[N],c[N]; bool bo[N]; pii a[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll solve(int x){
	int i,now=b[1]; memset(bo,0,sizeof(bo)); memcpy(c,b,sizeof(b));
	ll sum=0;
	for (i=1; i<=n; i++) if (a[i].se>1 && c[a[i].se]>=x){
		bo[i]=1;
		c[a[i].se]--; sum+=a[i].fi; now++;	
	}
	for (i=1; i<=n && now<x; i++) if (!bo[i] && a[i].se>1){
		sum+=a[i].fi; now++;
	}
	return sum;
}
int main(){
	scanf("%d%d",&n,&m);
	int i,x,y;
	for (i=1; i<=n; i++){
		scanf("%d%d",&x,&y);
		a[i]=mpr(y,x); b[x]++;
	}
	sort(a+1,a+n+1);
	ll ans=1ll<<60;
	for (i=1; i<=n; i++) ans=min(ans,solve(i));
	printf("%lld\n",ans);
	return 0;
}