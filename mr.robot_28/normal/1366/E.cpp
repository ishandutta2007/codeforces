#include<bits/stdc++.h>
using namespace std;
const int const1 = 998244353;
#define int long long
vector <int> tree;
vector <int> upd;
void push(int v, int l, int r)
{
	if(upd[v] == -1)
	{
		return;
	}
	tree[v * 2] = ((r + l) / 2 - l + 1) * upd[v] % const1;
	tree[v * 2 + 1] = (r - (r + l) / 2) * upd[v] % const1;
	upd[v * 2] = upd[v * 2 + 1] = upd[v];
	upd[v] = -1;
}
void update(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		tree[v] = (r - l + 1) * val % const1;
		upd[v] =val;
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		update(v * 2, l, (r + l) / 2, al, ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
		if(tree[v] >= const1)
		{
			tree[v] -= const1;
		}
	}
}
int ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		int sum = ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
		if(sum >= const1)
		{
			sum -= const1;
		}
		return sum;
	}
	else
	{
		return 0;
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <int> a(n), b(m);
	tree.resize(4 * n, 0);
	upd.resize(4 * n, -1);
	vector <int> post(n, 1e9 + 1);
	vector <pair <int, int> > vec;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		vec.push_back({a[i], i});
	}
	for(int i = n - 1; i >= 0; i--){
		if(i != n - 1)
		{
			post[i] = post[i + 1];
		}
		post[i] = min(post[i], a[i]);
	}
	for(int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	sort(vec.begin(), vec.end());
	int j = 0;
	for(int i = 0; i < m; i++)
	{
		while(j < vec.size() && vec[j].first <= b[i])
		{
			j++;
		}
		int d = j - 1;
		int last = n;
		int l = -1, r = n;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			if(post[midd] < b[i])
			{
				l = midd;
			} 
			else
			{
				r = midd;
			}
		}
		if(l > 0)
		{
			update(1, 0, n - 1, 0, l - 1, 0);
		}
		while(d >= 0 && vec[d].first == b[i])
		{
			int ind = vec[d].second;
			int s = 0;
			if(ind != 0)
			{
				s = ans(1, 0, n - 1, 0, ind - 1);
			}
			if(l == -1 && i == 0)
			{
				s = 1;
			}
			update(1, 0, n - 1, ind, last - 1, s);
			last = ind;
			d--;
		}
		if(last != 0){
			update(1, 0, n - 1, 0, last - 1, 0);
		}
	}
	cout << ans(1, 0, n - 1, n - 1, n - 1);
    return 0;
}