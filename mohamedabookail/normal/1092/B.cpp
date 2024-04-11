/**
 *    author:  Mohamed.Abo_Okail
 *    created: 21/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int n; cin >> n;
	vector <int> v(n);
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i += 2)
	{
		ans += abs(v[i] - v[i + 1]);
	}

	cout << ans << endl;
}