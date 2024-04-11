#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,x,a[N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>x;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int mn=2e9,mx=0,cnt=0;
		for(int i=1;i<=n;i++){
			mn=min(mn,a[i]),mx=max(mx,a[i]);
			if(mx-mn>2*x)
				cnt++,mn=mx=a[i];
		}
		cout<<cnt<<"\n";
	}
}