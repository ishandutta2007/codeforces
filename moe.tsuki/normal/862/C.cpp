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

int n, x;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x;
}

void solve()
{
	if (n == 2 && x == 0) { cout << "NO\n"; return; }
	cout << "YES\n";
	int start = 123455;
	if (n & 1)
	{
		F (i, n - 1) cout << ++start << ' '; 
		if (n % 4 == 1) cout << x << '\n';
		else cout << (x ^ 1) << '\n';
	} else
	{
		
		if (n % 4 == 2) 
		{
			if (x == 0)
			{
				F (i, n - 4) cout << ++start << ' ';
				cout << "1 2 4 6" << '\n';
				return;
			}
			cout << 0 << ' ' << x << ' ';
		}
		else 
		{
			if (x == 1) 
			{ 
				cout << "1 2 4 6" << ' '; 
				F (i, n - 4) cout << ++start << ' ';
				return;
			}
			else cout << 1 << ' ' << x << ' ';
			
		}
		F (i, n - 2) cout << ++start << ' ';
	}
}

main()
{
	input();
	solve();
}