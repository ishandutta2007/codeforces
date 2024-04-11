#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,f0=0,f1=0,flg=1;cin>>n;
		for (i=1;i<=n;i++)
		{
			cin>>a[i];
			if (a[i]==0 || a[i]==2) f0=1;
			if (a[i]==1) f1=1;
		}
		if (f0 && f1) {puts("NO");continue;}
		sort(a+1,a+n+1);
		for (i=1;i<n;i++) if (a[i+1]-a[i]==1 && f1) {flg=0;break;}
		if (flg) puts("YES");else puts("NO");
	}
}