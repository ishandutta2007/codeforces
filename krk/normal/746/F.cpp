#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, w, k;
int a[Maxn];
int t[Maxn];
int lim;
multiset <int> good, bad;
ll tot, opt;
ll sat;
ll best;

void Add(int len, int s)
{
	tot += len; sat += s;
	opt += (len + 1) / 2; good.insert(len / 2);
	if (good.size() > lim) {
		opt += *good.begin();
		bad.insert(*good.begin()); good.erase(good.begin());
	} 
}

void Rem(int len, int s)
{
	tot -= len; sat -= s;
	if (bad.find(len / 2) != bad.end()) {
		bad.erase(bad.lower_bound(len / 2)); opt -= len;
	} else {
		good.erase(good.lower_bound(len / 2)); opt -= (len + 1) / 2;
	}
	while (good.size() < lim && bad.size() > 0) {
		multiset <int>::iterator it = bad.end(); it--;
		opt -= *it;
		good.insert(*it); bad.erase(it);
	}
}

void Case1()
{
	lim = w - 1;
	int l = 0;
	for (int r = 0; r < n; r++) {
		while (l < r && opt > k - (t[r] + 1) / 2) {
			Rem(t[l], a[l]); l++;
		}
		if ((t[r] + 1) / 2 <= k && tot >= k - t[r] + 1) best = max(best, sat + a[r]);
		Add(t[r], a[r]);
	}
	while (l < n) {
		Rem(t[l], a[l]); l++;
	}
}

void Case2()
{
	lim = w;
	int l = 0;
	for (int r = 0; r < n; r++) {
		while (l < r && opt > k) {
			Rem(t[l], a[l]); l++;
		}
		if (tot >= k - (t[r] - 1) / 2) best = max(best, sat);
		Add(t[r], a[r]);
	}
	while (l < n && opt > k) {
		Rem(t[l], a[l]); l++;
	}
	best = max(best, sat);
	while (l < n) {
		Rem(t[l], a[l]); l++;
	}
}

int main()
{
	scanf("%d %d %d", &n, &w, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	Case1(); Case2();
	cout << best << endl;
	return 0;
}