#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=300010;
int n,ans,a[N],s[N],c[2]={1,0};
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+(a[i]=__builtin_popcountll(a[i]));
	for(int i=1;i<=n;i++){
		ans+=c[s[i]&1]++;
		for(int j=i,mx=a[i];j>=max(i-70,1ll);mx=max(mx,a[--j]))
			ans-=~(s[i]-s[j-1])&1&&mx*2>s[i]-s[j-1];
	}
	cout<<ans<<"\n";
}