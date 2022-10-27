#include<bits/stdc++.h>
using namespace std;

signed main() {
	int t;
	cin >> t;
	while(t--)
	{
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		int max1 = 0, max2 = 0;
		for(int i =0; i < k1; i++)
		{
			int a;
			cin >> a;
			max1 = max(max1, a);
		}
		for(int i = 0; i < k2; i++)
		{
			int a;
			cin >> a;
			max2 = max(max2, a);
		}
		if(max1 > max2)
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