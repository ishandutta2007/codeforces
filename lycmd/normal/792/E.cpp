#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=505;
int n,mn=2e9,a[N];
int solve(int x){
	int res=0;
	for(int i=1;i<=n;i++)
		if(a[i]%x==0)
			res+=a[i]/x;
		else if(a[i]/x+a[i]%x>=x-1)
			res+=a[i]/x+1;
		else
			return 0;
	return cout<<res<<"\n",1;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],mn=min(mn,a[i]);
	for(int i=1;i<=mn;i++)
		if(solve(mn/i+1)||solve(mn/i))
			break;
	return 0;
}