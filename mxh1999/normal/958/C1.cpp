#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
int n,p;
int a[maxn],pre[maxn],suf[maxn];
int main()
{
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		pre[i]=(pre[i-1]+a[i])%p;
	for (int i=n;i>=1;i--)
		suf[i]=(suf[i+1]+a[i])%p;
	int nnm=0;
	for (int i=1;i<n;i++)
		nnm=max(nnm,pre[i]+suf[i+1]);
	printf("%d\n",nnm);
}