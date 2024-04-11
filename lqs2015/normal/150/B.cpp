#include<iostream>
using namespace std;
int n,m,k,pa[2333];
long long ans;
int ins(int a)
{
	if (pa[a]==a) return a;
	pa[a]=ins(pa[a]);
	return pa[a];
}
void comb(int i,int j)
{
	pa[ins(i)]=ins(j);
}
int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) 
	pa[i]=i;
	for (int i=1;i<=n-k+1;i++)
	{
		for (int j=1;j<=k/2;j++)
		comb(i+j-1,i+k-j);
	}
	ans=1;
	for (int i=1;i<=n;i++)
	{
		if (pa[i]==i) ans=ans*m%1000000007;
	}
	cout<<ans<<endl;
	return 0;
}