#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <unordered_map>

typedef long long ll;
typedef long double ld;

using namespace std;

int n;
unordered_map<int, int> mm;

pair<int, int> arr[400];


int gcd(int a, int b)
{
	while (b)
	{
		int q = a % b;
		a = b;
		b = q;
	}
	return a;
}

vector<pair<int, int> > vv;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i].first;
	for (int i = 0; i < n; ++i)
		cin >> arr[i].second;
	for (int i = 0; i < n; ++i)
	{
		vv.clear();
		if (mm[arr[i].first] == 0)
			mm[arr[i].first] = arr[i].second;
		else
			mm[arr[i].first] = min(mm[arr[i].first], arr[i].second);
		for (auto it = mm.begin(); it != mm.end(); ++it)
		{
			int k = gcd(arr[i].first, it->first);
			//cout << k << "\n";
			vv.push_back({k, it->second + arr[i].second});
		}
		for (int j = 0; j < vv.size(); ++j)
		{
			int *p = &mm[vv[j].first];	
			if (*p == 0)
				*p = vv[j].second;
			else
				*p = min(*p, vv[j].second);
		}
	}
	if (mm[1] == 0)
		cout << -1;
	else
		cout << mm[1];
	return 0;
}