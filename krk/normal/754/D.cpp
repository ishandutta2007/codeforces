#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 600015;

int n, k;
int l[Maxn], r[Maxn];
vector <int> un;
int BIT[Maxn];
vector <int> lef;
vector <int> rig;
int res = -1;
int L, R;

bool Less1(const int &a, const int &b)
{
	return l[a] < l[b];
}

bool Less2(const int &a, const int &b)
{
	if (r[a] != r[b]) return r[a] < r[b];
	return l[a] > l[b];
}

void Inc(int ind, int val)
{
	ind++;
	for (int i = ind; i <= un.size(); i += i & -i)
		BIT[i] += val;
}

int Get(int ind)
{
	ind++;
	int res = 0;
	for (int i = ind; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int Find()
{
	int lef = 0, rig = un.size() - 1;
	int res = un.size();
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Get(mid) >= k) { res = mid; rig = mid - 1; }
		else lef = mid + 1;
	}
	return res;
}

int main() 
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l[i], &r[i]); r[i]++;
		un.push_back(l[i]); un.push_back(r[i]);
		lef.push_back(i); rig.push_back(i);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		l[i] = lower_bound(un.begin(), un.end(), l[i]) - un.begin();
		r[i] = lower_bound(un.begin(), un.end(), r[i]) - un.begin();
	}
	sort(lef.begin(), lef.end(), Less1);
	sort(rig.begin(), rig.end(), Less2);
	int i = 0, j = 0;
	while (i < lef.size() || j < rig.size())
		if (i < lef.size() && (j == rig.size() || l[lef[i]] <= r[rig[j]])) {
			Inc(l[lef[i]], 1); i++;
		} else {
			int got = Find();
			if (got < un.size() && un[r[rig[j]]] - un[got] > res) {
				res = un[r[rig[j]]] - un[got];
				L = un[got]; R = un[r[rig[j]]];
			}
			Inc(l[rig[j]], -1); j++;
		}
	if (res < 0) {
		printf("0\n");
		for (int i = 0; i < k; i++)
			printf("%d%c", i + 1, i + 1 < k? ' ': '\n');
		return 0;
	}
	printf("%d\n", res);
	for (int i = 0; i < n && k > 0; i++)
		if (un[l[i]] <= L && R <= un[r[i]]) {
			printf("%d%c", i + 1, k - 1 > 0? ' ': '\n');
			k--;
		}
    return 0;
}