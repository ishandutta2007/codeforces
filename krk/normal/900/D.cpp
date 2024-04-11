#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

int x, y;
vector <int> dvs;
vector <int> res;

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int main()
{
	scanf("%d %d", &x, &y);
	if (y % x) { printf("0\n"); return 0; }
	for (int i = 1; i * i <= y; i++) if (y % i == 0) {
		dvs.push_back(i);
		if (i * i < y) dvs.push_back(y / i);
	}
	sort(dvs.begin(), dvs.end());
	int ind = lower_bound(dvs.begin(), dvs.end(), x) - dvs.begin();
	res.resize(dvs.size(), 0);
	for (int i = int(dvs.size()) - 1; i >= ind; i--) {
		res[i] = toPower(2, y / dvs[i] - 1);
		for (int j = i + 1; j < dvs.size(); j++) if (dvs[j] % dvs[i] == 0)
			res[i] = (res[i] - res[j] + mod) % mod;
	}
	printf("%d\n", res[ind]);
	return 0;
}