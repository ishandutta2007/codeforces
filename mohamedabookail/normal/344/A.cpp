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
	
	int n; cin >> n;
	vector <int> v(n + 1);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	v[n] = -1;
	for (int i = 0; i < n; i++)
	{
		if(v[i] != v[i + 1]) {
			ans++;
		}
	}
	cout << ans << endl;
}