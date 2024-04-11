#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,q,mx,x,a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]+=a[i-1],mx=max(mx,(a[i]+i-1)/i);
	for(cin>>q;q--;)
		cin>>x,cout<<(x<mx?-1:(a[n]+x-1)/x)<<"\n";
}