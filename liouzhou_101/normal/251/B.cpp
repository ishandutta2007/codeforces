#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=110;

int n,k;
int q[MaxN],s[MaxN],t[MaxN];
int p1[MaxN][MaxN],p2[MaxN][MaxN];

bool check(int *p)
{
	for (int i=1;i<=n;++i)
		if (p[i]!=s[i]) return false;
	return true;
}

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		cin>>q[i];
	for (int i=1;i<=n;++i)
		cin>>s[i];
	for (int i=1;i<=n;++i)
		p1[0][i]=p2[0][i]=i;
	for (int j=1;j<=k;++j)
	{
		for (int i=1;i<=n;++i)
			t[i]=p1[j-1][i];
		for (int i=1;i<=n;++i)
			p1[j][i]=t[q[i]];
		for (int i=1;i<=n;++i)
			t[i]=p2[j-1][i];
		for (int i=1;i<=n;++i)
			p2[j][q[i]]=t[i];
	}
	if (check(p1[0]))
	{
		puts("NO");
		return 0;
	}
	int f1=0,f2=0;
	for (int i=1;i<=k;++i)
	{
		if (!f1&&check(p1[i]))
		{
			if (k%2==i%2) if (i==k||i>=2||!check(p2[1]))
			{
				puts("YES");
				return 0;
			}
			f1=1;
		}
		if (!f2&&check(p2[i]))
		{
			if (k%2==i%2) if (i>=k||i>=2||!check(p1[1]))
			{
				puts("YES");
				return 0;
			}
			f2=1;
		}
	}
	puts("NO");
	return 0;
}