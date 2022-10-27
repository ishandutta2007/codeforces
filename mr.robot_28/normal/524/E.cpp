#include<bits/stdc++.h>
using namespace std;
int n, m, k, q;
vector <int> tree1, tree2;
void update1(int v, int l, int r, int ind, int val)
{
	if(l == r)
	{
		tree1[v] = val;
		return ;
	}
	if(ind <= (r + l) / 2)
	{
		update1(v * 2, l, (r + l) / 2, ind, val);
	}
	else
	{
		update1(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
	}
	tree1[v] = max(tree1[v * 2], tree1[v * 2 + 1]);
}
void update2(int v, int l, int r, int ind, int val)
{
	if(l == r)
	{
		tree2[v] = val;
		return ;
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
}
int ans1(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree1[v];
	}
	else if(l <= ar && r >= al)
	{
		return max(ans1(v * 2, l, (r + l) / 2, al, ar), ans1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
	}
	return 0;
}
int ans2(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree2[v];
	}
	else if(l <= ar && r >= al)
	{
		return max(ans2(v * 2, l, (r + l) / 2, al, ar), ans2(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
	}
	return 0;
}
bool cmp1(pair <int, int> a, pair <int, int> b)
{
	return a.second < b.second;
}
bool cmp2(vector <int> a, vector <int> b)
{
	return a[0] < b[0];
}
bool cmp3(vector <int> a, vector <int> b)
{
	return a[1] < b[1];
}
signed main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k >> q;
	tree1.resize(4 * n, 1e9);
	tree2.resize(4 * m, 1e8);
	vector <pair <int, int> > mass(k);
	for(int i = 0; i < k; i++)
	{
		cin >> mass[i].first >> mass[i].second;
		mass[i].first--;
		mass[i].second--;
	}
	sort(mass.begin(), mass.end());
	vector <vector <int> > query(q, vector <int> (5));
	for(int i = 0; i < q; i++)
	{
		cin >> query[i][0] >> query[i][1] >> query[i][2] >> query[i][3];
		query[i][0]--;
		query[i][1]--;
		query[i][2]--;
		query[i][3]--;
		query[i][4] = i;
	}
	sort(query.begin(), query.end(), cmp2);
	vector <bool> ans(q, 0);
	int j = mass.size() - 1;
	for(int i = query.size() - 1; i >= 0; i--)
	{
		while(j >= 0 && mass[j].first >= query[i][0])
		{
			update2(1, 0, m - 1, mass[j].second, mass[j].first);
			j--;
		}
		int a = ans2(1, 0, m - 1, query[i][1], query[i][3]);
		if(a <= query[i][2])
		{
			ans[query[i][4]] = 1;
		}
	}
	sort(mass.begin(), mass.end(), cmp1);
	sort(query.begin(), query.end(), cmp3);
	j = mass.size() - 1;
	for(int i = query.size() - 1; i >= 0; i--)
	{
		while(j >= 0 && mass[j].second >= query[i][1])
		{
			update1(1, 0, n - 1, mass[j].first, mass[j].second);
			j--;
		}
		int a = ans1(1, 0, n - 1, query[i][0], query[i][2]);
		if(a <= query[i][3])
		{
			ans[query[i][4]] = 1;
		}
	}
	for(int i = 0; i < q; i++)
	{
		if(!ans[i])
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