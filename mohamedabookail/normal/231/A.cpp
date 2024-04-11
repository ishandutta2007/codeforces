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
	int ans = 0;
	while(n--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(a && b || a && c || b && c)
			ans++;
	}
	cout << ans << endl;
}