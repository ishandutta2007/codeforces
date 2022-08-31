#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MaxN=1000010;

int n,m;
char s[MaxN],t[MaxN];

int p[MaxN],L[MaxN],R[MaxN];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int T,ans=0;
	cin>>T;
	while (T--)
	{
		scanf("%s",t+1);
		m=strlen(t+1);
		if (m==1) continue;
		for (int i=2;i<=m;++i)
		{
			int j=p[i-1];
			while (j&&t[j+1]!=t[i])
				j=p[j];
			p[i]=j+(t[j+1]==t[i]);
		}
		for (int i=1;i<=n;++i)
		{
			int j=L[i-1];
			while (j&&t[j+1]!=s[i])
				j=p[j];
			L[i]=j+(t[j+1]==s[i]);
		}
		for (int i=1;i<=m/2;++i)
			swap(t[i],t[m-i+1]);
		for (int i=2;i<=m;++i)
		{
			int j=p[i-1];
			while (j&&t[j+1]!=t[i])
				j=p[j];
			p[i]=j+(t[j+1]==t[i]);
		}
		for (int i=1;i<=n;++i)
		{
			int j=R[n-i+2];
			while (j&&t[j+1]!=s[n-i+1])
				j=p[j];
			R[n-i+1]=j+(t[j+1]==s[n-i+1]);
		}
		for (int i=1;i<=n;++i)
		{
			L[i]=max(L[i],L[i-1]);
			R[n-i+1]=max(R[n-i+1],R[n-i+2]);
		}
		for (int i=1;i<=n;++i)
			if (L[i]+R[i+1]>=m)
			{
				++ans;
				break;
			}
	}
	cout<<ans<<endl;
	return 0;
}