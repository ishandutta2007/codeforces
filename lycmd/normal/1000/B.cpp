#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,m,ans,a[N],s[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m,a[n+1]=m;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+(i&1?a[i]-a[i-1]:0);
	ans=max(ans,s[n+1]=s[n]+(n&1?0:m-a[n]));
	for(int i=0;i<=n+1;i++){
		if(i&&a[i]-1>a[i-1])
			ans=max(ans,s[i]+m-a[i]-s[n+1]+s[i]+(i&1?-1:1));
		if(i<=n&&a[i]+1<a[i+1])
			ans=max(ans,s[i]+m-a[i]-s[n+1]+s[i]+(i&1?-1:1));
	}
	cout<<ans<<"\n";
}