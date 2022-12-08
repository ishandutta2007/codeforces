#include <bits/stdc++.h>

using namespace std;

int n;
int at[100005];

int bit[200005];
void update(int pos)
{
	while(pos<=150000)
	{
		bit[pos]++;
		pos+=pos&-pos;
	}
}

int get(int pos)
{
	int ans=0;
	while(pos)
	{
		ans+=bit[pos];
		pos-=pos&-pos;
	}
	return ans;
}

signed main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		int ok;
		cin>>ok;
		at[ok]=i;
	}
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		int ok;
		cin>>ok;
		update(at[ok]);
		if(get(at[ok])<at[ok])
		{
			ans++;
		}
	}
	cout<<ans;
}