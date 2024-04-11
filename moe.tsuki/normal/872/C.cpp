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

int q;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> q;
}


// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
// 0 0 0 1 0 1 0 2 1 2  0  3  2  3  2
int a[123] = {0, 0, 0, 0, 1, 0, 1, 0, 2, 1, 2, 0, 3, 2, 3, 2};

void solve()
{
	//for (int i = 0; i < 20; ++i) { dbgg(i); dbg(a[i]); }
	for (int i = 0; i < q; ++i)
	{
		int t; cin >> t;
		if (t < 16)
		{
			if (a[t]) cout << a[t] << '\n';
			else cout << -1 << '\n';
		} else
		{
			cout << (t - 12) / 4 + a[12 + (t - 12) % 4] << '\n';
		}
	}
}

main()
{
	input();
	solve();
}