#include<bits/stdc++.h>
using namespace std;
int const N=20000010;
int n,vis[N],a[N];
int main(){
	vis[1]=1;
	for(int i=2;i<N;i++)
		if(!vis[i]&&i<=N/i)
			for(int j=i*i;j<N;j+=i)
				vis[j]=1;
	cin>>n;
	int m=n*(n+1)/2;
	for(int i=1;i<=n;i++)
		a[i]=1;
	if(!vis[m-2])
		a[2]=2,m-=2;
	if(m&1&&vis[m])
		a[3]=3,m-=3;
	if(vis[m])
		for(int j=1;j<=n;j++)
			if(!vis[j]&&!vis[m-j]){
				a[j]=2;break;
			}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}