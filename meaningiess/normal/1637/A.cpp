#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,flg=1;cin>>n;
		for (i=1;i<=n;i++)
		{
			cin>>a[i];
			if (a[i]<a[i-1]) flg=0;
		}
		if (flg) puts("NO");else puts("YES");
	}
}