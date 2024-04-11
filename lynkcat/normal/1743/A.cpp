#include<bits/stdc++.h>
using namespace std;
int n;
void fc()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
	}
	cout<<(9-n)*(10-n)*3<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		fc();
	}
}