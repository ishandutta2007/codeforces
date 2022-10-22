#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[55];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,k,i,j;cin>>n>>k;
		for (i=1;i<=n;i++) cin>>a[i];
		int tp=0;
		for (i=1;i<=n;i++) tp=max(tp,a[i]);
		if (!tp) {puts("NO");}else puts("YES");
	}
}