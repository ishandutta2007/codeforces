#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <bitset>


using namespace std;

typedef long long ll;
typedef long double ld;

int n, t;
int x;

int a[100000];

int main()
{
	cin >> n >> t;
	a[0] = 1;
	--t;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> x;
		a[i + x] |= a[i];
	}
	if (a[t])
		cout << "YES";
	else
		cout << "NO";
	return 0;
}