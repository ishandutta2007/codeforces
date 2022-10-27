#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
const int  CONST = 998244353;
#define int long long
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		if(a > b){
			swap(a, b);
		}
		int k = b - a;
		int w = sqrt(2 * k);
		if(w * (w + 1) < 2 * k)
		{
			w++;
		}
		while((w * (w + 1) / 2) % 2 != k % 2)
		{
			w++;
		}
		cout << w << "\n";
	}
	return 0;
}