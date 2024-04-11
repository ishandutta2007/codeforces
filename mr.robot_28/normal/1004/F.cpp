#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, x;
vector <int> a;
const int N = 1e5;
int treeleft[N * 4][20], treeright[N * 4][20];
int tree1[N * 4], tree2[N * 4], tree3[N * 4];
int treesum[N * 4];
void update(int v, int l, int r, int al, int ar, int VAL)
{
	if(l >= al && r <= ar)
	{
		tree1[v] = tree2[v] = tree3[v] = VAL;
		treesum[v] = VAL * (r - l + 1);
	}
	else if(r >= al && l <= ar)
	{
		if(tree1[v] != -1)
		{
			tree1[v * 2] = tree1[v * 2 + 1] = tree1[v];
			tree2[v * 2] = tree2[v * 2 + 1] = tree1[v];
			tree3[v * 2] = tree3[v * 2 + 1] = tree1[v];
			treesum[v * 2] = tree1[v] * ((r + l) / 2 - l + 1);
			treesum[v * 2 + 1] = tree1[v] * (r - (r + l) / 2);
		}
		tree1[v] = -1;
		update(v * 2, l, (r + l) / 2, al, ar, VAL);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, VAL);
		tree2[v] = min(tree2[v * 2], tree2[v * 2 + 1]);
		tree3[v] = max(tree3[v * 2], tree3[v * 2 + 1]);
		treesum[v] = treesum[v * 2] + treesum[v * 2 + 1];
	}
}
void updateleft(int v, int l, int r, int al, int ar, int ind, int val)
{
	if(l >= al && r <= ar)
	{
		treeleft[v][ind] = val;
	}
	else if(l <= ar && r >= al)
	{
		if(treeleft[v][ind] != -2)
		{
			treeleft[v * 2][ind] = treeleft[v * 2 + 1][ind] = treeleft[v][ind];
		}
		treeleft[v][ind] = -2;
		updateleft(v * 2, l, (r + l) / 2, al, ar, ind, val);
		updateleft(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, ind, val);
	}
}
void updateright(int v, int l, int r, int al, int ar, int ind, int val)
{
	if(l >= al && r <= ar)
	{
		treeright[v][ind] = val;
	}
	else if(l <= ar && r >= al)
	{
		if(treeright[v][ind] != -2)
		{
			treeright[v * 2][ind] = treeright[v * 2 + 1][ind] = treeright[v][ind];
		}
		treeright[v][ind] = -2;
		updateright(v * 2, l, (r + l) / 2, al, ar, ind, val);
		updateright(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, ind, val);
	}
}
int ansleft(int v, int l, int r, int ind, int type)
{
	if(treeleft[v][type] != -2)
	{
		return treeleft[v][type];
	}
	if(ind <= (r + l) / 2)
	{
		return ansleft(v * 2, l, (r + l) / 2, ind, type);
	}
	else
	{
		return ansleft(v * 2 + 1, (r + l) / 2 + 1, r, ind, type);
	}
}
int ansright(int v, int l, int r, int ind, int type)
{
	if(treeright[v][type] != -2)
	{
		return treeright[v][type];
	}
	if(ind <= (r + l) / 2)
	{
		return ansright(v * 2, l, (r + l) / 2, ind, type);
	}
	else
	{
		return ansright(v * 2 + 1, (r + l) / 2 + 1, r, ind, type);
	}
}
int ans(int v, int l, int r, int al, int ar)
{
	if(tree2[v] > ar)
	{
		return 0;
	}
	if(l != r)
	{
		if(tree1[v] != -1)
		{
			tree1[v * 2] = tree1[v * 2 + 1] = tree1[v];
			tree2[v * 2] = tree2[v * 2 + 1] = tree1[v]; 
			tree3[v * 2] = tree3[v * 2 + 1] = tree1[v];
			treesum[v * 2] = tree1[v] * ((r + l) / 2 - l + 1);
			treesum[v * 2 + 1] = tree1[v] * (r - (r + l) / 2);
		}
	}
	if(al <= l && r <= ar)
	{
		if(tree3[v] > ar)
		{
			return ans(v * 2, l , (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
		}
		return (r - l + 1) * (ar + 1) - treesum[v];
	}
	else if(al <= r && ar >= l)
	{
		return ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	return 0;
}
signed main()
{
	scanf("%lld%lld%lld", &n, &m, &x);
	a.resize(n);
	for(int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}
	vector <int> left(20, -1), right(20, n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(((1 << j) & a[i]) != 0)
			{
				left[j] = i;
			}
		}
		for(int j = 0; j < 20; j++)
		{
			updateleft(1, 0, n - 1, i, i, j, left[j]);
		}
	}
	for(int i = n - 1; i >= 0; i--)
	{
		vector <pair <int, int> > mass;
		for(int j = 0; j < 20; j++)
		{
			if(((1 << j) & a[i]) != 0)
			{
				right[j] = i;
			}
			mass.push_back({right[j], j});
		}
		sort(mass.begin(), mass.end());
		int b = 0;
		for(int j = 0; j < 20; j++)
		{
			b |= (1 << mass[j].second);
			if(b >= x)
			{
				update(1, 0, n - 1, i, i, mass[j].first);
				break;
			}
		}
		for(int j = 0; j < 20; j++)
		{
			updateright(1, 0, n - 1, i, i, j, right[j]);
		}
	}
	while(m--)
	{
		int type;
		scanf("%lld", &type);
		if(type == 1)
		{
			int i, y;
			scanf("%lld%lld", &i, &y);
			i--;
			vector <pair <int, int> > mass(60);
			for(int j = 0; j < 20; j++)
			{
				left[j] = -1;
				right[j] = n;
			}
			for(int j = 0; j < 20; j++)
			{
				if(i == 0)
				{
					break;
				}
				left[j] = ansleft(1, 0, n - 1,i - 1, j);
			}
			for(int j = 0; j < 20; j++)
			{
				if(i == n - 1)
				{
					break;
				}
				right[j] = ansright(1, 0, n - 1, i + 1, j);
			}
			vector <int> cnt(20, 0);
			int rez = 0;
			bool flag = true;
			int cn = 0;
			for(int j = 0; j < 20; j++)
			{
				if(((1 << j) & y) != 0)
				{
					updateright(1, 0, n - 1, left[j] + 1, i, j, i);
					updateleft(1, 0, n - 1, i, right[j] - 1, j, i);
				}
				else
				{
					updateright(1, 0, n - 1, left[j] + 1, right[j] - 1, j, right[j]);
					updateleft(1, 0, n - 1, left[j] + 1, right[j] - 1, j, left[j]);
				}
				if(left[j] >= 0 || right[j] < n)
				{
					flag = false;
				}
				mass[cn++] = {left[j], j};
				mass[cn++] = {right[j], j};
				if(((1 << j) & y) != 0)
				{
					flag = false;
					mass[cn++] = {i, j};
				}
			}
			if(flag)
			{
				update(1, 0, n - 1, 0, n - 1, n);
				continue;
			}
			sort(mass.begin(), mass.begin() + cn);
			int r = 0;
			for(int j = 0; j < cn; j++)
			{
				int t = j;
				while(j < cn - 1 && mass[j + 1].first == mass[j].first)
				{
					j++;
				}
				while(r <= j || r < cn && rez < x)
				{
					cnt[mass[r].second]++;
					if(cnt[mass[r].second] == 1)
					{
						rez += (1 << mass[r].second);
					}
					r++;
				}
				if(mass[j].first >= i)
				{
					break;
				}
				if(mass[j + 1].first > mass[j].first && mass[j].first >= 0 && mass[r - 1].first >= i)
				{
					int st = 0;
					if(t != 0)
					{
						st = mass[t - 1].first + 1;
					}
					if(rez < x)
					{
						update(1, 0, n - 1, st, mass[j].first, n);
					}
					else
					{
						update(1, 0, n - 1, st, mass[j].first, mass[r - 1].first);
					} 
				}
				while(t <= j)
				{
					cnt[mass[t].second]--;
					if(cnt[mass[t].second] == 0)
					{
						rez -= (1 << mass[t].second);
					}
					t++;
				}
			}
			r = 0;
			while(r < cn && mass[r].first < i)
			{
				r++;
			}
			int pr = mass[r - 1].first + 1;
			rez = 0;
			for(int j = 0; j < 20; j++)
			{
				cnt[j] = 0;
			}
			while(r < cn && rez < x)
			{
				cnt[mass[r].second]++;
				if(cnt[mass[r].second] == 1)
				{
					rez += (1 << mass[r].second);
				}
				r++;
			}
			update(1, 0, n - 1, pr, i, mass[r - 1].first);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			printf("%lld\n", ans(1, 0, n - 1, l, r));
		}
	}
    return 0;
}