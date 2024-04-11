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

ll st[100];
ll en[100];

void init() {
	ll lst = 1988;
	ll pw = 1;
	for (int i = 1; i <= 9; ++i) {
		pw *= 10;
		++lst;
		st[i] = lst;
		en[i] = lst  + pw - 1;
		lst += pw - 1;
	}
}

ll solve(string s) {
	int k = s.size();
	ll pw = 1;
	for (int i = 0; i < k; ++i)
		pw *= 10;
	ll n = atoi(s.c_str());
	ll d = n - st[k] % pw;
	if (d < 0)
		d += pw;
	return st[k] + d;
}

int main() {
	init();
	int tt;
	scanf("%d", &tt);
	for (int it = 0; it < tt; ++it) {
		scanf(" IAO'");
		string s;
		cin >> s;
		cout << solve(s) << "\n";
	}
	return 0;
}