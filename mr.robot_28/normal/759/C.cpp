#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int N = 2e5;
int Tree[4 * N], upd[4 * N];
void push(int v)
{
	Tree[v * 2] += upd[v];
	Tree[v * 2 + 1] += upd[v];
	upd[v * 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	upd[v] = 0;
}
void update(int v, int l, int r, int al, int ar, int add)
{
	if(l >= al && r <= ar)
	{
		Tree[v] += add;
		upd[v] += add;
		return ;
	}
	if(l <= ar && r >= al)
	{
		push(v);
		update(v * 2, l, (r + l) / 2, al, ar, add);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, add);
		Tree[v] = max(Tree[v * 2], Tree[v * 2 + 1]);
	}
}
int go_to(int v, int l, int r)
{
	if(l == r)
	{
		return l;
	}
	push(v);
	if(Tree[v * 2 + 1] > 0){
		return go_to(v * 2 + 1, (r + l)  /2  +1, r);
	}
	return go_to(v * 2, l, (r + l) / 2);
}
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int m;
	cin >> m;
	vector <int> vals(m);
	for(int i = 0; i < m; i++)
	{
		int p, t;
		cin >> p >> t;
		p--;
		if(t == 1)
		{
			int x;
			cin >> x;
			vals[p] = x;
			update(1, 0, m - 1, 0, p, 1);
		}
		else
		{
			update(1, 0, m - 1, 0, p, -1);
		}
		if(Tree[1] > 0)
		{
			int idx = go_to(1, 0, m - 1);
			cout << vals[idx] << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
	return 0;
}