#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector <int> a, b, p;
vector <int> tree;
vector <int> val;
void push(int v, int l, int r)
{
	if(l == r)
	{
		tree[v] = 0;
		return;
	}
	tree[v * 2] += tree[v];
	tree[v * 2 + 1] += tree[v];
	tree[v] = 0;
}
int ans(int v, int l, int r, int ind)
{
	int k = tree[v];
	push(v, l, r);
	if(l == r)
	{
		return k;
	}
	if(ind <= (r + l) / 2)
	{
		return ans(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		return ans(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
}
void update(int v, int l, int r, int al, int ar, int val)
{
	if(al <= l && r <= ar)
	{
		tree[v] += val;
	}
	else if(al <= r && l <= ar)
	{
		push(v, l, r);
		update(v * 2, l, (r + l) / 2, al, ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	a.resize(n);
	p.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector <int> pref(n);
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
		if(i == 0)
		{
			pref[i] = p[i];
		}
		else
		{
			pref[i] = pref[i - 1] + p[i];
		}
	}
	cin >> m;
	b.resize(m);
	for(int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	tree.resize(m * 4);
	val.resize(m, 1e18);
	vector <bool> used(m);
	for(int i = 0; i < n; i++)
	{
		int l = -1, r = m;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			if(b[midd] <= a[i])
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		if(l == -1)
		{
			if(p[i] < 0)
			{
				update(1, 0, m - 1, 0, m - 1, p[i]);
			}
			continue;
		}
		if(b[l] == a[i])
		{
			if(l == 0)
			{
				int t = val[l] + ans(1, 0,  m - 1, l);
				if(p[i] < 0)
				{
					t += p[i];
					if(l != m - 1)
					{
						update(1, 0, m - 1, 1, m - 1, p[i]);
					}
				}
				val[l] = min(t, pref[i] - p[i]);
				used[l] = true;
			}
			else
			{
				if(!used[l - 1])
				{
					if(p[i] < 0)
					{
						update(1, 0, m - 1, 0, m - 1, p[i]);
					}
					else
					{
						update(1, 0, m - 1, 0, l - 1, p[i]);
					}
				}
				else
				{
				used[l] = true;
				int t = 1e18;
				if(used[l])
				{
				t = val[l] + ans(1, 0, m - 1, l);
				if(p[i] < 0)
				{
					t += p[i];
				}
				}
				val[l - 1] += ans(1, 0, m - 1, l - 1);
				val[l] = min(t, val[l - 1]);
				update(1, 0, m - 1, 0, l - 1, p[i]);
				if(p[i] < 0 && l != m - 1)
				{
					update(1, 0, m - 1, l + 1, m - 1, p[i]);
				}
			}	
			}
		}
		else if(p[i] >= 0)
		{
			update(1, 0, m - 1, 0, l, p[i]);
		}
		else
		{
			update(1, 0, m - 1, 0, m - 1, p[i]);
		}
	}
	if(!used[m - 1])
	{
		cout << "NO";
		return 0;
	}
	val[m - 1] = val[m - 1] + ans(1, 0, m - 1, m - 1);
	cout << "YES\n";
	cout << val[m - 1];
	return 0;
}