#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int Maxm = 710;
const int lim = 1000000000;

int n, q;
ll a[Maxn];
map <int, int> M[Maxm];
ll add[Maxm];

void addOne(int mind, int ind, int val) 
{
	if (a[ind] > lim) return;
	map <int, int>::iterator it = M[mind].find(a[ind]);
	if (it->second == 1) M[mind].erase(it);
	else it->second--;
	a[ind] += val;
	if (a[ind] <= lim) M[mind][a[ind]]++;
}

void Add(int l, int r, int val)
{
	while (l <= r && l % Maxm) {
		addOne(l / Maxm, l, val);
		l++;
	}
	while (l <= r && r % Maxm != Maxm - 1) {
		addOne(r / Maxm, r, val);
		r--;
	}
	if (l > r) return;
	int from = l / Maxm, to = r / Maxm;
	for (int i = from; i <= to; i++)
		add[i] += val;
}

int getMinimum(int val)
{
	map <int, int>::iterator it;
	for (int i = 0; i < Maxm; i++) {
		ll nd = val - add[i];
		if (nd < 0) continue;
		it = M[i].find(nd);
		if (it != M[i].end())
			for (int j = i * Maxm; ; j++)
				if (a[j] == nd) return j;
	}
	return -1;
}

int getMaximum(int val)
{
	map <int, int>::iterator it;
	for (int i = Maxm - 1; i >= 0; i--) {
		ll nd = val - add[i];
		if (nd < 0) continue;
		it = M[i].find(nd);
		if (it != M[i].end())
			for (int j = (i + 1) * Maxm - 1; ; j--)
				if (a[j] == nd) return j;
	}
	return -1;
}

int getF(int val)
{
	int mn = getMinimum(val);
	if (mn == -1) return -1;
	return getMaximum(val) - mn;
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
		M[i / Maxm][a[i]]++;
	}
	while (q--) {
		int typ, l, r, val;
		scanf("%d", &typ);
		if (typ == 1) {
			scanf("%d %d %d", &l, &r, &val); l--; r--;
			Add(l, r, val);
		} else if (typ == 2) {
			int y; scanf("%d", &y);
			printf("%d\n", getF(y));
		}
	}
	return 0;
}