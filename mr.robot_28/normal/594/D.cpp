#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
vector <int> tree, upd;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % const1;
	}
	else
	{
		int t = power(a, b / 2);
		t = t * t % const1;
		return t * a % const1;
	}
}
void update(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		upd[v] = upd[v] * val % const1;
	}
	else if(l <= ar && r >= al)
	{
		update(v * 2, l, (r + l) / 2, al, ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
	}
}
int ans(int v, int l, int r, int ind)
{
	if(l == r)
	{
		return upd[v];
	}
	if(ind <= (r + l) / 2)
	{
		return upd[v] * ans(v * 2, l, (r + l) / 2, ind) % const1;
	}
	else
	{
		return upd[v] * ans(v * 2 + 1, (r + l) / 2 + 1, r, ind) % const1;
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	upd.resize(4 * n, 1);
	int cnt = 0;
	vector <int> p(1e6 + 1, -1);
	vector <int> last(1e6 + 1, n);
	vector <int> funct(1e6 + 1);
	for(int i = 2; i <=1e6; i++)
	{
		if(p[i] == -1)
		{
			funct[i] = (i - 1) * power(i, const1 - 2) % const1; 
			cnt++;
			int j = i;
			while(j <= 1e6)
			{
				p[j] = i;
				j += i;
			}
		}
	}
	vector <int> a(n);
	for(int i = 0; i< n; i++)
	{
		cin >> a[i];
	}
	vector <vector <pair <int, int> > > quest(n);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		quest[l].push_back({r, i});
	}
	vector <int> res(q);
	for(int i = n - 1; i >= 0; i--)
	{
		update(1, 0, n - 1, i, n - 1, a[i]);
		while(a[i] != 1)
		{
			int p1 = p[a[i]];
			while(a[i] % p1 == 0)
			{
				a[i] = a[i] / p1;
			}
			update(1, 0, n - 1, i, last[p1] - 1, funct[p1]);
			last[p1] = i;
		}
		for(int j = 0; j < quest[i].size(); j++)
		{
			int r = quest[i][j].first;
			int ind = quest[i][j].second;
			res[ind] = ans(1, 0, n - 1, r);
		}
	}
	for(int i = 0; i < q; i++)
	{
		cout << res[i] << "\n";
	}
	return 0;
}