#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
#define ll long long
const int mod = 998244353;
const int N = 200;
int add(int a, int b)
{
	a += b;
	if(a >= mod)
	{
		a -= mod;
	}
	if(a < 0)
	{
		a += mod;
	}
	return a;
}
int mul(int a, int b)
{
	return a * b % mod;
}
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return mul(t, t);
	}
	return mul(a, power(a, b - 1));
}
int dv(int a, int b)
{
	return mul(a, power(b, mod - 2));
}
struct seg{
	int l;
	int free;
};
vector <seg> ret_split;
void rec(int l, int r, int al, int ar, int cfree = 60)
{
	if(r < al || l > ar)
	{
		return;
	}
	if(al <= l && ar >= r)
	{
		ret_split.push_back({l, cfree});
		return;
	}
	int midd = (r + l )/ 2;
	rec(l, midd, al, ar, cfree - 1);
	rec(midd + 1, r, al, ar, cfree - 1);
}
vector <seg> split(int l, int r)
{
	ret_split.clear();
	rec(0, (1LL << 60) - 1, l, r);
	return ret_split;
}
seg operator+(seg a, seg b)
{
	int pre1 = a.l;
	int pre2 = b.l;
	int len = max(a.free, b.free);
	int pre = (pre1 ^ pre2) / (1LL << len) * (1LL << len);
	return {pre, len};
}
const int inv2 = (mod + 1) / 2;
int n, m;
int l1[N], r1[N], l2[N], r2[N];
vector<seg> unu[65], doi[65];
struct node{
	node* l;
	node* r;
	bool tot;
	node(){
		l = r = 0;
		tot = 0;
	}
};
node* root = new node;
int type;
vector <int> la[3][100];
void baga2(node* now, int l, int r, int al, int ar, int kek = 60)
{
	if(now -> tot)
	{
		return;
	}
	if(al <= l && r <= ar)
	{
		now -> tot = 1;
		return;
	}
	int m = (r + l) / 2;
	if(al <= m)
	{
		if(!now -> l)
		{
			now -> l = new node;
			la[type][kek - 1].push_back(l);
		}
		baga2(now -> l, l, m, al, ar, kek - 1);
	}
	if(m + 1 <= ar)
	{
		if(!now -> r)
		{
			now -> r = new node;
			la[type][kek - 1].push_back(r);
		}
		baga2(now -> r, m + 1, r, al, ar, kek - 1);
	}
}
void baga(node* now, int l, int r, int al, int ar)
{
	if(now -> tot)
	{
		return;
	}
	if(al <= l && r <= ar)
	{
		now -> tot = 1;
		return;
	}
	int m = (r + l) / 2;
	if(al <= m)
	{
		if(!now -> l)
		{
			now -> l = new node;
		}
		baga(now -> l, l, m, al, ar);
	}
	if(ar >= m + 1)
	{
		if(!now -> r)
		{
			now -> r = new node;
		}
		baga(now -> r, m + 1, r, al, ar);
	}
}
int gauss(int x)
{
	x %= mod;
	return mul(inv2, mul(x, x + 1));
}
int gauss(int l, int r)
{
	return add(gauss(r), -gauss(l - 1));
}
int scoate(node* now, int l, int r)
{
	if(now -> tot)
	{
		return gauss(l, r);
	}
	int m = (r + l) / 2;
	int ret = 0;
	if(now -> l)
	{
		ret = add(ret, scoate(now -> l, l, m));
	}
	if(now -> r)
	{
		ret = add(ret, scoate(now -> r, m + 1, r));
	}
	return ret;
}
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n;
	vector<seg> segs1, segs2;
	for(int i = 0; i < n; i++)
	{
		cin >> l1[i] >> r1[i];
		auto vec = split(l1[i], r1[i]);
		for(auto &s : vec)
		{
			segs1.push_back(s);
		}
	}
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> l2[i] >> r2[i];
		auto vec = split(l2[i], r2[i]);
		for(auto &s : vec)
		{
			segs2.push_back(s);
		}
	}
	node* root1 = new node;
	node* root2 = new node;
	type = 1;
	la[type][60].push_back(0);
	for(auto &x : segs1)
	{
		baga2(root1, 0, (1LL << 60) - 1, x.l, x.l + (1LL << x.free) - 1);
	}
	type = 2;
	la[type][60].push_back(0);
	for(auto x : segs2)
	{
		baga2(root2, 0, (1LL << 60) - 1, x.l, x.l + (1LL << x.free) - 1);
	}
	for(auto &x : segs1)
	{
		for(auto &val : la[2][x.free])
		{
			seg y = {val, x.free};
			auto z = x + y;
			baga(root, 0, (1LL << 60) - 1, z.l, z.l + (1LL << z.free) - 1);
		}
	}
	for(auto &x : segs2)
	{
		for(auto &val : la[1][x.free])
		{
			seg y = {val, x.free};
			auto z = x + y;
			baga(root, 0, (1LL << 60) - 1, z.l, z.l + (1LL << z.free) - 1);
		}
	}
	cout << scoate(root, 0, (1LL << 60) - 1);
	return 0;
}