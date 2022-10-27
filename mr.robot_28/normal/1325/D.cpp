#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int u, v;
	cin >> u >> v;
	if(u > v)
	{
		cout << -1;
		return 0;
	}
	if(v == 0)
	{
		cout << 0;
		return 0;
	}
	v -= u;	
	if(v % 2 != 0)
	{
		cout << -1;
		return 0;
	}
	v = v / 2;
	if(v == 0)
	{
		cout << 1 << "\n";
		cout << u;
		return 0;
	}
	if((v & u) != 0)
	{
		cout << 3 << "\n";
		cout << u << " " << v << " " << v;
		return 0;
	}
	cout << 2 << "\n";
	cout << u + v << " " << v;
	return 0;
}