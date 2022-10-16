#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<bool> aware(n);
	vector<pair<int, int> > res;
	aware[0] = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int t = 0; t < n; t++) 
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				if (aware[i] && !aware[j] && a[i] && a[j]) {
					res.push_back({ i + 1, j + 1 });
					a[i]--;
					aware[j] = true;
				}
	for (int t = 0; t < n; t++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (aware[i] && !aware[j] && a[i]) {
					res.push_back({ i + 1, j + 1 });
					a[i]--;
					aware[j] = true;
				}
	
	for (int i = 0; i < n; i++)
		if (!aware[i])
			return cout << -1 << endl, 0;
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i].first << ' ' << res[i].second << endl;
	return 0;
}