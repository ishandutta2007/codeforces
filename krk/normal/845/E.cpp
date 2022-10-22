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
typedef pair <ll, ll> llll;

const ll Inf = 2000000000;
const int Maxk = 505;

int n, m, k;
int X[Maxk], Y[Maxk];

int Get(ll rad)
{
	vector <ll> my;
	for (int i = 0; i < k; i++) {
		my.push_back(max(1ll, X[i] - rad));
		if (X[i] + rad + 1 <= n)
			my.push_back(X[i] + rad + 1);
	}
	my.push_back(1);
	sort(my.begin(), my.end()); my.erase(unique(my.begin(), my.end()), my.end());
	vector <vector <llll> > I(my.size());
	for (int i = 0; i < k; i++) {
		int ind = lower_bound(my.begin(), my.end(), max(1ll, X[i] - rad)) - my.begin();
		I[ind].push_back(llll(max(1ll, Y[i] - rad), 1ll));
		if (Y[i] + rad + 1 <= m)
			I[ind].push_back(llll(Y[i] + rad + 1, -1ll));
		if (X[i] + rad + 1 <= n) {
			ind = lower_bound(my.begin(), my.end(), X[i] + rad + 1) - my.begin();
			I[ind].push_back(llll(max(1ll, Y[i] - rad), -1ll));
			if (Y[i] + rad + 1 <= m)
				I[ind].push_back(llll(Y[i] + rad + 1, 1ll));
		}
	}
	map <ll, ll> M; M[1] = 0;
	for (int i = 0; i < my.size(); i++) {
		for (int j = 0; j < I[i].size(); j++)
			M[I[i][j].first] += I[i][j].second;
		ll cur = 0;
		for (map <ll, ll>::iterator it = M.begin(); it != M.end(); it++) {
			cur += it->second;
			if (cur == 0) return my[i];
		}
	}
	return n + 1;
}

bool checkRows(ll rad)
{
	int row = Get(rad);
	if (row <= n) {
		for (int i = 0; i < k; i++)
			X[i] = n + 1 - X[i];
		int row2 = n + 1 - Get(rad);
		for (int i = 0; i < k; i++)
			X[i] = n + 1 - X[i];
		return row2 - row <= 2 * rad;
	}
	return true;
}

bool checkCols(ll rad)
{
	swap(n, m);
	for (int i = 0; i < k; i++)
		swap(X[i], Y[i]);
	bool res = checkRows(rad);
	for (int i = 0; i < k; i++)
		swap(X[i], Y[i]);
	swap(n, m);
	return res;
}

bool Check(ll rad)
{
	return checkRows(rad) && checkCols(rad);
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++)
		scanf("%d %d", &X[i], &Y[i]);
	ll lef = 0, rig = Inf;
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		if (Check(mid)) rig = mid - 1ll;
		else lef = mid + 1ll;
	}
	printf("%I64d\n", lef);
	return 0;
}