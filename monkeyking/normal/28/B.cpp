#include <iostream>
using namespace std;
int fa[105];

void init()
{
	for(int i=0;i<105;i++)
	{
		fa[i]=i;
	}
}

int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y) fa[x]=y;
}

int main()
{
	init();
	int n;
	cin>>n;
	int a[n],x;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]--;
	} 
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(i-x>=0) merge(i,i-x);
		if(i+x<n) merge(i,i+x);
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<find(i)<<" ";
//	}
//	cout<<endl;
//	for(int i=0;i<n;i++)
//	{
//		cout<<find(a[i])<<" ";
//	}
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		if(find(i)!=find(a[i])) 
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}