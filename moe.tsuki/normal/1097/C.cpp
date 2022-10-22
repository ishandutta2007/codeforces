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

const int maxn = 123456;
int n;
string b[maxn];
map<int, int> m[2];
void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> b[i];
}

void gao(string cur, int buc)
{
	int pre = 0;//dbg(cur);
	for (auto x : cur)
	{
		if (x == ')')
		{
			--pre;
			if (pre < 0) return;
		} else ++pre;
	}
	// dbg(pre);
	++m[buc][pre];
}

void solve()
{
	F1 (ima, n)
	{
		gao(b[ima], 0);
		//dbg(b[ima]);
		string s = b[ima];
		reverse(all(b[ima]));
		for (auto &x : b[ima]) x = '(' + ')' - x;
		gao(b[ima], 1);
	}
	int ans = 0;
	for (auto i : m[0])
	{
		if (i.fi == 0) continue;
		ans += min(i.se, m[1][i.fi]);
	}
	ans += m[0][0] / 2;
	cout << ans << '\n';
}

main()
{ 
	input();
	solve();
}