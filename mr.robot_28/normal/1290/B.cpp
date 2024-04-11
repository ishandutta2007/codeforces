#include<bits/stdc++.h> 
using namespace std;
//#define int long long
string s;
vector <vector <int> > tree;
bool flag = true;
void build(int v, int l, int r)
{
	if(l == r)
	{
		tree[v][s[l] - 'a'] = 1;
	}
	else
	{
		build(v * 2, l, (r + l) / 2);
		build(v * 2 + 1, (r + l) / 2 + 1, r);
		for(int i = 0; i < 26; i++)
		{
			tree[v][i] = tree[v * 2][i] + tree[v * 2 + 1][i];
		}
	}
}
vector <int> ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(ar <= (r + l) / 2)
	{
		return ans(v * 2, l, (r + l) / 2, al, ar);
	}
	else if(al > (r + l) / 2)
	{
		return ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	else
	{
		vector <int> v1 = ans(v * 2, l, (r + l) / 2, al, ar);
		vector <int>  v2 = ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
		vector <int> v(26);
		for(int i = 0; i < 26; i++)
		{
			v[i] = v1[i] + v2[i];
		}
		return v;
	}
}
main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	int n = s.size();
	tree.resize(n * 4, vector <int> (26));
	build(1, 0, n - 1);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		if(l == r)
		{
			cout << "Yes\n";
			continue;
		}
		vector <int>  v = ans(1, 0, n - 1, l - 1, r - 1);
		int cnt = 0;
		int cnt1 = 0;
		for(int j = 0; j < 26; j++)
		{
			if(v[j] != 0)
			{
				cnt++;
			}
			if(v[j] >= 2)
			{
				cnt1++;
			}
		}
		if(cnt  >= 3)
		{
			cout << "Yes\n";
		}
		else if(cnt == 1)
		{
			cout << "No\n";
		}
		else if(cnt == 2)
		{
			if(s[l - 1] == s[r -1 ])
			{
				cout << "No\n";
			}
			else
			{
				cout << "Yes\n";
			}
		}
	}
    return 0;
}