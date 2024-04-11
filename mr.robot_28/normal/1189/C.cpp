#include<bits/stdc++.h> 
using namespace std;
vector <int> A;
vector <pair <int, int> > t;
void built(int v, int l, int r)
{
	if(l == r)
	{
		t[v] = {0, A[l]};
	}
	else
	{
		t[v] = {0, 0};
		built(v * 2, l, (r + l) / 2);
		built(v * 2 + 1, (r + l) / 2 + 1, r);
		t[v].second = t[v * 2].second + t[v * 2 + 1].second;
		if(t[v].second >= 10)
		{
			t[v].second = t[v].second % 10;
			t[v].first = 1;
		}
		t[v].first += t[v * 2].first + t[v * 2 + 1].first;
	}
}
pair <int, int> ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return t[v];
	}
	else if(l <= ar && r >= al)
	{
		pair <int, int> t1 = ans(2 * v, l, (r + l) / 2, al, ar);
		pair <int, int> t2 = ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
		if(t1.second + t2.second >= 10)
		{
			return {t1.first + t2.first + 1, (t1.second + t2.second) % 10};
		}
		else
		{
			return {t1.first + t2.first, t1.second + t2.second};
		}
	}
	else
	{
		return {0, 0};
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	A.resize(n);
	t.resize(4 * n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	built(1, 0, n - 1);
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		pair <int, int> y = ans(1, 0, n - 1, l, r);
		cout << y.first << "\n";
	}
	return 0;
}