#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("popcnt,avx")
#include<bits/stdc++.h>
using namespace std;
int const N=30010;
int n,q,MOD,f[N];
pair<int,int>a[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>MOD,f[1]=1;
	for(int i=2;i<=n;i++)
		f[i]=(f[i-1]+f[i-2])%MOD;
	for(int i=1;i<=n;i++)
		cin>>a[i].first,a[i].second=i;
	sort(a+1,a+1+n);
	for(cin>>q;q--;){
		int l,r,cur=0,p=0;cin>>l>>r;
		long long ans=0;
		for(int i=1;i<=n;i++)
			if(l<=a[i].second&&a[i].second<=r&&a[i].first^cur)
				ans+=1ll*(cur=a[i].first)*f[++p];
		cout<<ans%MOD<<"\n";
	}
}