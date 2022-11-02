#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100000
#define MAXM 200000

typedef long long ll;
typedef vector<int> vi;

int n;
vi e[MAXN];
int lch[MAXN] = {};

int main()
{
	int m, x, y;
    cin >> n >> m;
    while (m--) {
		cin >> x >> y;
		e[x - 1].push_back(y - 1);
		e[y - 1].push_back(x - 1);
    }

	ll ans = 0;
    for (int i = 0; i < n; i++) {
		ll cur = lch[i] + 1;
		for (int j : e[i]) {
			if (j > i) {
				lch[j] = max(lch[j], lch[i] + 1);
			}
		}
		cur *= e[i].size();
		ans = max(ans, cur);
    }
	cout << ans << endl;
    return 0;
}