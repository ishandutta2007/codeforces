#include<bits/stdc++.h>
 
using namespace std;
#define int long long
vector <int> f1, f2;
vector <vector <int> > tree1;
vector <vector <int> > tree2;
int m;
void build(int v, int l, int r)
{
	if(l == r)
	{
		tree1[v].push_back(min(f2[l], m - 1));
		tree2[v].push_back(min(f2[l], m - 1));
	}
	else
	{
		build(v * 2, l, (r + l) / 2);
		build(v * 2 + 1, (r + l) / 2 + 1, r);
		int j = 0;
		for(int i = 0; i < tree1[v * 2].size(); i++)
		{
			while(j < tree1[v * 2 + 1].size() && tree1[v * 2 + 1][j] <= tree1[v * 2][i])
			{
				tree1[v].push_back(tree1[v * 2 + 1][j]);
				j++;
			}
			tree1[v].push_back(tree1[v * 2][i]);
		}
		while(j < tree1[v * 2 + 1].size())
		{
			tree1[v].push_back(tree1[v * 2 + 1][j]);
			j++;
		}
		tree2[v].resize(tree1[v].size());
		tree2[v][tree2[v].size() - 1] = tree1[v][tree1[v].size() - 1];
		for(int i = tree2[v].size() - 2; i >= 0; i--){
			tree2[v][i] = tree1[v][i] + tree2[v][i + 1];
		}
	}
}
pair <int, int> funct(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		int l1 = -1, r1 = tree1[v].size();
		while(r1 - l1 > 1)
		{
			int midd = (r1 + l1) / 2;
			if(tree1[v][midd] >= val)
			{
				r1 = midd;
			}
			else
			{
				l1 = midd;
			}
		}
		if(r1 == tree1[v].size())
		{
			return {0, 0};
		}
		return {tree2[v][r1], tree1[v].size() - r1};
	}
	else if(l <= ar && r >= al)
	{
		pair <int, int> t1 = funct(v * 2, l, (r + l) / 2, al, ar, val);
		pair <int, int> t2 = funct(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		return {t1.first + t2.first, t1.second + t2.second};
	}
	else
	{
		return {0, 0};
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n >> m;
	string a, b, s;
	cin >> a >> b >> s;
	string b1 = b;
	string s1 = s;
	for(int i = 0; i < n / 2; i++)
	{
		swap(b1[i], b1[n - 1 - i]);
	}
	for(int i = 0; i < m / 2; i++)
	{
		swap(s1[i], s1[m - 1 - i]);
	}
	string t1 = s + "#" + a;
	string t2 = s1 + "#" + b1;
	vector <int> z1(t1.size());
	vector <int> z2(t2.size());
	int l = 0, r = -1;
	for(int i = 1; i < t1.size(); i++)
	{
		if(i > r)
		{
			int j = 0;
			while(j + i < t1.size() && t1[i + j] == t1[j])
			{
				j++;
			}
			z1[i] = j;
			if(j != 0)
			{
				l = i;
				r = i + j - 1;
			}
		}
		else if(i + z1[i - l] <= r)
		{
			z1[i] = z1[i - l];
		}
		else
		{
			int j = min(z1[i - l] - 1, r - i);
			if(j < 0)
			{
				j = 0;
			}
			while(j + i < t1.size() && t1[i + j] == t1[j])
			{
				j++;
			}
			z1[i] = j;
			if(z1[i] + i - 1 > r)
			{
				r = z1[i] + i - 1;
				l = i;
			} 
		}
	}
	l = 0, r = -1;
	for(int i = 1; i < t2.size(); i++)
	{
		if(i > r)
		{
			int j = 0;
			while(j + i < t2.size() && t2[i + j] == t2[j])
			{
				j++;
			}
			z2[i] = j;
			if(j != 0)
			{
				l = i;
				r = i + j - 1;
			}
		}
		else if(i + z2[i - l] <= r)
		{
			z2[i] = z2[i - l];
		}
		else
		{
			int j = min(z2[i - l], r - i);
			while(j + i < t2.size() && t2[i + j] == t2[j])
			{
				j++;
			}
			z2[i] = j;
			if(z2[i] + i - 1 > r)
			{
				r = z2[i] + i - 1;
				l = i;
			} 
		}
	}
	f1.resize(n);
	f2.resize(n);
	tree1.resize(4 * n);
	tree2.resize(4 * n);
	for(int i = 0; i < n; i++)
	{
		f1[i] = z1[m + 1 + i];
		f2[i] = z2[z2.size() - i - 1];
	}
	build(1, 0, n - 1);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(f1[i] > 0)
		{
			int k = m - f1[i];
			if(k < 1)
			{
				k = 1;
			}
			pair <int, int> t = funct(1, 0, n - 1, 0, n - 1, k);
			ans += min(f1[i], m - 1) * t.second + t.first - (m - 1) * t.second;
//			cout << t.first << " " << t.second << "\n";
//			cout << ans << "\n";
			if(i != 0)
			{
				t = funct(1, 0, n - 1, 0, i - 1, k);
				ans -= min(f1[i], m - 1) * t.second + t.first - (m - 1) * t.second;
			}
			if(i + m - 1< n)
			{
				t = funct(1, 0, n - 1, i + m - 1, n - 1, k);
				ans -= min(f1[i], m - 1) * t.second + t.first - (m - 1) * t.second;
//				cout << t.first << " "<< t.second << "\n";
			}
//			cout << ans << "\n";
		}
	}
	cout << ans;
	return 0;
}