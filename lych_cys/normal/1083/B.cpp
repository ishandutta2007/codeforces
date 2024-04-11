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
#define N 1000009
using namespace std;

int n,m; char s1[N],s2[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int main(){
	n=read(); m=read();
	scanf("%s%s",s1+1,s2+1);
	ll ans=0;
	int now=0,last=0;
	for (int i=1; i<=n; i++){
		now=now*2+s2[i]-s1[i];
	//	cerr<<i<<' '<<now<<' '<<last<<' '<<now+1-last<<'\n';
		int tmp=min(now+1-last,m);
	//	cerr<<tmp<<' '<<n-i+1<<'\n';
		ans+=(ll)tmp*(n-i+1);
		m-=tmp; last=now+1;
		if (!m) break;
	}
	printf("%lld\n",ans);
	return 0;
}