#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
int s[10];
int n;
char a[maxn],b[maxn];
int main()
{
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	for (int i=1;i<=n;i++)
	{
		if (a[i]=='0' && b[i]=='0')	s[0]++;
		if (a[i]=='1' && b[i]=='0')	s[1]++;
		if (a[i]=='0' && b[i]=='1')	s[2]++;
		if (a[i]=='1' && b[i]=='1')	s[3]++;
	}
	long long ans=0;
	for (int i=0;i<4;i++)
		for (int j=i+1;j<4;j++)
		{
			int a1,b1,a2,b2;
			if (i==0)	a1=0,b1=0;
			if (i==1)	a1=1,b1=0;
			if (i==2)	a1=0,b1=1;
			if (i==3)	a1=1,b1=1;
			if (j==0)	a2=0,b2=0;
			if (j==1)	a2=1,b2=0;
			if (j==2)	a2=0,b2=1;
			if (j==3)	a2=1,b2=1;
			if ((a1|b1)!=(a2|b1) || (a2|b2)!=(a1|b2))
			{
				ans+=s[i]*1LL*s[j];
			}
		}
	cout<<ans<<endl;
	return 0;
}