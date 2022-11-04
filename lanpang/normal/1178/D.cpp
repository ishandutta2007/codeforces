#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 998244353;

int n , f[maxn] , ff[maxn];
vector<int> v , vv;

int main()
{
	int i , j;
	cin >> n;
	for (i = 2 ; i <= 2000 ; i++)
	{
		if (f[i]) continue;
		for (j = i+i ; j <= 2000 ; j += i)
			f[j] = 1;
	}
	for (i = 1 ; i <= n ; i++)
	{
		v.push_back(i);
		vv.push_back(i%n+1);
	}
	i = 0;
	while (f[(int)v.size()])
	{
		i++;
		if (ff[i] || ff[i+2]) continue;
		v.push_back(i);
		vv.push_back(i+2);
		ff[i] = 1;
		ff[i+2] = 1;
	}
	cout << (int)v.size() << "\n";
	for (i = 0 ; i < v.size() ; i++)
		cout << v[i] << " " << vv[i] << "\n";
	return 0;
}