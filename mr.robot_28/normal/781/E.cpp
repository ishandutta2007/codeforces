#include<bits/stdc++.h>
using namespace std;
const int const1 = 1e9 + 7;
int h, w, n;
vector <pair <pair <int, int>, pair <int, int> > > A;
vector <pair <pair <int, int>, int> > scan;
vector <set <pair <int, int> > > tree;
void updnew(int v, int l, int r, int al, int ar, int ind, int a)
{
	if(l >= al && r <= ar)
	{
		tree[v].insert({-A[ind].first.first, a});
	}
	else if(l <= ar && r >= al)
	{
		updnew(v * 2, l, (r + l) / 2, al, ar, ind, a);
		updnew(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, ind, a);
	}
}
void upddel(int v, int l, int r, int al, int ar, int ind)
{
	if(l >= al && r <= ar)
	{
		set <pair <int, int> > :: iterator it;
		it = tree[v].lower_bound({-A[ind].first.first, 0});
		tree[v].erase(*it);
	}
	else if(l <= ar && r >= al)
	{
		upddel(v * 2, l, (r + l) / 2, al, ar, ind);
		upddel(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, ind);
	}
}
pair <int, int> ans(int v, int l, int r, int ind)
{
	if(l == r)
	{
		if(tree[v].size() == 0)
		{
			return {0, 1};
		}
		else
		{
			return {-tree[v].begin() -> first, tree[v].begin() -> second};
		}
	}
	else if(ind <= (r + l) / 2)
	{
		pair <int, int> ver = ans(v * 2, l, (r + l) /2 , ind);
		pair <int, int> ver1;
		if(tree[v].size() == 0)
		{
			ver1 = {0, 1};
		}
		else
		{
			ver1 = {-tree[v].begin() -> first, tree[v].begin() -> second};
		}
		if(ver1.first < ver.first)
		{
			return ver;
		}
		else
		{
			return ver1;
		}
	}
	else
	{
		pair <int, int> ver = ans(v * 2 + 1, (r + l) / 2 + 1, r, ind);
		pair <int, int> ver1;
		if(tree[v].size() == 0)
		{
			ver1 = {0, 1};
		}
		else
		{
			ver1 = {-tree[v].begin() -> first, tree[v].begin() -> second};
		}
		if(ver1.first < ver.first)
		{
			return ver;
		}
		else
		{
			return ver1;
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> h >> w >> n;
	tree.resize(4 * w);
	for(int i = 0; i < n; i++)
	{
		int u, l, r, s;
		cin >> u >> l >> r >> s;
		l--;
		r--;
		A.push_back({{u, s}, {l, r}});
		scan.push_back({{u, 1}, i});
		if(u + s + 1 <= h + 1)
		{
			scan.push_back({{u + s + 1, -1}, i});
		}
	}
	sort(scan.begin(), scan.end());
	for(int i = 0; i < scan.size(); i++)
	{
		int ind = scan[i].second;
		if(scan[i].first.second == 1)
		{
			if(A[ind].second.first == 0)
			{
				int k1 = ans(1, 0, w - 1, A[ind].second.second + 1).second * 2;
				if(k1 >= const1)
				{
					k1 -= const1;
				}
				updnew(1, 0, w - 1, A[ind].second.first, A[ind].second.second, ind, k1);
			}
			else if(A[ind].second.second == w - 1)
			{
				int k1 = ans(1, 0, w - 1, A[ind].second.first - 1).second * 2;
				if(k1 >= const1){
					k1 -= const1;
				}
				updnew(1, 0, w - 1, A[ind].second.first, A[ind].second.second, ind, k1);
			}
			else
			{
				int k1 = ans(1, 0, w - 1, A[ind].second.first - 1).second;
				int k2 = ans(1, 0, w - 1, A[ind].second.second + 1).second;
				k1 = k1 + k2;
				if(k1 >= const1)
				{
					k1 -= const1;
				}
				updnew(1, 0, w - 1, A[ind].second.first, A[ind].second.second, ind, k1);
			}
		}
		else
		{
			upddel(1, 0, w - 1, A[ind].second.first, A[ind].second.second, ind);
		}
	}
	int global_ans = 0;
	for(int i = 0; i < w; i++)
	{
		global_ans += ans(1, 0, w - 1, i).second;
		if(global_ans >= const1)
		{
			global_ans -= const1;
		}
	}
	cout << global_ans;
    return 0;
}