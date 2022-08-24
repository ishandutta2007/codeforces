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


int main()
{
	ll x1, y1;
	ll x2, y2;
	
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		if (((a * x1 + b * y1 + c) < 0) != ((a * x2 + b * y2 + c) < 0))
			++cnt;
	}
	
	cout << cnt;
	
	return 0;
}