#include<bits/stdc++.h>
using namespace std;
int const N=55;
int t,n,a[N];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int flg=1;
		for(int i=1;i<=n;i+=2)
			flg&=a[i]%2==a[1]%2;
		for(int i=2;i<=n;i+=2)
			flg&=a[i]%2==a[2]%2;
		cout<<(flg?"YES\n":"NO\n");
	}
	return 0;
}