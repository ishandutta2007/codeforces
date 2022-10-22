#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxm = 317;

int n;
int a[Maxn];
int q;
int res = 0;
int cnt[Maxm][Maxn];
deque <int> block[Maxm];

void Rot(int l, int r)
{
	int el = block[r / Maxm][r % Maxm];
	block[r / Maxm].erase(block[r / Maxm].begin() + r % Maxm);
	cnt[r / Maxm][el]--;
	for (int i = r / Maxm - 1; i >= l / Maxm; i--) {
		block[i + 1].push_front(block[i].back());
		cnt[i + 1][block[i].back()]++;
		cnt[i][block[i].back()]--;
		block[i].pop_back();
	}
	block[l / Maxm].insert(block[l / Maxm].begin() + l % Maxm, el);
	cnt[l / Maxm][el]++;
}

int Calc(int l, int r, int k)
{
	int res = 0;
	if (l / Maxm == r / Maxm) {
		for (int j = l % Maxm; j <= r % Maxm; j++)
			res += block[l / Maxm][j] == k;
	} else {
		for (int j = l % Maxm; j < block[l / Maxm].size(); j++)
			res += block[l / Maxm][j] == k;
		for (int i = l / Maxm + 1; i < r / Maxm; i++)
			res += cnt[i][k];
		for (int j = 0; j <= r % Maxm; j++)
			res += block[r / Maxm][j] == k;
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[i / Maxm][a[i]]++;
		block[i / Maxm].push_back(a[i]);
	}
	scanf("%d", &q);
	while (q--) {
		int typ, l, r, k;
		scanf("%d %d %d", &typ, &l, &r);
		l = (l + res - 1 + n) % n; r = (r + res - 1 + n) % n;
		if (l > r) swap(l, r);
		if (typ == 1) Rot(l, r); 
		else {
			scanf("%d", &k);
			k = (k + res - 1 + n) % n + 1;
			res = Calc(l, r, k);
			printf("%d\n", res);
		}
	}
	return 0;
}