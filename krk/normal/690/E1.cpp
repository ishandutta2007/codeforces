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

const int Maxn = 606;

int q;
int h, w;
int B[Maxn][Maxn];

int main()
{
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &h, &w);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf("%d", &B[i][j]);
		vector <int> tmp;
		for (int i = 0; i + 1 < h; i++) {
			int sum = 0;
			for (int j = 0; j < w; j++)
				sum += abs(B[i][j] - B[i + 1][j]);
			tmp.push_back(sum);
		}
		sort(tmp.begin(), tmp.end());
		int i = h / 2 - 1;
		int my = 0;
		for (int j = 0; j < w; j++)
			my += abs(B[i][j] - B[i + 1][j]);
		int ind = lower_bound(tmp.begin(), tmp.end(), my) - tmp.begin();
		if (ind > 7 * tmp.size() / 8) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}