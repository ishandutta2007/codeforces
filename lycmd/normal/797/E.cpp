#include<bits/stdc++.h>
using namespace std;
int const N=100010,B=335;
int n,q,b,a[N],f[N][B];
int solve(int p,int k){
	int r=0;
	for(;p<=n;r++)
		p+=a[p]+k;
	return r;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n,b=sqrt(n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
		for(int j=1;j<=b;j++)
			f[i][j]=f[min(i+a[i]+j,n+1)][j]+1;
	cin>>q;
	for(int p,k;q--;){
		cin>>p>>k;
		if(k<=b)
			cout<<f[p][k]<<"\n";
		else
			cout<<solve(p,k)<<"\n";
	}
}