/**
 *    author:  Mohamed.Abo_Okail
 *    created: 05/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	
	int t; cin >> t;
	while(t--)
	{
		int n, a, b, x, y;
		cin >> n >> a >> b >> x >> y;
		n /= 2;
		int ans = 0;
		if(x < y)
		{
			swap(x, y);
			swap(a, b);
		}
		ans += (min(a, n) * x) + (min((n - min(a, n)), b) * y);
		cout << ans << endl;
	}
}