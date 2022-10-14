#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=300010;
int n,a,ans,top,d[N],c[N],s[N],p[N],q[N],f[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>a;
	for(int i=1;i<=n;i++)
		cin>>d[i]>>c[i],ans=max(ans,c[i]=a-c[i]),s[i]=s[i-1]+c[i];
	for(int i=1;i<n;i++){
		int t=s[i-1];
		d[i]=d[i+1]-d[i];
		for(;top&&d[i]>=d[q[top]];top--)
			t=min(t,f[top]-d[q[top]]*d[q[top]]);
		q[++top]=i;
		ans=max(ans,s[i+1]-(p[top]=min(top>1?p[top-1]:LLONG_MAX,
			f[top]=t+d[i]*d[i])));
	}
	cout<<ans<<"\n";
}