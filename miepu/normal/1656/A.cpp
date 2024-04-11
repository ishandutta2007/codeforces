#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

	int n,a[N];
void solve(){
	int mx=1,mn=1;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++){
		if(a[i]>a[mx])mx=i;
		if(a[i]<a[mn])mn=i;
	}
	cout<<mx<<' '<<mn<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}