#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n,p,k,x,y,ans=1e18;
		string s;
		cin >> n >> p >> k >> s >> x >> y;
		p--;
		for (int i=p;i<min(p+k,n);i++)
		{
			int cur,tot=0;
			for (int j=i;j<n;j+=k)
			tot+=(s[j]=='0');
			cur=tot;
			for (int j=i;j<n;j+=k)
			{
				ans=min(ans,min((tot-cur)*x,y*(j-i))+cur*x+(i-p)*y);
				cur-=(s[j]=='0');
			}
		}
		cout << ans << endl;
	}
}