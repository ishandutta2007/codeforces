#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> m = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, list;
	for (int i = 1895; i < 1905; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (j == 1 && i % 4 == 0 && i % 100 != 0)
				list.push_back(m[j] + 1);
			else
				list.push_back(m[j]);
		}
	}
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < list.size() - n + 1; i++)
	{
		bool f = true;
		for (int j = i; j < i + n; j++)
			if (list[j] != a[j - i])
			{
				f = false;
				break;
			}
		if (f)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
	return 0;
}