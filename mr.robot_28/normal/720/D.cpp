#include<bits/stdc++.h>
 
using namespace std;
vector <int> tree, flag, tree1;
const int mod = 1e9 + 7;
void rev(int &a)
{
	if(a >= mod)
	{
		a -= mod;
	}
}
void push(int v)
{
	if(flag[v])
	{
		tree[v * 2] = tree[v * 2 +1 ] = 0;
		flag[v * 2] = flag[v * 2 + 1] = 1;
		flag[v] = 0;
	}
}
void update(int v, int l, int r, int ind, int val)
{
	if(l == r)
	{
		tree[v] = val;
		return;
	}
	push(v);
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind, val);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
	}
	tree[v] = tree[v * 2] +tree[v * 2 + 1];
	rev(tree[v]);
}
void update1(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		flag[v] = 1;
		tree[v] = 0;
	}
	else if(l <= ar && r >= al)
	{
		push(v);
		update1(v * 2, l, (r + l) / 2, al, ar);
		update1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
		rev(tree[v]);
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
		push(v);
		int sum = ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
		rev(sum);
		return sum;
	}
	return 0;
}
void update2(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		tree1[v] ^= 1;
	}
	else if(l <= ar && r >= al)
	{
		update2(v * 2, l, (r + l) / 2, al, ar);
		update2(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
}
int ans2(int v, int l, int r, int id)
{
	if(l == r)
	{
		return tree1[v];
	}
	if(id <= (r + l) / 2)
	{
		return tree1[v] ^ ans2(v * 2, l, (r + l) / 2, id);
	}
	else
	{
		return tree1[v] ^ ans2(v * 2 + 1, (r + l) / 2 + 1, r, id);
	}
}
signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	tree.resize(4 * m);
	flag.resize(4 * m);
	tree1.resize(4 * m);
	set <pair <int, int> > s;
	vector <pair <pair <int, int>, pair <int, int> > > mass(k);
	vector <pair <pair <int, int> , int> > scan;
	for(int i = 0; i < k; i++)
	{
		cin >> mass[i].first.first >> mass[i].second.first >> mass[i].first.second >> mass[i].second.second;
		scan.push_back({{mass[i].first.first, -1}, i});
		scan.push_back({{mass[i].first.second + 1, 2}, i});
	}
	update(1, 0, m - 1, 0, 1);
	sort(scan.begin(), scan.end());
	for(int i = 0; i < scan.size(); i++)
	{
		int ind = scan[i].second;
		int type = scan[i].first.second;
		if(type == 2)
		{
			if(scan[i].first.first == n + 1)
			{
				break;
			}
			s.erase({mass[ind].second.second - 1, ind});
			update2(1, 0, m - 1, mass[ind].second.first - 1, mass[ind].second.second - 1);
		}
		else
		{
			int y1 = mass[ind].second.first;
			int y2 = mass[ind].second.second;
			y1--;
			y2--;
			if(mass[ind].first.first != 1 && y2 != m - 1 && ans2(1, 0, m - 1, y2 + 1) == 0)
			{
				set <pair <int, int> > :: iterator it;
				it = s.lower_bound({y2 + 1, 0});
				if(s.size() == 0 || it == s.begin())
				{
					int sum = ans(1, 0, m - 1, 0, y2 + 1);
					update(1, 0, m - 1, y2 + 1, sum);
				}
				else
				{
					it--;
					int sum = ans(1, 0, m - 1, it -> first + 1, y2 + 1);
					update(1, 0, m - 1, y2 + 1, sum);
				}
			}
			s.insert({y2, ind});
			update2(1, 0, m - 1, y1, y2);
			update1(1, 0, m - 1, y1, y2);
		}
	}
	if(s.size() == 0)
	{
		cout << ans(1, 0, m - 1, 0, m - 1);
	}
	else if(s.rbegin() -> first == m - 1)
	{
		cout << 0;
	}
	else
	{
		cout << ans(1, 0, m - 1, s.rbegin() -> first + 1, m - 1);
	}
	return 0;
}