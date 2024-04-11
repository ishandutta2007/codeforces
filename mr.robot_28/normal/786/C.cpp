#include<bits/stdc++.h>
 
using namespace std;
vector <int> b;
vector <vector <int> > tree, iterleft, iterright;
void build(int v, int l, int r)
{
	if(l == r)
	{
		tree[v].push_back(b[l]);
	}
	else
	{
		build(v * 2, l, (r + l) / 2);
		build(v * 2 + 1, (r + l) / 2 + 1, r);
		iterleft[v].resize(r - l + 1);
		iterright[v].resize(r - l + 1);
		int j = 0;
		for(int i = 0; i < tree[v * 2].size(); i++){
			while(j < tree[v * 2 + 1].size() && tree[v * 2 + 1][j] < tree[v * 2][i])
			{
				tree[v].push_back(tree[v * 2 + 1][j]);
				j++;
			}
			tree[v].push_back(tree[v * 2][i]);
		}
		while(j < tree[v * 2 + 1].size())
		{
			tree[v].push_back(tree[v * 2 + 1][j]);
			j++;
		}
		j = 0;
		for(int i = 0; i < tree[v].size(); i++)
		{
			while(j < tree[v * 2].size() && tree[v * 2][j] <= tree[v][i])
			{
				j++;
			}
			iterleft[v][i] = j - 1;
		}
		j = 0;
		for(int i = 0; i < tree[v].size(); i++)
		{
			while(j < tree[v * 2 + 1].size() && tree[v * 2 + 1][j] <= tree[v][i])
			{
				j++;
			}
			iterright[v][i] = j - 1;
		}
	}
}
pair <int, int> go_to(int v, int l, int r, int al, int ar, int ind, int cnt)
{
	if(l >= al && r <= ar)
	{
		if(l == r)
		{
			return {ind + 1, l};
		}
		if(ind + 1 <= cnt)
		{
			return {ind + 1, r};
		}
		int l1 = -1;
		if(ind != -1)
		{
			l1 = iterleft[v][ind];
		}
		pair <int, int> t = go_to(v * 2, l, (r + l) / 2, al, ar, l1, cnt);
		if(t.first == cnt && t.second < (r + l) / 2)
		{
			return t;
		}
		int r1 = -1;
		if(ind != -1){
			r1 = iterright[v][ind];
		}
		pair <int, int> t1 = go_to(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, r1, cnt - t.first);
		if(t1.first > cnt - t.first)
		{
			return t;
		}
		return {t.first + t1.first, t1.second};
	}
	else if(l <= ar && r >= al)
	{
		int l1 = -1;
		if(ind != -1)
		{
			l1 = iterleft[v][ind];
		}
		pair <int, int> t = go_to(v * 2, l, (r + l) / 2, al, ar, l1, cnt);
		if(t.first == cnt && t.second < (r + l) / 2)
		{
			return t;
		}
		int r1 = -1;
		if(ind != -1)
		{
			r1 = iterright[v][ind];
		}
		pair <int, int> t1 =  go_to(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, r1, cnt - t.first);
		if(t1.first > cnt - t.first){
			return t;
		}
		return {t1.first + t.first, t1.second};
	}
	else
	{
		return {0, -1};
	}
}
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> p(n, -1);
	b.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
		b[i] = p[a[i]];
		p[a[i]] = i;
	}
	tree.resize(4 * n);
	iterleft.resize(4 * n);
	iterright.resize(4 * n);
	build(1, 0, n - 1);
	for(int len = 1; len <= n; len++)
	{
		int ans = 0;
		int i = 0;
		while(i < n)
		{
			int l1 = -1, r1 = tree[1].size();
			while(r1 - l1 > 1)
			{
				int midd = (r1 + l1) / 2;
				if(tree[1][midd] < i)
				{
					l1 = midd;
				}
				else
				{
					r1 = midd;
				}
			}
			i = go_to(1, 0, n - 1, i, n - 1, l1, len).second;
			i++;
			ans++;
		}
		cout << ans << " ";
	}
	return 0;
}