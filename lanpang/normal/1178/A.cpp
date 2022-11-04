#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[110] , s , ss;
vector<int> v;

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		s += a[i];
		if (i == 1 || a[i]*2 <= a[1]) 
		{
			ss += a[i];
			v.push_back(i);
		}
	}
	if (ss*2 > s)
	{
		cout << (int)v.size() << "\n";
		for (auto i: v)
			cout << i << " ";
		cout << "\n";
	}
	else cout << "0\n";
	return 0;
}