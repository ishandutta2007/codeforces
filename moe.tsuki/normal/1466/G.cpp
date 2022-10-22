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

const int maxn = 123456, mod = 1000000007, kt = 227, bk = 1000000009;
int n, q;
string s[23];
string t;
vi hh[23];
int pre[maxn][26];
int po[1234567];
int po2[1234567];
int last;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	cin >> s[0] >> t;
}

void build(int x)
{
	hh[x].resize(s[x].size());
	hh[x][0] = s[x][0];
	F1 (i, s[x].size() - 1)
		hh[x][i] = ((hh[x][i - 1] * kt % bk) + s[x][i]) % bk;
}

int hsh(int x, int l, int r)
{
	if (l == 0)
		if (r != -1)
			return hh[x][r];
		else return 0;
	return ((hh[x][r] - hh[x][l - 1] * po[r - l + 1] % bk) % bk + bk) % bk;
}

int gao(int x)
{
	int ret = 0;
	for (int i = 0; i < s[x].length(); ++i)
	{
		if (i + s[last + 1].length() - 1 >= s[x].length()) break;
		//dbgg(hsh(last + 1, 0, s[last + 1].length() - 1)); 
		//dbgg(hsh(x, i, i + s[last + 1].length() - 1));
		if (hsh(last + 1, 0, s[last + 1].length() - 1) == 
				hsh(x, i, i + s[last + 1].length() - 1))
			++ret;
	}
	//dbg(s[x]);
	//dbg(s[last + 1]);
	//dbg(ret);
	return ret;
}

void solve()
{
	po[0] = 1;
	F1 (i, 1234566)
		po[i] = po[i - 1] * kt % bk;
	po2[0] = 1;
	F1 (i, 1234566)
		po2[i] = po2[i - 1] * 2 % mod;
	for (int i = 0; i <= n; ++i)
	{
		if (i)
		{
			s[i] = s[i - 1];
			s[i] += t[i - 1];
			s[i] += s[i - 1];
			//if (s[i].length() < 50)dbg(s[i]);
			if (s[i].length() >= 2000001) break;
		}
		build(i);
		last = i;
	}
	F1 (i, n)
	{
		F (j, 26)
			pre[i][j] = pre[i - 1][j] * 2 % mod;
		pre[i][t[i - 1] - 'a'] = (pre[i][t[i - 1] - 'a'] + 1) % mod;
	}
	while (q --> 0)
	{
		int k; cin >> k;
		string qry; cin >> qry;
		//dbg(s[k]);
		s[last + 1] = qry;
		build(last + 1);
		int ans = 0;
		int til = 0;
		for (int i = 0; i <= min(last, k); ++i)
		{
			til = i;
			if (s[i].length() > qry.length() * 2) break;
		}
		//dbg(til);
		ans = gao(til) * po2[k - til];
		//dbg(ans);
		for (int i = 0; i < qry.size(); ++i)
		{
			/*dbg(s[last + 1]);
			dbg(i);
			dbg(hsh(last + 1, 0, i - 1));
			dbg(hsh(last + 1, i + 1, qry.size() - 1));*/
			if (hsh(last + 1, 0, i - 1) == 
				hsh(last, s[last].length() - i, s[last].length() - 1)
				&& hsh(last + 1, i + 1, qry.size() - 1) ==
				hsh(last, 0, qry.size() - i - 2))
			{
				//dbg(qry[i]);
				ans = (ans + pre[k][qry[i] - 'a'] - (pre[til][qry[i] - 'a'] * po2[k - til]) % mod) % mod;
			}
		}
		cout << (ans % mod + mod) % mod << '\n';
	}
}

main()
{
	input();
	solve();
}