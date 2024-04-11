#include<iostream>
using namespace std;
long long r[1111111],c[1111111],n,m,x,y,sum;
long long nc,nr;
int main()
{
	cin>>n>>m;
	nc=nr=n;
	for (int i=1;i<=m;i++)
	{
		if (i) cout<<" ";
		cin>>x>>y;
		if (!c[y]) 
		{
			c[y]=1;
			nc--;
		}
		if (!r[x])
		{
			r[x]=1;
			nr--;
		}
		cout<<nc*nr;
	}
	return 0;
}