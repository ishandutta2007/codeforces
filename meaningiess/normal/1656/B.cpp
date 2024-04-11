#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int,int> m;int a[200010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,k,flg=0;cin>>n>>k;m.clear();
		for (i=1;i<=n;i++)
		{
			cin>>a[i];
			if (m[a[i]+k] || m[a[i]-k]) flg=1;
			m[a[i]]++;
		}
		if (flg) puts("YES");else puts("NO");
	}
}