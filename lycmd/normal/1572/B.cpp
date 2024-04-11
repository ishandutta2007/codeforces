#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int t,n,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		int xs=0,p=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],a[i]^=a[i-1],p=i%2&&!a[i]?i:p;
		if(p&&!a[n]){
			cout<<"YES\n"<<n-1-(n!=p)<<"\n";
			for(int i=p+1;i<n-1;i+=2)
				cout<<i<<" ";
			for(int i=p-2;i>0;i-=2)
				cout<<i<<" ";
			for(int i=1;i<n-1;i+=2)
				cout<<i<<" ";
		}else cout<<"NO\n";
	}
}