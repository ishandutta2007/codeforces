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
	
	ll n; cin >> n;
	int arr[] = {1, 5, 10, 20, 100};
	int ans = 0;
	for (int i = 4; i >= 0; i--)
	{
		ans += n / arr[i];
		n %= arr[i];
	}
	cout << ans << endl;
}