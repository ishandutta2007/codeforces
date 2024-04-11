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

int n, a, b;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a >> b;
}

void solve()
{
	int A = -1;
	for (int i = 0; i * a <= n; ++i)
	{
		if ((n - i * a) % b == 0) A = i;
	}
	if (A == -1)
	{
		cout << "-1\n";
		return;
	}
	int B = (n - A * a) / b;
	int cur = 1;
	F1 (i, A)
	{
		for (int t = cur + 1; t <= cur + a - 1; ++t)
			cout << t << ' ';
		cout << cur << ' ';
		cur += a;
	}
	F1 (i, B)
	{
		for (int t = cur + 1; t <= cur + b - 1; ++t)
			cout << t << ' ';
		cout << cur << ' ';
		cur += b;
	}
	// dbg(A); dbg(B);
}

main()
{
	input();
	solve();
}