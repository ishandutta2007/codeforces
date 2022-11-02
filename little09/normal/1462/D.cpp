#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[3005],s[3005];
inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 
int main()
{
	int T=read();
	while (T--)
	{
		cin>>n;
		int ans=n-1;
		for (int i=1;i<=n;i++) 
		{
			a[i]=read();
			s[i]=a[i]+s[i-1];
		}
		for (int i=1;i<=n;i++)
		{
			int sum=s[i],tot=1;
			int now=i+1;
			for (int j=i+1;j<=n;j++)
			{
				if (s[j]-s[now-1]>sum) goto uu;
				else if  (s[j]-s[now-1]==sum)
				{
					now=j+1;
					tot++;
				}
			}
			if (now!=n+1) goto uu;
			//cout << "t" << tot << endl;
			ans=min(ans,n-tot);
			uu:;
		}
		//cout << "ans ";
		cout << ans << endl;
	}
	return 0;
}