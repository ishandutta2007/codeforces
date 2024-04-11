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
	vector < pair <int, int> > v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	int k; cin >> k;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if(k <= v[i].second)
		{
			ans = i;
			break;
		}
	}

	cout << n - ans << endl;
}