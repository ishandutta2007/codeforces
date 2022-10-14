#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,a[N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+1+n,[](int x,int y){
			return __builtin_ctzll(x)<__builtin_ctzll(y);
		});
		int res=__builtin_ctzll(a[1]);
		for(int i=2;i<=n;i++)
			res+=~a[i]&1;
		cout<<res<<"\n";
	}
}