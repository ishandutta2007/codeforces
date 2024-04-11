#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > P;
vector <vector <pair <int, int> > > t;
void built(int v, int l, int r)
{
	if(l == r)
	{
		for(int j = 0; j < 9; j++)
		{
			t[v][j].first = P[l][j];
			t[v][j].second = 1e9;
		}
	}
	else
	{
		built(v * 2, l, (r + l) / 2);
		built(v * 2 + 1, (r + l) / 2 + 1, r);
		for(int j = 0; j < 9; j++)
		{
			t[v][j].first = min(t[v * 2][j].first, t[v * 2 + 1][j].first);
			if(t[v * 2][j].first < t[v * 2 + 1][j].first)
			{
				t[v][j].second = min(t[v * 2][j].second, t[v * 2 + 1][j].first);
			}
			else
			{
				t[v][j].second = min(t[v * 2][j].first, t[v * 2 + 1][j].second);
			}
		}
	}
}
void update(int v, int l, int r, int pos, int R)
{
	if(l == r)
	{
		int p = R;
		for(int j = 0; j < 9; j++)
		{
			if(p % 10 != 0)
			{
				P[l][j] = R;
			}
			else
			{
				P[l][j] = 1e9;
			}
			t[v][j].first = P[l][j];
			t[v][j].second = 1e9;
			p = p / 10;
		}
		return;
	}
	if(pos <= (l + r) / 2)
	{
		update(v * 2, l, (r + l) / 2, pos, R);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, pos, R);
	}
	for(int j = 0; j < 9; j++)
	{
		t[v][j].first = min(t[v * 2][j].first, t[v * 2 + 1][j].first);
		if(t[v * 2][j].first < t[v * 2 + 1][j].first)
		{
			t[v][j].second = min(t[v * 2][j].second, t[v * 2 + 1][j].first);
		}
		else
		{
			t[v][j].second = min(t[v * 2][j].first, t[v * 2 + 1][j].second);
		}
	}
}
void ans(int v, int l, int r, int al, int ar, vector <pair <int, int> > &rez)
{
	if(al <= l && ar >= r)
	{
		rez = t[v];
		return ;
	}
	vector <pair <int, int> > a(9, {1e9, 1e9}), b(9, {1e9, 1e9});
	if(al <= (r + l) / 2 && ar >= l)
	{
		ans(v * 2, l, (r + l) / 2, al, ar, a);
	}
	if(al <= r && ar >= (r + l) / 2 + 1)
	{
		ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, b);
	}
	for(int i = 0; i < 9; i++)
	{
		if(a[i].first < b[i].first)
		{
			rez[i].first = a[i].first;
			rez[i].second = min(a[i].second, b[i].first);
		}
		else
		{
			rez[i].first = b[i].first;
			rez[i].second = min(a[i].first, b[i].second);
		}
	}
} 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <int> A(n);
	P.resize(n, vector <int> (9, 1e9));
	t.resize(n * 4, vector <pair <int, int> > (9));
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		int p = A[i];
		for(int j = 0; j < 9; j++)
		{
			if(p == 0)
			{
				break;
			}
			if(p % 10 != 0)
			{
				P[i][j] = A[i];
			}
			p = p / 10;
		}
	}
	built(1, 0, n - 1);
	for(int i = 0; i < m; i++)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int ind, x;
			cin >> ind >> x;
			ind--;
			update(1, 0, n - 1, ind, x);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			vector <pair <int, int> > K(9, {1e9, 1e9});
			ans(1, 0, n - 1, l, r, K);
			pair <int, int> a = {1e9, 1e9};
			for(int j = 0; j < 9; j++)
			{
				if(K[j].second != 1e9 && (a.first + a.second) > (K[j].first + K[j].second))
				{
					a = K[j];
				}
			}
			if(a.second == 1e9)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << a.first + a.second << "\n";
			}
		}
	}
	return 0;
}