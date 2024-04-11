#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m=0,a[300010],b[300010],l[1500000],r[1500000];
void prt()
{
	for (int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
	for (int i=1;i<=n;i++) cout<<b[i]<<' ';cout<<endl;cout<<endl;
}
void swp(int x,int y)
{
	l[++m]=x;r[m]=y;swap(b[x],b[y]);swap(a[b[x]],a[b[y]]);
}
int main()
{
	int i,t;cin>>n;
	for (i=1;i<=n;i++) cin>>b[i],a[b[i]]=i;
	for (i=1;i<=n/2;i++)
	{
		if (a[i]>n/2)
		{
			swp(a[i],1);swp(1,n);swp(n,i);
		}
		else
		{
			swp(a[i],n);swp(n,i);
		}
	}
	for (i=n/2+1;i<=n;i++)
	{
		if (a[i]<=n/2)
		{
			swp(a[i],n);swp(1,n);swp(1,i);
		}
		else
		{
			swp(a[i],1);swp(1,i);
		}
	}
	cout<<m<<endl;
	for (i=1;i<=m;i++) cout<<l[i]<<' '<<r[i]<<endl;
	
}