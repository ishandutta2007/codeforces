#include<bits/stdc++.h>
using namespace std;
int const N=305;
int n,m,k,p1,p2,a,p[N],vis[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	if(k==n||m>n*(n-1)/2-k+1)
		cout<<"-1\n",exit(0);
	while(k--)
		cin>>a,p[a]=1,p1=p1?p1:a;
	p2=1+(p1<2);
	for(int i=p2+1;i<=n;i++)
		if(i!=p1)
			p2+=(p1==p2),vis[i][p2]=vis[p2][i]=1,
			cout<<i<<" "<<p2<<"\n",m--,p2++;
	for(int i=1;i<=n&&m;i++)
		if(!p[i])
			vis[i][p1]=vis[p1][i]=1,
			cout<<i<<" "<<p1<<"\n",m--;
	for(int i=1;i<=n&&m;i++)
		for(int j=i+1;j<=n&&m;j++)
			if(i^p1&&j^p1&&!vis[i][j])
				cout<<i<<" "<<j<<"\n",m--;
}