#include<bits/stdc++.h>
using namespace std;
#define int long long
const int cnst = 1e9 + 7;
vector <int> simple;
vector <int> t, t1;
vector <bitset<300> > k, k1;
bitset <300> upd;
bitset <300> ans;
vector <int> predcnt;
int pr1 = 1;
vector <int> A;
int pow1(int a, int n)
{
	if(n == 0)
	{
		return 1;
	}
	else if(n  == 1)
	{
		return a % cnst;
	}
	else if(n % 2 == 0)
	{
		int a1 = pow1(a, n / 2);
		return (a1 * a1) % cnst;
	}
	else
	{
		int a1 = pow1(a, n / 2);
		a1 = (a1 * a1) % cnst;
		return (a1 * a) % cnst;
	}
}
void build(int v, int l, int r)
{
	if(l == r)
	{
		t[v] = A[l];
		while(A[l] > 1)
		{
			k[v][predcnt[A[l]]] = 1;
			A[l] = A[l] / predcnt[A[l]];
		}	
	}
	else
	{
		build(v * 2, l, (r + l) / 2);
		build(v * 2 + 1, (r + l) / 2 + 1, r);
		t[v] = (t[v * 2] * t[v * 2 + 1]) % cnst;
		k[v] = k[v * 2] | k[v * 2 + 1];
	}
}
void update(int v, int l, int r, int al, int ar, int x)
{
	if(l >= al && r <= ar)
	{
		k[v] |= upd;
		t1[v] = (t1[v] * x) % cnst;
		t[v] = (t[v] * pow1(x, (r - l + 1))) % cnst;
		k1[v] |= upd;
	}
	else if(l <= ar && r >= al)
	{
		update(v * 2, l, (r + l) / 2, al, ar, x);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, x);
		t[v] = ((t[v * 2] * t[v * 2 + 1] % cnst) * pow1(t1[v], r - l + 1)) % cnst;
		k[v] = k[v * 2] | k[v * 2 + 1] | k1[v];
	}
}
void answer(int v, int l, int r, int al, int ar)
{
	if(al <= l && r <= ar)
	{
		ans |= k[v];
		pr1 = (pr1 * t[v]) % cnst;
	}
	else if(l <= ar && r >= al)
	{
		answer(v * 2, l, (r + l) / 2, al, ar);
		answer(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
		pr1 = (pr1 * pow1(t1[v], min(r, ar) - max(l, al) + 1)) % cnst;
		ans |= k1[v];
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	k.resize(4 * n);
	k1.resize(4 * n);
	A.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	t.resize(4 * n, 1);
	t1.resize(4 * n, 1);
	predcnt.resize(301, -1);
	for(int i = 2; i <= 300; i++)
	{
		if(predcnt[i] == -1)
		{
			int k = i;
			while(k <= 300)
			{
				predcnt[k] = i;
				k += i;
			}
		}
	}
	build(1, 0, n  - 1);
	vector <int> w1(301);
	for(int i = 1; i <= 300; i++)
	{
		w1[i] = pow1(i, cnst - 2);
	}
	for(int i = 0; i < q; i++)
	{
		string type;
		cin >> type;
		if(type == "MULTIPLY")
		{
			int l, r, x;
			cin >> l >> r >> x;
			l--;
			r--;
			for(int j = 2; j < 300; j++)
			{
				upd[j] = 0;
			}
			int x1 = x;
			while(x != 1)
			{
				upd[predcnt[x]] = 1;
				x = x / predcnt[x];
			}
			update(1, 0, n - 1, l, r, x1);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			int p = 1;
			for(int j = 2; j < 300; j++)
			{
				ans[j] = 0;
			}
			answer(1, 0, n - 1, l, r);
			p = pr1;
			for(int j = 2; j < 300; j++)
			{
				if(ans[j])
				{
					p = ((p * (j - 1) % cnst) * w1[j]) % cnst;
				}
			}
			pr1 = 1;
			cout << p << "\n";
		}
	}
    return 0;
}