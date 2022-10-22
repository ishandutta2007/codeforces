#include <iostream>
using namespace std;

struct bcj
{
	int f[505],c;
	int get(int n)
	{
		return f[n]?f[n]=get(f[n]):n;
	}
	int link(int x,int y)
	{
		x=get(x);
		y=get(y);
		if(x!=y)
		{
			f[x]=y;
			c++;
		}
	}
};
bcj l[10005],r[10005];

int main()
{
	int n,m,k,L,R;
	cin>>n>>m;
	int x[m],y[m];
	for(int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i];
		l[i]=l[i-1];
		l[i].link(x[i],y[i]);
	}
	for(int i=m;i;i--)
	{
		r[i]=r[i+1];
		r[i].link(x[i],y[i]);
	}
	cin>>k;
	bcj ans;
	while(k--)
	{
		cin>>L>>R;
		ans=l[L-1];
		for(int i=1;i<=n;i++)
		{
			if(r[R+1].f[i]) ans.link(i,r[R+1].f[i]);
		}
		cout<<n-ans.c<<endl;
	}
	return 0;
}