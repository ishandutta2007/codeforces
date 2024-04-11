#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

typedef unsigned int uint;

const int Maxn = 100005;

int n, k;
uint ip[Maxn];
set <uint> S;

int toInt(const string &s)
{
	stringstream ss(s);
	int res; ss >> res;
	return res;
}

uint getUint(const string &s)
{
	uint res = 0;
	int v = s.find('.');
	res = toInt(s.substr(0, v)) << 24;
	int u = s.find('.', v + 1);
	res += toInt(s.substr(v + 1, u - v - 1)) << 16;
	v = u; u = s.find('.', v + 1);
	res += toInt(s.substr(v + 1, u - v - 1)) << 8;
	v = u; 
	res += toInt(s.substr(v + 1));
	return res;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		ip[i] = getUint(s);
	}
	int i;
	for (i = 1; i <= 31; i++) {
		uint mask = (1 << i) - 1 << 32 - i;
		S.clear();
		for (int j = 0; j < n; j++)
			S.insert(ip[j] & mask);
		if (S.size() == k) break;
	}
	if (i <= 31) {
		uint mask = (1 << i) - 1 << 32 - i;
		printf("%d.%d.%d.%d\n", mask / (1 << 24), mask % (1 << 24) / (1 << 16), mask % (1 << 16) / (1 << 8), mask % (1 << 8));
	} else printf("-1\n");
	return 0;
}