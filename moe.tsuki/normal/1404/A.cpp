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

const int maxn = 345678;
int t;

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
		string s;
		cin >> s;
		int z = 0;
		int o = 0;
		bool ok = true;
		for (int i = 0; i < k; ++i)
		{
			for (int j = i + k; j < n; j += k)
				if (s[j] != '?')
					if (s[i] != '?' && s[j] != s[i])
						ok = false;
					else s[i] = s[j];
		}
		F (i, k)
			if (s[i] == '0') ++z;
			else if (s[i] == '1') ++o;
		if (max(z, o) * 2 > k) 
			ok = false;
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}

main()
{
	input();
	solve();
}