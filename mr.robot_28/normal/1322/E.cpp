#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, a[N], b[N];
vector <int> vec[N];
set <pair <int, int> > S;
struct node{
	int cl, cr, mx, vl, vr, v;
	node(){}
	node(int c)
	{
		cl = cr = c;
		mx = vl = vr = v = 1;
	}
}t[N * 4];
node operator+(node a, node b)
{
	node ans;
	ans.cl = a.cl;
	ans.cr = b.cr;
	ans.mx = max(a.mx, b.mx);
	ans.vl = a.vl;
	ans.vr = b.vr;
	ans.v = a.v + b.v;
	if(a.cr ^ b.cl)
	{
		ans.mx = max(ans.mx, a.vr + b.vl);
		if(a.v == a.vl)
		{
			ans.vl += b.vl;
		}
		if(b.v == b.vr)
		{
			ans.vr += a.vr;
		}
	}
	return ans;
}
void build(int v, int l, int r)
{
	if(l == r)
	{
		t[v] = node(0);
		return;
	}
	int midd = (r + l) / 2;
	build(v * 2, l, midd);
	build(v * 2 + 1, midd + 1, r);
	t[v] = t[v * 2] + t[v * 2 + 1];
}
void change(int v, int l, int r, int p)
{
	if(l == r)
	{
		t[v] = node(1);
		return;
	}
	if(p <= (r + l) / 2)
	{
		change(v * 2, l, (r + l) / 2, p);
	}
	else
	{
		change(v * 2 + 1, (r + l) / 2 + 1, r, p);
	}
	t[v] = t[v * 2] + t[v * 2 + 1];
}
struct YYN{
	int t[N * 4], nn;
	void build(int n)
	{
		for(nn = 1; nn <= n; nn <<= 1);
		for(int i = 0; i <= 2 * nn - 1; i++)
		{
			t[i] = 0;
		}
	}
	void change(int x, int y, int v)
	{
		x += nn - 1, y += nn + 1;
		for(; x ^ y ^ 1; x >>= 1, y >>= 1)
		{
			if(!(x & 1))
			{
				t[x ^ 1] = max(t[x ^ 1], v);
			}
			if(y & 1)
			{
				t[y ^ 1] = max(t[y ^ 1], v);
			}
		}
	}
	void output()
	{
		for(int i = 1; i <= nn - 1; i++)
		{
			t[i * 2] = max(t[i * 2], t[i]);
			t[i * 2 + 1] = max(t[i * 2 + 1], t[i]);
		}
		for(int i = 1; i <= n; i++)
		{
			cout << t[i + nn] << " ";
		}
	}
}RE;
void flip(int x)
{
	if(x == 1 || a[x] == a[x - 1])
	{
		S.erase(make_pair(x, a[x]));
	}
	if(x == n || a[x] == a[x + 1])
	{
		S.erase(make_pair(x + 1, a[x]));
	}
	a[x] ^= 1;
	change(1, 1, n, x);
	if(x == 1 || a[x] == a[x - 1])
	{
		S.insert(make_pair(x, a[x]));
	}
	if(x == n || a[x] == a[x + 1])
	{
		S.insert(make_pair(x + 1, a[x]));
	}
}
void update1(int x, int v)
{
	set <pair <int, int> > :: iterator it = S.lower_bound(make_pair(x, -1));
	set <pair <int, int> > :: iterator pre = it, suf = it;
	pre--;
	if(pre -> second == 1 && suf -> second == 1)
	{
		RE.change(pre -> first, suf -> first - 1, v);
	}
	else if(pre -> second == 1 && suf -> second == 0)
	{
		RE.change(pre -> first, (pre -> first + suf -> first) / 2 - 1, v);
	}
	else if(pre -> second == 0 && suf -> second == 1)
	{
		RE.change((pre -> first + suf ->  first) / 2, suf -> first - 1, v);
	}
}
void update2(int x, int v)
{
	set <pair <int, int> > :: iterator it = S.lower_bound(make_pair(x, -1));
	set <pair <int, int> > :: iterator  pre = it, suf = it;
	if(x != 1)
	{
		--pre;
		if(pre -> second == 1)
		{
			RE.change(pre -> first, it -> first - 1, v);
		}
		else
		{
			RE.change((pre -> first + it -> first) / 2, it -> first - 1, v);
		}
	}
	if(x != n + 1)
	{
		++suf;
		if(suf -> second == 1)
		{
			RE.change(it -> first, suf -> first - 1, v);
		}
		else
		{
			RE.change(it -> first, (it -> first + suf -> first) / 2 - 1, v);
		}
	}
}
void update3(int x, int v)
{
	if(x == 1 || a[x] == a[x - 1])
	{
		update2(x, v);
	}
	else
	{
		update1(x, v);
	}
	if(x == n || a[x] == a[x + 1])
	{
		update2(x + 1, v);
	}
	else
	{
		update1(x + 1, v);
	}
}
signed main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	*b = unique(b + 1, b + n + 1) - b - 1;
	for(int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(b + 1, b + *b + 1, a[i]) - b;
		vec[a[i]].push_back(i);
	}
	memset(a, 0, sizeof(a));
	build(1, 1, n);
	RE.build(n);
	for(int i = 1; i <= n + 1; i++)
	{
		S.insert(make_pair(i, 0));
	}
	int ansT = 0;
	for(int i = *b; i >= 1; i--)
	{
		for(int j = 0; j < vec[i].size(); j++)
		{
			flip(vec[i][j]);
		}
		for(int j = 0; j < vec[i].size(); j++)
		{
			update3(vec[i][j], b[i]);
		}
		ansT = max(ansT, t[1].mx);
	}
	cout << (ansT - 1) / 2 << "\n";
	RE.output();
	return 0;
}