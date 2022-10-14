#include<bits/stdc++.h>
using namespace std;
int const N=5000010;
int k1,k2,k3,n,ans,t,a[N],s1[N],s2[N],s3[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>k1>>k2>>k3,n=k1+k2+k3;
	for(int i=1,x;i<=k1;i++)
		cin>>x,a[x]=1;
	for(int i=1,x;i<=k2;i++)
		cin>>x,a[x]=2;
	for(int i=1,x;i<=k3;i++)
		cin>>x,a[x]=3;
	for(int i=1;i<=n;i++)
		s1[i]=s1[i-1]+(a[i]==1),s2[i]=s2[i-1]+(a[i]==2),
		s3[i]=s3[i-1]+(a[i]==3);
	for(int i=0;i<=n;i++)
		ans=max(ans,(t=max(t,s1[i]+k2-s2[i]))-k2+s2[i]+k3-s3[i]);
	cout<<n-ans<<"\n";
}