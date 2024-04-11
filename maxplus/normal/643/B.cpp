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
	int n, k;
	int a, b, c, d;
	cin >> n >> k;
	cin >> a >> b >> c >> d;
	if (n == 4 || k < n + 1)
	{
		cout << -1 << endl;
		return 0;
	}
	vector<int> fway(n);
	fway[0] = a, fway[1] = c, fway[n - 2] = d, fway[n - 1] = b;
	vector<int> used(n);
	used[a - 1] = true, used[b - 1] = true, used[c - 1] = true, used[d - 1] = true;
	int ind = 2;
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
			fway[ind++] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		cout << fway[i] << ' ';
	}
	cout << endl;
	cout << fway[1] << ' ' << fway[0] << ' ';
	for (int i = 2; i < n - 2; i++)
	{
		cout << fway[i] << ' ';
	}
	cout << fway[n - 1] << ' ' << fway[n - 2] << endl;

	return 0;
}