/**
 *    author:  Mohamed.Abo_Okail
 *    created: 20/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int n; cin >> n;
	string s; cin >> s;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		if(!((s[i] - '0') % 2))
			ans += (i + 1);
	}

	cout << ans << endl;
}