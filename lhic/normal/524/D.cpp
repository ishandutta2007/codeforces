#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

int n, m;
int t;
int s[30000];
int cl[30000];

int main() {
	scanf("%d%d", &n, &m);
	scanf("%d", &t);
	int now = 0;
	int mx = 0;
	for (int i = 0; i < n; ++i){
		int h, m, se;
		scanf("%d:%d:%d", &h, &m, &se);
		s[i] = h * 3600 + m * 60 + se;
	}

	int nc = 0;
	for (int i = 0; i < n; ++i) {
		while (s[i] - s[now] >= t)
			++now;
		if (now != i && nc + 1 - cl[now] +  1 > m)
			cl[i] = nc;
		else
			cl[i] = ++nc;
		mx = max(mx, cl[i] - cl[now] + 1);
	}

	if (mx != m)
		cout << "No solution";
	else {
		cout << cl[n - 1] << "\n";
		for (int i = 0; i < n; ++i)
			cout << cl[i] << "\n";
	}

	return 0;
}