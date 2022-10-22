#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010];
int main()
{
	int T;cin>>T;a[0]=1e9;
	while (T--)
	{
		int n,i,x,ans;cin>>n;ans=n;
		for (i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cin>>x;ll lst=0;int flg=1;
		for (i=1;i<=n;i++) a[i]-=x;
		for (i=1;i<=n;i++) if (flg) lst=a[i],flg=0;
		else
		{
			if (lst+a[i]<0)
			{
				ans--;flg=1;lst=0;
			}
			if (lst>0) lst=0;lst+=a[i];
		}
		cout<<ans<<endl;
	}
}