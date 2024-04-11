#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int> upd;
vector <int> tree;
void push(int v, int l, int r)
{
	tree[v * 2] += upd[v] * ((r + l) / 2 - l + 1);
	tree[v * 2 + 1] += upd[v] * (r - (r + l) / 2);
	upd[v * 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	upd[v] = 0;
}
void update(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		tree[v] += (r - l + 1) * val;
		upd[v] += val;
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		update(v * 2, l, (r + l) / 2, al, ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		tree[v] = (tree[v * 2] + tree[v * 2 + 1]);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	tree.resize(4 * n, 0);
	upd.resize(4 * n, 0);
	int len = 0;
	stack <pair <int, int> > st;
	st.push({n, 1e9 + 1});
	int sum = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		if(s[i] == '1')
		{
			len++;
			while(st.size() > 0 && st.top().second < len)
			{
				st.pop();
			}
			int maxind = st.top().first - 1;
		//	cout << maxind << "\n";
			update(1, 0, n - 1, i, maxind, 1);
		}
		else
		{
			if(len != 0)
			{
				for(int j = len; j >= 1; j--)
				{
					st.push({i + j, j});
				}
			}
			len = 0;
		}
		sum += tree[1];
	}
	cout << sum;
	return 0;
}