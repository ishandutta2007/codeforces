/**
 *    author:  Mohamed.Abo_Okail
 *    created: 24/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	

	int n; cin >> n;
	map <int, int> mp;
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		mp[a]++;
		ans = max(ans, mp[a]);
	}
	cout << ans << endl;
}