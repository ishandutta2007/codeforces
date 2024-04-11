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

int n, k;
vector<int> vv;
int a, b, c, d;
int was[1000000];

int main() {
	scanf("%d%d", &n, &k);
	scanf("%d%d%d%d", &a, &b, &c, &d);
	--a;
	--b;
	--c;
	--d;
	if (k <= n || n == 4) {
		cout << -1 << "\n";
		return 0;
	}
	was[a] = 1;
	was[b] = 1;
	was[c] = 1;
	was[d] = 1;
	vector<int> vv;
	vv.push_back(a);
	vv.push_back(c);
	for (int i = 0; i < n; ++i)
		if (!was[i])
			vv.push_back(i);
	vv.push_back(d);
	vv.push_back(b);
	for (int i = 0; i < n; ++i)
		cout << vv[i] + 1 << " ";
	cout << "\n";
	cout << vv[1] + 1 << " " << vv[0] + 1 << " ";
	for (int i = 2; i < n - 2; ++i)
		cout << vv[i] + 1 << " ";
	cout << vv[n - 1] + 1 << " " << vv[n - 2] + 1 << "\n";
	return 0;
}