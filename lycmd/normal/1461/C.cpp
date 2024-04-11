#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int t,n,m,a[N];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int p=n;
		for(int i=n;i>=1;i--)
			if(a[i]==i)
				p=i-1;
			else break;
		double ans=!!p;
		while(m--){
			int x;
			double w;
			cin>>x>>w;
			if(x>=p)ans*=1-w;
		}
		cout<<fixed<<setprecision(8)<<1-ans<<"\n";
	}
}