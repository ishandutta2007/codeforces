/**
 *    author:  Mohamed.Abo_Okail
 *    created: 26/11/2019
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
	int mx = -1, c = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if(s[i] == 'x') c++;
		else 
		{
			ans += max(c - 2, 0);
			c = 0;
		}
	}
	ans += max(c - 2, 0);
	cout << ans << endl;
}