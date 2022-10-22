#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int n, t, k, d;
int res, r;

int main()
{
	cin >> n >> t >> k >> d;
	res = (n / k + (n % k != 0)) * t;
	for (int i = 1; i <= n; i++) {
		int tim1 = (i / k + (i % k != 0)) * t;
		int tim2 = d + ((n - i) / k + ((n - i) % k != 0)) * t;
		if (max(tim1, tim2) < res) { res = max(tim1, tim2); r = 1; }
	}
	printf("%s\n", r? "YES": "NO");
	return 0;
}