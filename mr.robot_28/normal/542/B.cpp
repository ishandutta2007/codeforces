#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 6666666;
int tree[N], upd[N];
int leftind[N], rightind[N];
int c = 1;
void push(int v)
{
	tree[v] = max(tree[leftind[v]], tree[rightind[v]]) + upd[v];
}
void update(int &v, int l, int r, int ind, int val)
{
	if(!v)
	{
		c++;
		v = c;
	}
	if(l == r)
	{
		tree[v] = upd[v] = val;
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update(leftind[v], l, (r + l) / 2, ind, val);
	}
	else
	{
		update(rightind[v], (r + l) / 2 + 1, r, ind, val);
	}
	push(v);
}
void add(int &v, int l, int r, int al, int ar)
{
	if(!v)
	{
		return;
	}
	if(l >= al && r <= ar)
	{
		tree[v]++;
		upd[v]++;
		return;
	}
	if(l <= ar && r >= al)
	{
		add(leftind[v], l, (r + l) / 2, al, ar);
		add(rightind[v], (r + l) / 2 + 1, r, al, ar);
		push(v);
	}
}
int ans(int &v, int l, int r, int al, int ar)
{
	if(!v)
	{
		return 0;
	}
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	if(l <= ar && r >= al)
	{
		return max(ans(leftind[v], l, (r + l) / 2, al, ar), ans(rightind[v], (r + l) / 2 + 1, r, al, ar)) + upd[v];
	}
	return 0;
}
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	priority_queue <pair <int, int> > q;
	int n, k;
	cin >> n >> k;
	for(int i=  0; i < N; i++)
	{
		leftind[i] = rightind[i] = tree[i] = upd[i] = 0;
	}
	for(int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		l = max(l, 0LL);
		q.push({-r, -l});
		q.push({-l, 1});
	}
	int ind = -1;
	int st = 1;
	while(!q.empty())
	{
		int l = -q.top().second;
		int r = -q.top().first;
		q.pop();
		if(l >= 0)
		{
			add(st, 0, 1e9, l, r);
		}
		else
		{
			if(r == ind)
			{
				continue;
			}
			int val1 = ans(st, 0, 1e9, ind, ind);
			int val2 = ans(st, 0, 1e9, 0, r - k);
			if(l == -1 || val1 < val2)
			{
				ind = r;
				update(st, 0, 1e9, r, val2);
				if(r + k <= 1e9)
				{
					q.push({-r - k, 2});
				}
			}
		}
	}
	cout << tree[1];
	return 0;
}