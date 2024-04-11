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

int n,a[100009],b[100009];
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
int main(){
	scanf("%d",&n);
	int i,j,now=0;
	for (i=1; i<=n/2; i++){
		scanf("%d",&a[i]);
		for (j=sqrt(a[i]-1); j; j--) if (!(a[i]%j)){
			int x=j,y=a[i]/j;
			if ((x^y)&1) continue;
			int u=y-x>>1,v=x+y>>1;
			//cerr<<u<<' '<<v<<'\n';
			if (u>b[now]){
				b[++now]=u; b[++now]=v;	break;
			}
		}
		if (!j){ puts("No"); return 0; }
	}
	puts("Yes");
	for (i=1; i<=n; i++) printf("%lld%c",(ll)b[i]*b[i]-(ll)b[i-1]*b[i-1],i<n?' ':'\n');
	return 0;	
}