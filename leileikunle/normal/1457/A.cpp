#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int m,n,r,c;
		cin>>n>>m>>r>>c;
		int maxn1 = max(n-r,r-1);
		int maxn2 = max(m-c,c-1);
		cout<<maxn1+maxn2<<endl;
	}
 }