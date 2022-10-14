#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,k,fa[N],dep[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=2;i<=n;i++)
		fa[i]=max(i-k,1),dep[i]=dep[fa[i]]+1;
	cout<<dep[n]+dep[n-1]<<"\n";
	for(int i=2;i<=n;i++)
		cout<<i<<" "<<fa[i]<<"\n";
}