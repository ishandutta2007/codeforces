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
typedef pair <ii, int> iii;

int n, k;
set <iii> S;
int cnt[3];

int Siz(int lef, int rig) { return rig - lef + 1; }

void updateLeft(int l, int r, int k)
{
	set <iii>::iterator it = S.lower_bound(iii(ii(l + 1, 0), 0));
	if (it != S.begin()) {
		it--;
		if (it->second != k) {
			if (it->first.first < l) {
				S.insert(iii(ii(it->first.first, l - 1), it->second));
				cnt[it->second] += Siz(it->first.first, l - 1);
			}
			if (it->first.second > r) {
				S.insert(iii(ii(r + 1, it->first.second), it->second));
				cnt[it->second] += Siz(r + 1, it->first.second);
			}
			int to = min(r, it->first.second);
			cnt[it->second] -= Siz(it->first.first, it->first.second); S.erase(it); 
			S.insert(iii(ii(l, to), k)); cnt[k] += Siz(l, to);
		}
	}
}

void updateRight(int l, int r, int k)
{
	set <iii>::iterator it = S.lower_bound(iii(ii(r + 1, 0), 0));
	if (it != S.begin()) {
		it--;
		if (it->second != k) {
			if (it->first.first < l) {
				S.insert(iii(ii(it->first.first, l - 1), it->second));
				cnt[it->second] += Siz(it->first.first, l - 1);
			}
			if (it->first.second > r) {
				S.insert(iii(ii(r + 1, it->first.second), it->second));
				cnt[it->second] += Siz(r + 1, it->first.second);
			}
			int to = max(l, it->first.first);
		    cnt[it->second] -= Siz(it->first.first, it->first.second); S.erase(it);
			S.insert(iii(ii(to, r), k)); cnt[k] += Siz(to, r);
		}
	}
}

void Update(int l, int r, int k)
{
	set <iii>::iterator it = S.lower_bound(iii(ii(l + 1, 0), 0));
	if (it != S.begin()) {
		it--;
		int lef = it->first.first, rig = it->first.second;
		while (it != S.end() && it->first.first <= r) {
			rig = it->first.second; 
			cnt[it->second] -= Siz(it->first.first, it->first.second);
			S.erase(it++);
		}
		S.insert(iii(ii(lef, rig), k));
		cnt[k] += Siz(lef, rig);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	cnt[2] = n; S.insert(iii(ii(1, n), 2));
	while (k--) {
		int l, r, k; scanf("%d %d %d", &l, &r, &k);
		updateLeft(l, r, k); updateRight(l, r, k);
		Update(l, r, k);
		printf("%d\n", cnt[2]);
	}
	return 0;
}