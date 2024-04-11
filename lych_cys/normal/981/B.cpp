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
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 100009
using namespace std;

int n,m,a[N],b[N]; map<int,int> mp;
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int main(){
	n=read();
	int i; ll ans=0;
	for (i=1; i<=n; i++){
		a[i]=read(); ans+=(mp[a[i]]=read());
	}
	m=read();
	for (i=1; i<=m; i++){
		b[i]=read();
		int x=read();
		if (mp.count(b[i])) ans+=max(mp[b[i]],x)-mp[b[i]]; else ans+=x;
	}
	printf("%lld\n",ans);
	return 0;
}