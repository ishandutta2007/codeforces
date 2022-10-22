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

typedef long long ll;

const int Maxn = 100005;

int n, S;
int a[Maxn];
vector <ll> seq;

ll getCost(int t)
{
	seq.clear();
	for (int i = 1; i <= n; i++)
		seq.push_back(ll(a[i]) + ll(i) * t);
	sort(seq.begin(), seq.end());
	ll res = 0;
	for (int i = 0; i < t; i++)
		res += seq[i];
	return res;
}

int main()
{
	scanf("%d %d", &n, &S);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int lef = 0, rig = n;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (getCost(mid) > S) rig = mid - 1;
		else lef = mid + 1;
	}
	printf("%d %I64d\n", lef - 1, getCost(lef - 1));
	return 0;
}