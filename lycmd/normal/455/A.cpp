#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,k,l,mx,cnt[N],f[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1,x;i<=n;i++)
		cin>>x,cnt[x]++,mx=max(mx,x);
	for(int i=1;i<=mx;i++)
		f[i]=i<2?cnt[1]:max(f[i-1],cnt[i]*i+f[i-2]);
	cout<<f[mx]<<"\n";
}