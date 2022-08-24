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


int main() {
	int a, b, ta, tb;
	cin >> a >> ta;
	cin >> b >> tb;
	int h, m;
	scanf("%d:%d", &h, &m);
	m = h * 60 + m;
	int st = 5 * 60;
	int en = 24 * 60;
	int ans = 0;
	for (int i = st; i < en; i += b) {
		if (i < m + ta && i + tb > m)
			++ans;
	}
	cout << ans << "\n";
	return 0;
}