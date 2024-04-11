/**
 *    author:  Mohamed.Abo_Okail
 *    created: 27/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int n, h;
	cin >> n >> h;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		ans += (a <= h) ? 1 : 2;
	}
	cout << ans << endl;
}