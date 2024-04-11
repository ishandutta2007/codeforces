#include<iostream>
using namespace std;
int a[1111],b[1111],n,p[1111],cnt,pos[1111];
bool ex[1111];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=b[i]) pos[++cnt]=i;
		else 
		{
			ex[a[i]]=1;
			p[i]=a[i];
		}
	}
	if (cnt==1)
	{
		for (int i=1;i<=n;i++)
		{
			if (!ex[i]) p[pos[1]]=i;
		} 
		for (int i=1;i<=n;i++)
		{
			if (i-1) cout<<" ";
			cout<<p[i];
		}
	}
	else
	{
		for (int i=1;i<=2;i++)
		{
			if (ex[a[pos[i]]] && !ex[b[pos[i]]]) 
			{
				p[pos[i]]=b[pos[i]];
				ex[b[pos[i]]]=1;
			}
			else if (!ex[a[pos[i]]] && ex[b[pos[i]]])
			{
				p[pos[i]]=a[pos[i]];
				ex[a[pos[i]]]=1;
			}
		}
		if (!p[pos[1]] && !p[pos[2]]) 
		{
			p[pos[1]]=a[pos[1]];
			if (a[pos[2]]!=a[pos[1]]) p[pos[2]]=a[pos[2]];
			else p[pos[2]]=b[pos[2]];
		}
		else
		{
			for (int i=1;i<=2;i++)
			{
				if (!p[pos[i]])
				{
					for (int j=1;j<=n;j++)
					{
						if (!ex[j]) 
						{
							p[pos[i]]=j;
							break;
						}
					}
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (i-1) cout<<" ";
			cout<<p[i];
		}
	}
	return 0;
}