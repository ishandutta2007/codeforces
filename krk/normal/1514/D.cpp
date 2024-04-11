#include <bits/stdc++.h>
using namespace std;

const int Maxm = 50;
const int Maxn = 300005;

int n, q;
int a[Maxn];
vector <int> seq[Maxn];
bool tk[Maxn];
int asked[Maxm], alen;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		seq[a[i]].push_back(i);
	}
	while (q--) {
		for (int i = 0; i < alen; i++)
			tk[asked[i]] = false;
		alen = 0;
		int l, r; scanf("%d %d", &l, &r);
		int res = 1;
		for (int i = 0; i < Maxm; i++) {
			int ind = uniform_int_distribution<int>(l, r)(rng);
			if (tk[a[ind]]) continue;
			tk[a[ind]] = true;
			asked[alen++] = a[ind];
			int tims = upper_bound(seq[a[ind]].begin(), seq[a[ind]].end(), r) -
			 		   lower_bound(seq[a[ind]].begin(), seq[a[ind]].end(), l);
			int could = r - l + 1 - tims + 1;
			if (tims > could) { res += tims - could; break; }
		}
		printf("%d\n", res);
	}
    return 0;
}