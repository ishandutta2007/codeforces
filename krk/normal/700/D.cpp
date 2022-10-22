#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxx = 319;
const int Maxy = 1105;
const int Maxv = 91;

int n;
int a[Maxn];
int freq[Maxn];
vector <int> big;
int q;
int st[Maxn];
int cnt[Maxn];
int l[Maxn], r[Maxn];
vector <ii> quer[Maxn]; 
int cur[Maxn];
ll res[Maxn];

void Add(int l, int r, int add)
{
	for (int i = l; i <= r; i++) {
		if (freq[a[i]] < Maxy) cnt[st[a[i]]]--;
		st[a[i]] += add;
		if (freq[a[i]] < Maxy) cnt[st[a[i]]]++;
	}
}

ll Solve()
{
	ll res = 0;
	priority_queue <int> Q;
	for (int i = 0; i < big.size(); i++)
		if (st[big[i]] >= Maxy) Q.push(-st[big[i]]);
		else cnt[st[big[i]]]++;
	int lst = -1;
	for (int i = 1; i < Maxy; i++) if (cur[i] > 0 || cnt[i] > 0) {
		cur[i] += cnt[i];
		if (lst != -1) {
			lst += i; cur[i]--;
			res += lst;
			if (lst < Maxy) cur[lst]++;
			else Q.push(-lst);
			lst = -1;
		}
		int hm = cur[i] / 2; cur[i] %= 2;
		if (hm > 0) {
			res += ll(hm) * 2 * i;
			if (2 * i < Maxy) cur[2 * i] += hm;
			else while (hm--) Q.push(-2 * i);
		}
		if (cur[i] > 0) lst = i;
		cur[i] = 0;
	}
	if (!Q.empty()) {
		if (lst != -1) {
			lst += -Q.top(); Q.pop();
			res += lst;
			Q.push(-lst);
			lst = -1;
		}
		while (Q.size() >= 2) {
			int a = -Q.top(); Q.pop();
			int b = -Q.top(); Q.pop();
			res += a + b;
			Q.push(-(a + b));
		}
	}
	for (int i = 0; i < big.size(); i++)
		if (st[big[i]] < Maxy) cnt[st[big[i]]]--; 
	return res;
}
 
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		freq[a[i]]++;
	}
	for (int i = 0; i < Maxn; i++)
		if (freq[i] >= Maxy) big.push_back(i);
		else cnt[st[i]]++;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &l[i], &r[i]); l[i]--; r[i]--;
		int lef = (l[i] + Maxx - 1) / Maxx * Maxx;
		if (lef <= r[i]) 
			quer[lef].push_back(ii(r[i], i));
		else {
			Add(l[i], r[i], 1);
			res[i] = Solve();
			Add(l[i], r[i], -1);
		}
	}
	for (int i = 0; i < n; i++) if (quer[i].size()) {
		sort(quer[i].begin(), quer[i].end());
		int pnt = 0;
		for (int j = i; j < n; j++) {
			Add(j, j, 1);
			while (pnt < quer[i].size() && quer[i][pnt].first == j) {
				int ind = quer[i][pnt].second;
				Add(l[ind], i - 1, 1);
				res[ind] = Solve();
				Add(l[ind], i - 1, -1);
				pnt++;
			}
		}
		Add(i, n - 1, -1);
	}
	for (int i = 0; i < q; i++)
		printf("%I64d\n", res[i]);
	return 0;
}