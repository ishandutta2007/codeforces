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

int n;
string W;
int mask;
int m;
string S;
int safe;

int main()
{
	scanf("%d", &n);
	cin >> W;
	for (int i = 0; i < n; i++)
		if (W[i] != '*') mask |= 1 << int(W[i] - 'a');
	safe = (1 << 26) - 1;
	cin >> m;
	while (m--) {
		cin >> S;
		string tocomp = S;
		for (int i = 0; i < S.length(); i++)
			if (!(mask & 1 << int(S[i] - 'a'))) tocomp[i] = '*';
		if (tocomp == W) {
			int my = 0;
			for (int i = 0; i < S.length(); i++)
				if (tocomp[i] == '*') my |= 1 << int(S[i] - 'a');
			safe &= my;
		}
	}
	int res = __builtin_popcount(safe);
	printf("%d\n", res);
	return 0;
}