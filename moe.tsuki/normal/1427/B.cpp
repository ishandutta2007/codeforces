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
int n, k;
int a[123456];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t; 
}

void solve()
{
	while (t --> 0)
	{
		int cnt = 0, ans = 0;
		cin >> n >> k;
		string s;
		cin >> s;
		vi q;
		int last = -1;
		F (i, n)
		{
			if (s[i] == 'W')
			{
				++cnt;
				++ans;
				if (i && s[i - 1] == 'W')
					++ans;
				else if (~last) q.pb(i - last - 1);
				last = i;
			}
		}
		ans += min(n - cnt, k) * 2;
		if (cnt == 0 && k > 0) --ans;
		/*if (n == 1) 
		{
			if (a[0] == 'W')
				cout << "1\n";
			else if (k >= 1)
				cout << "1\n";
			else cout << "0\n";
			continue;
		}*/
		sort(all(q));
		F (i, q.size())
			if (k >= q[i])
			{
				k -= q[i];
				++ans;
			}
		cout << ans << '\n';
	}
}

main()
{
	input();
	solve();
}