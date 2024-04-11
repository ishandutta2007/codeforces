#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1000000;
bool mark[MAX * 2 + 10];
int a[1000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		vector<int> ans;
		for (int i = MAX; i >= 0; i--)
		{
			bool valid = true;
			for (int j = 0; j < n; j++)
				if (mark[a[j] + i])
				{
					valid = false;
					break;
				}
			if (valid)
			{
				for (int j = 0; j < n; j++)
					mark[a[j] + i] = true;
				ans.push_back(i);
				if (ans.size() == n)
					break;
			}
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << "\n";
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mark[a[i] + ans[j]] = false;
	}
	return 0;
}