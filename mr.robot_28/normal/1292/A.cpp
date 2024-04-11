#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector <vector <bool> > used(2, vector <bool> (n));
	int cnt = 0;
	for(int i =0; i < q; i++)
	{
		int type, s;
		cin >> type >> s;
		s--;
		type--;
			if(used[type][s])
			{
				if(s != 0 && used[1 - type][s - 1])
				{
					cnt--;
				}
				if(s != n - 1 && used[1 - type][s + 1])
				{
					cnt--;
				}
				if(used[1 - type][s])
				{
					cnt--;
				}
			}
			else
			{
				if(s != 0 && used[1 - type][s - 1])
				{
					cnt++;
				}
				if(s != n - 1 && used[1 - type][s + 1])
				{
					cnt++;
				}
				if(used[1 - type][s])
				{
					cnt++;
				}
			}
			used[type][s] = !used[type][s];
		if(cnt == 0)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
	return 0;
}