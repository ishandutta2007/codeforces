#include<iostream>
using namespace std;
int a[13333],b[13333],n,m,k,l,r;
struct DSU
{
	int f[510],c;
	int get(int a)
	{
		if (f[a]) 
		{
			f[a]=get(f[a]);
			return f[a];
		}
		else return a;
	}
	void uion(int x,int y) 
	{
		if (get(x)!=get(y)) 
		{
			f[get(x)]=get(y);
			c++;
		}
	}
}lef[13333],rig[13333],ans;
int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		lef[i]=lef[i-1];
		lef[i].uion(a[i],b[i]); 
	}
	for (int i=m;i>=1;i--)
	{
		rig[i]=rig[i+1];
		rig[i].uion(a[i],b[i]);
	}
	cin>>k;
	for (int i=1;i<=k;i++)
	{
		cin>>l>>r;
		ans=lef[l-1];
		for (int j=1;j<=n;j++)
		{
			if (rig[r+1].f[j]) ans.uion(j,rig[r+1].f[j]);
		}
		cout<<n-ans.c<<endl;
	}
	return 0;
}