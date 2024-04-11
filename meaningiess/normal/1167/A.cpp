#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;cin>>T;char a[111];
	while (T--)
	{
		int n,i;cin>>n;cin>>a+1;
		for (i=1;i<=n;i++) if (a[i]=='8') break;
		if (n-i+1>=11) puts("YES");else puts("NO");
	}
}