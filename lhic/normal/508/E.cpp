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


typedef long long ll;
typedef long double ld;

using namespace std;


vector<string> v;

int n;
int l[1000];
int r[1000];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> l[i] >> r[i];
	for (int i = n - 1; i >= 0; --i)
	{
		if (l[i] == 1)
		{
			v.push_back("()");
			continue;
		}
		int sz = 1;
		string s = "(";
		for (int j = v.size() - 1; j >= 0; --j)
		{
			if (sz >= l[i])
				break;
			sz += v[j].size();
			s += v[j];
			v.pop_back();
		}
		if (sz < l[i] || sz > r[i])
		{
			cout << "IMPOSSIBLE";
			return 0;
		}
		s += ")";
		v.push_back(s);
	}
	for (int j = v.size() - 1; j >= 0; --j)
		cout << v[j];
	return 0;
}