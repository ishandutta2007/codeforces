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


int n, m, p;
int cnt[1234567];
bool use[67];
int ans;
string s[234567];
vi v;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> p;
	F1 (i, n) cin >> s[i];
}

void mobius(int l, int r)
{
	if (l == r) return;
	int m = (l + r) / 2;
	mobius(l, m);
	mobius(m + 1, r);
	for (int i = l, j = m + 1; i <= m; ++i, ++j)
		cnt[j] += cnt[i];
}

int myrand()
{
	static int fu = 41324329;
	return fu = (((fu * fu) ^ 12745221) % 1000000007);
}

void solve()
{
	F1 (t, 50)
	{
		int fu = myrand() % n + 1;
		v.clear();
		F (i, m) if (s[fu][i] == '1') v.pb(i);
		F1 (i, n)
		{
			int cur = (1 << v.size()) - 1;
			F (j, v.size())
				if (s[i][v[j]] == '1')
					cur -= (1 << j);
			++cnt[cur];
		}
		mobius(0, (1 << v.size()) - 1);
		F (i, 1 << v.size())
			if (cnt[i] >= (n + 1) / 2)
			{
				if (__builtin_popcountll((~i) & ((1ll << v.size()) - 1)) > ans)
				{
					ans = __builtin_popcountll((~i) & ((1ll << v.size()) - 1));
					F (j, 67) use[j] = false;
					F (j, v.size()) 
						if (((~i) & ((1ll << v.size()) - 1)) & (1ll << j))
							use[v[j]] = true;
				}
			}
		F (i, 65536) cnt[i] = 0;
	}
	F (i, m) cout << "01"[use[i]];
	cout << '\n';
}

main()
{
	input();
	solve();
}