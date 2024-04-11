#include<bits/stdc++.h>
using namespace std;
int const N=5010;
int n,a[N];
int solve(int l,int r){
	if(l==r)return min(a[l],1);
	int p=l,res=0;
	for(int i=l;i<=r;i++)
		if(a[i]<a[p])p=i;
	res=a[p];
	for(int i=l;i<=r;i++)
		a[i]-=res;
	if(p>l)res+=solve(l,p-1);
	if(p<r)res+=solve(p+1,r);
	return min(r-l+1,res);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<solve(1,n)<<"\n";
}//