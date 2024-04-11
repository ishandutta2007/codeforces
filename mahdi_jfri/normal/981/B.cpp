#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

map<int , int> mp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int _ = 0; _ < 2; _++)
	{
		int n;
		cin >> n;

		for(int i = 0; i < n; i++)
		{
			int x , y;
			cin >> x >> y;

			mp[x] = max(mp[x] , y);
		}
	}

	ll res = 0;
	for(auto shit : mp)
		res += shit.second;

	cout << res << endl;

}