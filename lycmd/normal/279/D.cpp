#include<bits/stdc++.h>
using namespace std;
int const N=23,M=10000010,INF=0x3f3f;
int n,a[N];
int f[M];
int solve(int s,int x){
	int&res=f[s];
	if(res)
		return res;
	if(!x)
		return res=1;
	res=INF;
	for(int i=0;i<x;i++)
		for(int j=i;j<x;j++)
			if(a[i]+a[j]==a[x])
				res=min(res,solve(s^1<<x|1<<x-1|1<<i|1<<j,x-1));
	return res=max(res,__builtin_popcount(s));
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans=solve(1<<(n-1),n-1);
	cout<<(ans<INF?ans:-1)<<"\n";
}