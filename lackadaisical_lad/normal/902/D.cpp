#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll E = (ll)1e9 + 7;
const int N = 200100;

vector<int> m[200];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	m[0] = { 1 };
	m[1] = { 0, 1 };
	for (int i = 2; i <= n; i++)
	{
		m[i] = m[i - 1];
		m[i].insert(m[i].begin(), 0);
		bool f = false;
		for (int j = 0; j < m[i - 2].size(); j++)
		{
			m[i][j] += m[i - 2][j];
			if (abs(m[i][j]) > 1)
				f = true;
		}
		if (f)
			for (int j = 0; j < m[i - 2].size(); j++)
			{
				m[i][j] -= m[i - 2][j] * 2;
			}
	}
	cout << n << '\n';
	for (int i : m[n])
		cout << i << ' ';
	cout << '\n';
	cout << n - 1 << '\n';
	for (int i : m[n - 1])
		cout << i << ' ';
	return 0;
}