#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <string> s1(n), s2(m);
	for(int i = 0; i <  n; i++)
	{
		cin >> s1[i];
	}
	for(int i = 0; i < m; i++)
	{
		cin >> s2[i];
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int y;
		cin >> y;
		int k1 = (y - 1 + n) % n;
		int k2 = (y - 1 + m) % m;
		cout << s1[k1] << s2[k2] << "\n";
	} 
	return 0;
}