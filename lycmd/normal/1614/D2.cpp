#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=20000010;
int n,tot,a[N],p[N],s[N],f[N],vis[N];
signed main(){
	ios::sync_with_stdio(0);
	for(int i=2;i<N;i++)
		if(!vis[i]){
			p[++tot]=i;
			for(int j=i*2;j<N;j+=i)
				vis[j]=1;
		}
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[a[i]]++;
	for(int i=1;i<=tot;i++)
		for(int j=N/p[i];j;j--)
			s[j]+=s[j*p[i]];
	for(int i=N-1;i;i--){
		int t=0;
		for(int j=1;j<=tot&&i*p[j]<N;j++)
			t=max(t,f[i*p[j]]-s[i*p[j]]*i);
		f[i]=s[i]*i+t;
	}
	cout<<f[1]<<"\n";
}//