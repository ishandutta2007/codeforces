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
using namespace std;

int n; double a[1009],b[1009],m;
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
bool ok(double x){
	int i;
	for (i=1; i<=n; i++){
		x-=(x+m)/a[i];
		if (x<0) return 0;
		x-=(x+m)/b[i+1];
		if (x<0) return 0;
	}
	return 1;
}
int main(){
	scanf("%d%lf",&n,&m);
	int i;
	for (i=1; i<=n; i++) scanf("%lf",&a[i]);
	for (i=1; i<=n; i++) scanf("%lf",&b[i]);
	b[n+1]=b[1];
	long double l=0,r=2e9,mid;
	while (l+1e-8<r){
		mid=(l+r)/2;
		if (ok(mid)) r=mid; else l=mid;
	}
	if (l<1e9+5e8) printf("%.10f\n",(double)l); else puts("-1");
	return 0;
}