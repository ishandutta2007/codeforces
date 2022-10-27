#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> c(n);
	int min1 = 1e9, c1 = 1e9;
	int min2 = 1e9, c2 = 1e9;
	int delta = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
		if(c1 != c[i])
		{
			delta = max(delta, i - min1);
		}
		else
		{
			delta = max(delta, i - min2);
		}
		if(min1 == 1e9)
		{
			min1 = i;
			c1 = c[i];
		}
		else if(min2 == 1e9 && c[i] != c1)
		{
			min2 = i;
			c2 = c[i];
		}
	}
	cout << delta;
	return 0;
}