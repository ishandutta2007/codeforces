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

string s;
const int maxn = 1234;
int a[maxn], b[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
}

void solve()
{
	int n = s.length();
	F1 (i, n) if (s[i - 1] == '(') a[i] = 1;
	F1 (i, n) if (s[i - 1] == ')') b[i] = 1;
	F1 (i, n) a[i] += a[i - 1];
	for (int i = n; i >= 1; --i) b[i] += b[i + 1];
	int ans = 0, cur;
	F (i, n + 1)
	{
		if (min(a[i], b[i + 1]) > ans)
		{
			ans = min(a[i], b[i + 1]);
			cur = i;
		}
	}
	if (ans == 0)
	{
		cout << 0 << '\n';
		return;
	}
	cout << 1 << '\n';
	cout << ans + ans << '\n';
	int cnt = ans;
	vi out;
	F1 (i, cur) if (s[i - 1] == '(' && cnt-- > 0) out.pb(i);
	cnt = ans;
	for (int i = n; i >= cur + 1; --i) 
		if (s[i - 1] == ')' && cnt-- > 0) out.pb(i);
	sort(all(out));
	for (auto x : out) cout << x << ' ';
}

main()
{
	input();
	solve();
}