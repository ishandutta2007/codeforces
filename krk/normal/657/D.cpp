#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef long double ld;

const int Maxn = 200005;

int n;
ii pt[Maxn];
ld T;
ld mnpoints[Maxn], mxpoints[Maxn];
int ind[Maxn];

bool Eq(const ii &a, const ii &b)
{
	return ll(a.first) * ll(b.second) == ll(b.first) * ll(a.second);
}

bool Less(const ii &a, const ii &b)
{
	if (ll(a.first) * ll(b.second) != ll(b.first) * ll(a.second))
		return ll(a.first) * ll(b.second) > ll(b.first) * ll(a.second);
	return a.first < b.first;
}

bool Less2(const int &a, const int &b)
{
	return pt[a].first > pt[b].first;
}

bool Paradox(ld c)
{
	ld tim = 0.0;
	for (int i = 0, j; i < n; i = j) {
		ld sum = 0.0l;
		j = i;
		while (j < n && Eq(pt[i], pt[j])) {
			sum += pt[j].second;
			j++;
		}
		j = i;
		while (j < n && Eq(pt[i], pt[j])) {
			mnpoints[j] = ld(pt[j].first) * (1.0l - c * (tim + sum) / T);
			mxpoints[j] = ld(pt[j].first) * (1.0l - c * (tim + ld(pt[j].second)) / T);
			j++;
		}
		tim += sum;
	}
	ld mn = 1e9l;
	for (int i = 0, j; i < n; i = j) {
		j = i;
		ld mymn = 1e9l;
		while (j < n && pt[ind[i]].first == pt[ind[j]].first) {
			if (mn < mxpoints[ind[j]]) return true;
			mymn = min(mymn, mnpoints[ind[j]]);
			j++;
		}
		mn = min(mn, mymn);
	}
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &pt[i].first);
	for (int i = 0; i < n; i++) {
		scanf("%d", &pt[i].second);
		T += pt[i].second;
	}
	sort(pt, pt + n, Less);
	for (int i = 0; i < n; i++)
		ind[i] = i;
	sort(ind, ind + n, Less2);
	ld lef = 0, rig = 1;
	for (int i = 0; i < 40; i++) {
		ld mid = (lef + rig) / 2.0l;
		if (Paradox(mid)) rig = mid;
		else lef = mid;
	}
	cout << fixed << setprecision(10) << lef << endl;
	return 0;
}