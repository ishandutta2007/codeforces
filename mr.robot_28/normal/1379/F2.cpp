#include<bits/stdc++.h>
 
using namespace std;
vector <int> tree1, tree2, treeflag;
void update1(int v, int l, int r, int ind, int val)
{
	if(l == r)
	{
		tree1[v] = val;
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update1(v * 2, l, (r + l) / 2, ind, val);
	}
	else
	{
		update1(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
	}
	tree1[v] = min(tree1[v * 2], tree1[v * 2 + 1]);
	treeflag[v] = false;
	if(treeflag[v * 2] || treeflag[v * 2 + 1] || tree1[v * 2] < tree2[v * 2 + 1])
	{
		treeflag[v] = true;
	}
}
void update2(int v, int l, int r, int ind, int val)
{
	if(l == r)
	{
		tree2[v] = val;
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update2(v * 2, l, (r + l) / 2, ind, val);
	}
	else
	{
		update2(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
	}
	tree2[v] = max(tree2[v * 2], tree2[v * 2 + 1]);
	treeflag[v] = false;
	if(treeflag[v * 2] || treeflag[v * 2 + 1] || tree1[v * 2] < tree2[v * 2 + 1])
	{
		treeflag[v] = true;
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	tree1.resize(8 * n, 1e9);
	tree2.resize(8 * n, 0);
	treeflag.resize(8 * n, 0);
	set <pair <int, int> > st;
	vector <set <int> > sets(n * 2);
	int c1 = 0;
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		x--;
		if(st.find({x, y}) != st.end())
		{
			if(x % 2 == 0)
			{
				if(st.find({x + 1, y + 1}) != st.end())
				{
					c1--;
					sets[x + 1].insert(y + 1);
					update2(1, 0, 2 * n - 1, x + 1, *sets[x + 1].rbegin());
				}
				else
				{
					sets[x].erase(y);
					if(sets[x].size() == 0)
					{
						update1(1, 0, 2 * n - 1, x, 1e9);
					}
					else
					{
						update1(1, 0, 2 * n - 1, x, *sets[x].begin());
					}
				}
			}
			else
			{
				if(st.find({x - 1, y - 1}) != st.end())
				{
					c1--;
					sets[x - 1].insert(y - 1);
					update1(1, 0, 2 * n - 1, x - 1, *sets[x - 1].begin());
				}
				else
				{
					sets[x].erase(y);
					if(sets[x].size() == 0)
					{
						update2(1, 0, 2 * n - 1, x, 0);
					}
					else
					{
						update2(1, 0, 2 * n - 1, x, *sets[x].rbegin());
					}
				}
			}
			st.erase({x, y});
		}
		else
		{
			if(x % 2 == 0)
			{
				if(st.find({x + 1, y + 1}) != st.end())
				{
					c1++;
					sets[x + 1].erase(y + 1);
					if(sets[x + 1].size() == 0)
					{
						update2(1, 0, 2 * n - 1, x + 1, 0);
					}
					else
					{
						update2(1, 0, 2 * n - 1, x + 1, *sets[x + 1].rbegin());
					}
				}
				else
				{
					sets[x].insert(y);
					update1(1, 0, 2 * n - 1, x, *sets[x].begin());
				}
			}
			else
			{
				if(st.find({x - 1, y - 1}) != st.end())
				{
					c1++;
					sets[x - 1].erase(y - 1);
					if(sets[x - 1].size() == 0)
					{
						update1(1, 0, 2 * n - 1, x - 1, 1e9);
					}
					else
					{
						update1(1, 0, 2 * n - 1, x - 1, *sets[x - 1].begin());
					}
				}
				else
				{
					sets[x].insert(y);
					update2(1, 0, 2 * n - 1, x, *sets[x].rbegin());
				}
			}
			st.insert({x, y});
		}
		if(treeflag[1] || c1 != 0)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
	return 0;
}