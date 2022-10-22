#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[111];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,j,k,s=0;cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i++)
		{
			for (j=i;j<=n;j++)
			{
				for (k=i;k<=j;k++) if (a[k])s++;else s+=2;
			}
		}
		cout<<s<<endl;
	}
}