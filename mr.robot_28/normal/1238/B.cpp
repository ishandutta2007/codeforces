#include <bits/stdc++.h>

using namespace std;

int main() {
	#define int long long
	int q;
	cin >> q;
	while(q--)
	{
		int n, r;
		cin >> n >> r;
		vector <int> x(n);
		for(int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x.begin(), x.end());
		int ans = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			if(x[i] - ans * r <= 0)
			{
				break;
			}
			if(i == n - 1 || x[i] < x[i + 1])
			{
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}