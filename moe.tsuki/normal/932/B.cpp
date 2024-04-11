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
#define int long long
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

const int maxn = 1234567;

int g(int a)
{
	int ret = 1;
	while (a)
	{
		if (a % 10)
		ret *= (a % 10);
		a /= 10;
	}
	if (ret < 10) return ret;
	return g(ret);
}

int q;
int v[10][maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> q;
}

void solve()
{
	F1 (i, maxn)
	{
		v[g(i)][i] = 1;
	}
	F (i, 10)
		F1 (j, maxn - 1) v[i][j] += v[i][j - 1];  
	F (i, q)
	{
		int l, r, k;
		cin >> l >> r >> k;
		if (k >= 10) { cout << "0\n"; continue; }
		cout << v[k][r] - v[k][l - 1] << '\n'; 
	}
}

main()
{
	input();
	solve();
}