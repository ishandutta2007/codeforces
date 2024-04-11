/**
 *    author:  Mohamed.Abo_Okail
 *    created: 08/11/2019
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
		int n; cin >> n;
		vector <int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		int ans = 0;
		sort(v.begin(), v.end());
		for (int i = (n - 1); i >= 0; i--)
		{
			if(ans < v[i]) ans++;
		}
		cout << ans << endl;
	}
}