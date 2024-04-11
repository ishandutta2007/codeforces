#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <sstream>
#include <complex>
#include <string>
#include <cstring>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int res = 6;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int cnt = 0;
			for (int c = 0; c < 6; c++)
			{
				if (a[i][c] != a[j][c])
					cnt++;
			}
			res = min(res, (cnt - 1) / 2);
		}
	}
	cout << res << endl;
}