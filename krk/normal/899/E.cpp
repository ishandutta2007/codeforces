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

const int Maxn = 200005;

int n;
int a[Maxn];
set <ii> S, Q;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0, j; i < n; i = j) {
		j = i;
		while (j < n && a[i] == a[j]) j++;
		S.insert(ii(i, j - i)); Q.insert(ii(-(j - i), i));
	}
	while (!Q.empty()) {
		int ind = Q.begin()->second; Q.erase(Q.begin());
		res++;
		set <ii>::iterator it = S.lower_bound(ii(ind, 0)), lef, rig;
		lef = it, rig = it;
		if (lef != S.begin()) {
			lef--;
			rig++;
			if (rig != S.end())
				if (a[lef->first] == a[rig->first]) {
					Q.erase(ii(-lef->second, lef->first));
					Q.erase(ii(-rig->second, rig->first));
					ii nw = ii(lef->first, lef->second + rig->second);
					S.erase(lef); S.erase(rig);
					S.insert(nw); Q.insert(ii(-nw.second, nw.first));
				}
		}
		S.erase(it);
	}
	printf("%d\n", res);
	return 0;
}