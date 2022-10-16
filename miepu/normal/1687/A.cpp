#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

int a[N],sum[N];

int S(int l,int r){
	return (l+r)*(r-l+1)/2;
}

void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum[i]=sum[i-1]+a[i];
	int res=0;
	for(int i=min(n,k);i<=n;i++)
		res=max(res,sum[i]-sum[i-min(n,k)]);
	if(k<=n) res+=S(0,k-1);
	else res+=S(k-n,k-1);
	cout<<res<<'\n';
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}