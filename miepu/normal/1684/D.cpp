#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;


int n,k;
int a[N];

void solve(){
	cin>>n>>k;
	int res=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		res+=a[i];
		a[i]-=n-i;
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(int i=1;i<=k;i++){
		if(a[i]+i-1<0)break;
		res-=a[i]+i-1;
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}