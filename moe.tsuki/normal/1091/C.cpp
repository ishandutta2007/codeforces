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

int n;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
}

vi ans;

void gao(int x)
{
	ans.pb((n / x) * (1 + n + 1 - x) / 2);
}

void solve()
{
	for (int i = 1; i * i <= n; ++i)
	{
		if (n % i == 0) 
		{
			gao(i);
			if (i * i != n)
				gao(n / i);
		}
	}
	sort(all(ans));
	for (int x : ans) cout << x << ' ';
}

main()
{
	input();
	solve();
}