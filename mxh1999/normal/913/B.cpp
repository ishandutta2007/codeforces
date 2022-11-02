#include<bits/stdc++.h>
using namespace std;

const int maxn=1010;
int leaf[maxn],num[maxn],fa[maxn];
int n,m;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		leaf[i]=true;
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]);
		leaf[fa[i]]=false;
	}
	for (int i=1;i<=n;i++)
	if (leaf[i])	num[fa[i]]++;
	for (int i=1;i<=n;i++)
	if (!leaf[i] && num[i]<3)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}