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
typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxp = 320;

int n, k;
int t[Maxn];
ll a[Maxn];
vector <ll> un;
int my[Maxn], seeklef[Maxn], seekrig[Maxn];
int cnt[Maxn];
ll res;
int q;
int ql[Maxn], qr[Maxn];
vector <ii> quer[Maxp];
ll qres[Maxn];

void modLeft(int x, bool add)
{
	if (add) { res += cnt[seekrig[x]]; cnt[my[x]]++; }
	else { cnt[my[x]]--; res -= cnt[seekrig[x]]; }
}

void modRight(int x, bool add)
{
	if (add) { res += cnt[seeklef[x]]; cnt[my[x]]++; }
	else { cnt[my[x]]--; res -= cnt[seeklef[x]]; }
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);
	un.push_back(0);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", &a[i]);
		if (t[i] == 2) a[i] = -a[i];
		a[i] += a[i - 1];
		un.push_back(a[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i <= n; i++) {
		my[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
		ll needlef = a[i] - ll(k);
		int ind = lower_bound(un.begin(), un.end(), needlef) - un.begin();
		if (ind < un.size() && un[ind] == needlef) seeklef[i] = ind;
		else seeklef[i] = int(un.size());
		ll needrig = a[i] + ll(k);
		ind = lower_bound(un.begin(), un.end(), needrig) - un.begin();
		if (ind < un.size() && un[ind] == needrig) seekrig[i] = ind; 
		else seekrig[i] = int(un.size());
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d %d", &ql[i], &qr[i]); ql[i]--;
		int ind = ql[i] / Maxp + 1;
		if (ind * Maxp <= qr[i]) quer[ind].push_back(ii(qr[i], i));
		else {
			for (int j = ql[i]; j <= qr[i]; j++)
				modRight(j, true);
			qres[i] = res;
			for (int j = qr[i]; j >= ql[i]; j--)
				modRight(j, false);
		}
	}
	for (int i = 0; i < Maxp; i++) if (!quer[i].empty()) {
		sort(quer[i].begin(), quer[i].end());
		int lim = i * Maxp;
		int L = lim, R = lim - 1;
		for (int j = 0; j < quer[i].size(); j++) {
			int ind = quer[i][j].second;
			while (R < qr[ind]) modRight(++R, true);
			while (ql[ind] < L) modLeft(--L, true);
			while (L < ql[ind]) modLeft(L++, false);
			qres[ind] = res;
		}
		while (L < lim) modLeft(L++, false);
		while (R >= lim) modRight(R--, false);
	}
	for (int i = 1; i <= q; i++)
		printf("%I64d\n", qres[i]);
	return 0;
}