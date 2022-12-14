#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int maxn = max(a,max(b,c));
	int minn = min(a,min(b,c));
	cout<<maxn - minn;
}