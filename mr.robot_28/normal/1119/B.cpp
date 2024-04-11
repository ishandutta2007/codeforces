#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, h;
	cin>> n >> h;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int l = -1, r = n;
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		vector <int> b;
		for(int i = 0; i <= midd; i++)
		{
			b.push_back(a[i]);
		}
		sort(b.begin(), b.end());
		int sum = 0;
		for(int i = b.size() - 1; i >= 0; i -= 2)
		{
			sum += b[i];
		}
		if(sum <= h)
		{
			l = midd;
		}
		else
		{
			r =midd;
		}
	}
	cout << l + 1;
	return 0;
}