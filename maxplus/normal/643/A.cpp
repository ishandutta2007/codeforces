#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const long long mod = 10;
const long long people = 70000 * mod, otpet = 600000 * mod;
int main()
{
	//cin.tie(nullptr), ios::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<int> res(n);
	int ak = 0;
	for (int i = 0; i < n; i++)
	{
		int winind = 0;
		vector<int> am(n);
		for (int j = i; j < n; j++)
		{
			am[a[j] - 1]++;
			if (am[a[j] - 1] > am[winind] || (am[a[j] - 1] == am[winind] && a[j] - 1 < winind))
				winind = a[j] - 1;
			res[winind]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}