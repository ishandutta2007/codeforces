#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

int dangyeu[710][710];
int a[500005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int lol=sqrt(500000);
	int q;
	cin>>q;
	for(int i=1; i<=q; i++)
	{
		int t, x, y;
		cin>>t>>x>>y;
		if(t==1)
		{
			a[x]+=y;
			for(int dr=1; dr<=lol; dr++)
			{
				dangyeu[dr][x%dr]+=y;
			}
			continue;
		}
		if(x>lol)
		{
			int ax=0;
			for(int dora=y; dora<=500000; dora+=x)
			{
				ax+=a[dora];
			}
			cout<<ax<<endl;
		}
		else
		{
			cout<<dangyeu[x][y]<<endl;
		}
	}
	
}