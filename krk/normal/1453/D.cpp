#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const ll lim = 1000000000000000000ll;

vector <ll> vals;
int T;
ll k;
vector <int> seq;
bool a[Maxn];

int main()
{
	vals.push_back(0);
	while (vals.back() <= lim) {
		ll nxt = (vals.back() + 1) * 2ll;
		vals.push_back(nxt);
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d", &k);
		if (k % 2) { printf("-1\n"); continue; }
		k -= 2;
		seq.clear();
		int sum = 1;
		while (k > 0) {
			int ind = upper_bound(vals.begin(), vals.end(), k) - vals.begin() - 1;
			sum += ind;
			seq.push_back(ind);
			k -= vals[ind];
		}
		if (sum > 2000) { printf("-1\n"); continue; }
		fill(a, a + sum + 1, false);
		a[1] = true;
		int lst = 1;
		for (int i = 0; i < seq.size(); i++) {
			lst += seq[i];
			a[lst] = true;
		}
		printf("%d\n", sum);
		for (int i = 1; i <= sum; i++)
			printf("%d%c", bool(a[i]), i + 1 <= sum? ' ': '\n');
	}
    return 0;
}