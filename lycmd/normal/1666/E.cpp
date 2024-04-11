#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,k,a[N],b[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>k>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=a[i];
	b[n]=k;
	for(int i=1;i<=2500;i++)
		for(int j=n-1;j;j--)
			b[j]=min(max(b[j],(b[j-1]+b[j+1]+1)/2),a[j+1]);
	for(int i=1;i<=n;++i)
		cout<<b[i-1]<<" "<<b[i]<<"\n";
}