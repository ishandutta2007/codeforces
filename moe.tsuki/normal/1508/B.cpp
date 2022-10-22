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

int t;
int u[123456];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		int n, k; cin >> n >> k;
		int cur = 0;
		int kk = k - 1;
		F (i, n - 1) kk >>= 1;
		F1 (i, n) u[i] = false;
		if (kk) cout << "-1\n";
		else 
		{
			while (k > 1)
			{
				//dbg(k);
				int f = 1;
				while (f + cur < n && (n - cur - f - 1 <= 62 && k > (1ll << (n - cur - f - 1))))
				{
					//dbg(k);
					k -= (1ll << (n - cur - f - 1));
					++f;
				}
				//dbg(f);
				for (int i = f + cur; i > cur; --i)
				{
					cout << i << ' ';
					u[i] = true;
				}
				cur += f;
			}
			F1 (i, n) if (!u[i]) cout << i << ' ';
			cout << '\n';
		}
	}
}

main()
{
	input();
	solve();
}