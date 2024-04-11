#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int> treeleft, treeright, tree1, tree2;
void update(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		if(val > 0)
		{
			tree1[v] += val;
		}
		else
		{
			tree2[v] += -val;
		}
	}
	else if(l <= ar && r >= al)
	{
		update(v * 2, l, (r + l) / 2, al, ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
	}
}
pair <int, int> ans(int v, int l, int r, int ind)
{
	if(l == r)
	{
		return {tree1[v], tree2[v]};
	}
	else if(ind <= (r + l) / 2)
	{
		pair <int, int> t = ans(v * 2, l, (r + l) / 2, ind);
		t.first += tree1[v];
		t.second += tree2[v];
		return t;
	}
	else
	{
		pair <int, int> t = ans(v * 2 + 1, (r + l) / 2 + 1, r, ind);
		t.first += tree1[v];
		t.second += tree2[v];
		return t;
	}
}
void update1(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		treeleft[v] += val;
	}
	else if(l <= ar && r >= al)
	{
		update1(v * 2, l, (r + l) / 2, al, ar, val);
		update1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
	}
}
int ans1(int v, int l, int r, int ind)
{
	if(l == r)
	{
		return treeleft[v];
	}
	else if(ind <= (r + l) / 2)
	{
		return treeleft[v] + ans1(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		return treeleft[v] + ans1(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
}
void update2(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		treeright[v] += val;
	}
	else if(l <= ar && r >= al)
	{
		update2(v * 2, l, (r + l) / 2, al, ar, val);
		update2(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
	}
}
int ans2(int v, int l, int r, int ind)
{
	if(l == r)
	{
		return treeright[v];
	}
	else if(ind <= (r + l) / 2)
	{
		return treeright[v] + ans2(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		return treeright[v] + ans2(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
}
signed main() {
	int n;
	cin >> n;
	tree1.resize(4 * n);
	tree2.resize(4 * n);
	treeleft.resize(4 * n);
	treeright.resize(4 * n);
	vector <int> p(n), ind(n);
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
		p[i]--;
		ind[p[i]] = i;
	}
	int rev = 0;
	for(int i = 0; i < n; i++)
	{
		int y = ind[i];
		rev += ans(1, 0, n - 1, y).second;
		update(1, 0, n - 1, 0, y, -1);
		update(1, 0, n - 1, y, n - 1, 1);
		update2(1, 0, n - 1, 0, y, y);
		update1(1, 0, n - 1 ,y, n - 1, y);
		int l = 0, r = n;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			int cntl = ans(1, 0, n - 1, midd).first;
			int cntr = ans(1, 0, n - 1, midd).second;
			if(cntl <= cntr)
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		int cntl = ans(1, 0, n - 1, l).first;
		int cntr = ans(1, 0, n - 1, l).second;
		int sumleft = ans1(1, 0, n - 1, l);
		int sumright = ans2(1, 0, n - 1, l);
		int res = 0;
		if(cntl + cntr > i + 1)
		{
			cntl--;
			cntr--;
			sumleft -= l;
			sumright -= l;
			res += cntl * (l - 1) - sumleft - (cntl - 1) * cntl / 2;
			res += sumright - cntr * (l + 1) - (cntr - 1) * cntr / 2;
		}
		else
		{
			if(cntl > 0)
			{
				res += cntl * l - sumleft - (cntl - 1) * cntl / 2;
				res += sumright - cntr * (l + 1) - (cntr - 1) * cntr / 2;
			}
			else if(cntr > 0)
			{
				res += cntl * (l - 1) - sumleft - (cntl - 1) * cntl / 2;
				res += sumright - cntr * l - (cntr - 1) * cntr / 2;
			}
		}
		cout << res + rev << " ";
	}
	return 0;
}