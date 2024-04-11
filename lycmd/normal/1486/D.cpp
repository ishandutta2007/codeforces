#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,k,a[N],b[N];
int check(int x){
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+(a[i]>=x?1:-1);
	int mx=b[k],mn=0;
	for(int i=k+1;i<=n;i++)
		mx=max(mx,b[i]-(mn=min(mn,b[i-k])));
	return mx>0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=1,r=n+1;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))l=mid;else r=mid;
	}
	cout<<l<<"\n";
}