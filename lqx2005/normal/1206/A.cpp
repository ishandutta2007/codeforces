#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
int a[N+5],b[N+5];
map<int,bool> p;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),p[a[i]]=1;
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]),p[b[i]]=1;
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=m;j++)
		{
			if(p[a[i]+b[j]]==0)
			{
				printf("%d %d\n",a[i],b[j]);
				return 0;
			}
		}
	} 
	return 0;
}