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

const int Maxn = 105;

string my;
int n;
string W[Maxn];

int main()
{
	cin >> my;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> W[i];
		if (my == W[i] || my[0] == W[i][1] && my[1] == W[i][0]) { printf("YES\n"); return 0; }
		for (int j = 0; j < i; j++)
			if (my[0] == W[j][1] && my[1] == W[i][0] ||
				my[0] == W[i][1] && my[1] == W[j][0]) { printf("YES\n"); return 0; }
	}
	printf("NO\n");
	return 0;
}