#include<bits/stdc++.h>
using namespace std;
int a[501],b[501],f[501],g[501];
void sc(int now)
{
	if(now==0)return;
	else sc(g[now]);
	cout<<b[now]<<' ';
}
int main()
{
    int n;
	cin>>n;
	for(int x=1;x<=n;x++)
	cin>>a[x];
	int m;
	cin>>m;
	for(int x=1;x<=m;x++)
	cin>>b[x];
	for(int x=1;x<=n;x++)
	{
	    int z=0;
	    for(int y=1;y<=m;y++)
	    if(a[x]==b[y])f[y]=f[z]+1,g[y]=z;
	    else if(a[x]>b[y]&&f[z]<f[y])z=y;
	}
	int maid=0;
	for(int x=1;x<=m;x++)
	if(f[x]>f[maid])maid=x;
	cout<<f[maid]<<endl;
	sc(maid);
}