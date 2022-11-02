#include<bits/stdc++.h>
using namespace std;

const int maxn=1000010;
int g[maxn];
int f[maxn][10];
int G(int t)
{
	if (t<10)	return g[t]=t;
	int qaq=1;
	int T=t;
	while (t)
	{
		if (t%10!=0)	qaq=qaq*(t%10);
		t/=10;
	}
	return g[T]=G(qaq);
}
void prepare()
{
	for (int i=1;i<=1000000;i++)	G(i);
	for (int i=1;i<=1000000;i++)
	{
		memcpy(f[i],f[i-1],sizeof(f[i]));
		f[i][g[i]]++;
	}
}
int main()
{
	prepare();
	int te;
	scanf("%d",&te);
	while (te--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",f[r][k]-f[l-1][k]);
	}
	return 0;
}