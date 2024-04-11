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

typedef pair <int, int> ii;
typedef long long ll;

const int Maxm = 1000001;

vector <ii> vals[Maxm];
int t;
int x, p, k;

ll Get(int p, int n)
{
	ll res = 0;
	for (int i = 0; i < vals[p].size(); i++)
		res += ll(vals[p][i].second) * (n / vals[p][i].first);
	return res;
}

int main()
{
	for (int i = 1; i < Maxm; i++)
		vals[i].push_back(ii(1, 1));
	for (int i = 2; i < Maxm; i++)
		for (int j = i; j < Maxm; j += i) {
			int got = 0;
			for (int k = 0; k < vals[j].size(); k++)
				if (i % vals[j][k].first == 0) got -= vals[j][k].second;
			vals[j].push_back(ii(i, got));
		}
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &x, &p, &k);
		k += Get(p, x);
		int lef = 1, rig = 1000000000;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (Get(p, mid) >= k) rig = mid - 1;
			else lef = mid + 1;
		}
		printf("%d\n", rig + 1);
	}
	return 0;
}