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
	
	string s; cin >> s;
	ll ans = 0, c = 0;
	int f = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] == '+' || s[i] == '-')
		{
			ans += c * f;
			((s[i] == '+') ? f = 1 : f = -1);
			c = 0;
		}
		c = (c * 10) + (s[i] - '0');
	}
	ans += c * f;

	cout << ans << endl;

}