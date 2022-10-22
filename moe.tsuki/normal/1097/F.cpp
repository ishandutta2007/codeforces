#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define F(i,n) for (int i = 0; i < n; ++i)
#define F1(i,n) for (int i = 1; i <= n; ++i)
#define dbg(x) cerr << #x << " = " << x << endl
#define dbgg(x) cerr << #x << " = " << x << ' '
#define T(x) x[pool]
#define mineq(x,y) { if ((x) > (y)) (x) = (y); }
#define maxeq(x,y) { if ((x) < (y)) (x) = (y); }
#define MEOW cout << "meowwwww" << '\n'; system("pause");
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c)
{
	s << "[ "; for (auto it : c) s << it << " "; s << "\b]\n";
	return s;
}

template<typename T>
ostream& operator <<(ostream &s, const pair<int, T> &c)
{
	s << "[ "; cout << c.fi << " , " << c.se << " ] ";
	return s;
}

const int maxn = 123456, L = 7020;
bitset<L> a[maxn];
bitset<L> FA[L], DI[L];
int n, q;

vi divs[L], fa[L];
bool sf[L];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
}

void solve()
{
	for (int i = 1; i < L; ++i) sf[i] = true;
	for (int i = 1; i < L; ++i)
	{
		int cur = i;
		int sqr = sqrt(cur) + 5;
		for (int j = 2; j <= sqr; ++j)
		{
			int ima = 0;
			while (cur % j == 0) ++ima, cur /= j;
			if (ima >= 2) sf[i] = false;
		}
	}
	

	for (int i = 1; i < L; ++i)
	{
		for (int j = i; j < L; j += i)
			divs[j].pb(i);
	}
	for (int i = 1; i < L; ++i)
	{
		for (int j = 1; j * i < L; ++j)
			if (sf[j]) fa[i].pb(i * j);
	}
	
	for (int i = 1; i < L; ++i)
	{
		for (int t : fa[i]) FA[i].set(t);
	}
	for (int i = 1; i < L; ++i)
	{
		for (int t : divs[i]) DI[i].set(t);
	}
	
	while (q --> 0)
	{
		int type; cin >> type;
		int x, y, z;
		if (type == 1)
		{
			cin >> x >> y;
			a[x] = DI[y];
		}
		if (type == 2)
		{
			cin >> x >> y >> z;
			a[x] = a[y] ^ a[z];
		}
		if (type == 3)
		{
			cin >> x >> y >> z;
			a[x] = a[y] & a[z];
		}
		if (type == 4)
		{
			cin >> x >> y;
			cout << (a[x] & FA[y]).count() % 2;
		}
	}
}

main()
{
	input();
	solve();
}