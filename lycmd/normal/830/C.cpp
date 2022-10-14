#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233;
int n,k,s,i,a[N];
int solve(int x){
	int res=0;
	for(int i=1;i<=n;i++)
		res+=a[i]/x;
	return(res+n)*x<=s;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k,s=k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s+=a[i]--;
	for(i=1;i*i<=s;i++)
		if(solve(s/i))
			cout<<s/i<<"\n",exit(0);
	for(;i;i--)
		if(solve(i))
			cout<<i<<"\n",exit(0);
}