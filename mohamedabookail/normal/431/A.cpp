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
	
	int arr[5];
	cin >> arr[1] >> arr[2] >> arr[3] >> arr[4];
	string s; cin >> s;
	ll ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		ans += arr[s[i] - '0'];
	}
	cout << ans << endl;
}