#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int n;
int a[Maxn];
ll res[Maxn];
ll BIT[Maxn];
map <int, int> pos;
int m; 
int l[Maxn], r[Maxn];
vector <int> quer[Maxn];
ll ans[Maxn];

void Insert(int x, ll val)
{
	for (int i = x; i <= n; i += i & -i)
		BIT[i] ^= val;
}

int Get(int x)
{
	ll res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res ^= BIT[i];
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		res[i] = (res[i - 1] ^ ll(a[i]));
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &l[i], &r[i]);
		quer[l[i]].push_back(i);
		ans[i] = res[r[i]] ^ res[l[i] - 1];
	}
	for (int i = n; i >= 1; i--) {
		int val = a[i];
		if (pos.find(val) != pos.end()) {
			int ind = pos[val];
			Insert(ind, val);
		}
		Insert(i, val);
		pos[val] = i;
		for (int j = 0; j < quer[i].size(); j++) {
			int ind = quer[i][j];
			ans[ind] ^= Get(r[ind]);
		}
	}
	for (int i = 0; i < m; i++)
		printf("%I64d\n", ans[i]);
	return 0;
}