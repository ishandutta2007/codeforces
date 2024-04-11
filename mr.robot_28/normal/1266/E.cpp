#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> cnt;
vector <int> A;
vector <int> tree;
void update(int v, int l, int r, int ind, int up)
{
	if(l == r)
	{
		tree[v] = min(cnt[ind], A[ind]);
		return;
	}
	else if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind, up);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind, up);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	tree.resize(4 * n);
	A.resize(n);
	cnt.resize(n);
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		sum += A[i];
	}
	int q;
	cin >> q;
	set <pair <pair <int, int> , int> > k;
	while(q--)
	{
		int s, t, u;
		cin >> s >> t >> u;
		set <pair <pair <int, int>, int> > :: iterator it;
		it = k.lower_bound({{s, t}, 0});
		if(it != k.end() && it -> first.first == s && it -> first.second == t)
		{
			int u1 = it -> second;
			cnt[u1 - 1]--;
			update(1, 0, n - 1, u1 - 1, -1);
			k.erase({{s, t}, u1});
		}
		if(u != 0)
		{
			cnt[u - 1]++;
			update(1, 0, n - 1, u - 1, 1);
			k.insert({{s,t}, u});
		}
		cout << sum - tree[1] << "\n";
	}
	return 0;
}