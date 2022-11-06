#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
using namespace std;

int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int n; pii a[1009]; bool bo[1009]; map<pii,int> mp;
bool check(int x,int y){
	int i;
	memset(bo,0,sizeof(bo));
	for (i=1; i<=n; i++){
		int k=mp[mpr(x-a[i].fi,y-a[i].se)];
		if (!k) return 0;
		if (bo[k]) return 0; bo[k]=1;
	}
	printf("%d %d\n",x,y);
	return 1;
}
int main(){
	scanf("%d",&n);
	int i,x,y;
	for (i=1; i<=n; i++) scanf("%d%d",&a[i].fi,&a[i].se);
	for (i=1; i<=n; i++){
		scanf("%d%d",&x,&y);
		mp[mpr(x,y)]=i;	
	}
	for (i=1; i<=n; i++) if (check(a[i].fi+x,a[i].se+y)) break;
	return 0;
}