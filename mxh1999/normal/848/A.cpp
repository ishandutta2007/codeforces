#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=100010;
int f[maxn];
int pre[maxn],q[maxn];
int n;

int main()
{
	scanf("%d",&n);
	if (n==0)
	{
		printf("a\n");
		return 0;
	}
	memset(f,-1,sizeof(f));
	f[0]=0;
	for (int i=0;i<n;i++)
	{
		for (ll j=1;j*(j-1)/2<=n;j++)
		{
			ll x=i+j*(j-1)/2;
			if (x>n)	break;
			if (f[x]==-1 ||f[x]>f[i]+1)	f[x]=f[i]+1,pre[x]=i,q[x]=j;
		}
	}
	char now='a';
	while (n)
	{
		for (int i=1;i<=q[n];i++)	printf("%c",now);
		n=pre[n];
		now++;
	}
	printf("\n");
	return 0;
}