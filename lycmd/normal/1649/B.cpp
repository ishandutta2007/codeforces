#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,mx,s,a[N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n,mx=s=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],mx=max(mx,a[i]),s+=a[i];
		cout<<(!s?0:max(2*mx-s,1ll))<<"\n";
	}
}