#include <bits/stdc++.h>
using namespace std;


signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int l, r;
		cin >> l >> r;
		if(l * 2 >= r + 1)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}