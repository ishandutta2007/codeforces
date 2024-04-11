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

int n, m;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
}

void solve()
{
	int cur = 0;
	int need = 0;
	F1 (i, n)
	{
		if (cur < m) ++need;
		cur += (i - 1) / 2;
		//dbgg(i); dbg(cur);
	}
	if (cur < m) { cout << "-1\n"; return; }
	//dbg(need);
	if (need)
	{
		F1 (i, need - 1) 
		{
			cout << i << ' ';
			m -= (i - 1) / 2;
		}
		int diff = (need - 1) / 2 - m;
		//dbg(diff);
		cout << need + diff * 2 << ' ';
	}
	for (int i = n - need; i > 0; --i)
		cout << 1000000000 - i * 20000 << ' ';
}

main()
{
	input();
	solve();
}