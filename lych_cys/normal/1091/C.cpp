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
int n,cnt; ll a[1000009];
ll calc(int x){ return (ll)x*(x-1)/2; }
void check(int x){
	a[++cnt]=(ll)x*calc(n/x)+n/x;	
}
int main(){
	scanf("%d",&n);
	int i;
	for (i=1; i*i<=n; i++) if (!(n%i)){
		check(i);
		if (i*i<n) check(n/i);	
	}
	sort(a+1,a+cnt+1);
	for (i=1; i<=cnt; i++) if (i==1 || a[i]>a[i-1]) printf("%lld ",a[i]);
	puts("");
	return 0;
}