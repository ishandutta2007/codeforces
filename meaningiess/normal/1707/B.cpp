#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010],b[100010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,j,c0=0;cin>>n;
		for (i=1;i<=n;i++) {cin>>a[i];if (!a[i]) c0++;}
		for (i=n;i>1;i--)
		{
			//cout<<c0<<' ';for (j=c0+1;j<=i;j++) cout<<a[j]<<' ';cout<<endl;
			int cnt=0,flg=0;if (c0) b[++cnt]=a[c0+1],flg=1;
			for (j=c0+2;j<=i;j++)
			{
				if (a[j]!=a[j-1]) b[++cnt]=a[j]-a[j-1];
				else c0++;
			}
			sort(b+1,b+cnt+1);c0-=flg;
			for (j=c0+1;j<=i-1;j++) a[j]=b[j-c0];
		}
		if (c0) cout<<0<<endl;
		else cout<<a[1]<<endl;
	}
}