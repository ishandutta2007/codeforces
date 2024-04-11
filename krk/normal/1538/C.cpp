#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, l, r;
int a[Maxn];
vector <int> un;
int BIT[Maxn];

void Insert(int x)
{
	for (int i = x + 1; i > 0; i -= i & -i)
		BIT[i]++;
}

int Get(int x)
{
	int res = 0;
	for (int i = x + 1; i <= un.size(); i += i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		un.clear();
		scanf("%d %d %d", &n, &l, &r);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			un.push_back(a[i]);
		}
		sort(un.begin(), un.end());
		un.erase(unique(un.begin(), un.end()), un.end());
		fill(BIT, BIT + int(un.size()) + 1, 0);
		long long res = 0;
		for (int i = 0; i < n; i++) {
			int lef = lower_bound(un.begin(), un.end(), l - a[i]) - un.begin();
			int rig = upper_bound(un.begin(), un.end(), r - a[i]) - un.begin();
			res += Get(lef) - Get(rig);
			int ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
			Insert(ind);
		}
		printf("%I64d\n", res);
	}
    return 0;
}