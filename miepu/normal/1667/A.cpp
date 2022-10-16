#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,a[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int res=1e18;
	for(int i=0;i<=n;i++){
		int nr=0;
		for(int j=i+1,nw=0;j<=n;j++){
			int t=ceil(1.*(nw+1)/a[j]);
			nr+=t;
			nw=t*a[j];
		}
		for(int j=i-1,nw=0;j>=1;j--){
			int t=ceil(1.*(nw+1)/a[j]);
			nr+=t;
			nw=t*a[j];
		}
		res=min(res,nr);
	}
	cout<<res<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}