#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long a,b,n,m;
		cin >> a >> b >> n >> m;
		if (a<b)
		swap(a,b);
		long long tmp=min(a-b,n);
		a-=tmp;
		n-=tmp;
		if (a+b>=n+m && b>=m)
		puts("Yes");
		else
		puts("No");
	}
}