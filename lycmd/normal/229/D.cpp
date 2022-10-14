#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=5010;
int n,a[N],s[N],pre[N],f[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
		for(int j=i-1;~j;j--)
			if(s[i]-s[j]>=s[j]-s[pre[j]]){
				pre[i]=j,f[i]=f[j]+i-j-1;
				break;
			}
	cout<<f[n]<<"\n";
}