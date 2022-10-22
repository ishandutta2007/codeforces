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

const int maxn = 234567;
int t;
int A[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		int n; cin >> n;
		string ans = "";
		string s[3];
		cin >> s[0] >> s[1] >> s[2];
		int p, q, r;
		p = q = r = 0;
		for (int i = 0; i < n + n; ++i)
			if (s[0][i] == '0') ++p;
		for (int i = 0; i < n + n; ++i)
			if (s[1][i] == '0') ++q;
		for (int i = 0; i < n + n; ++i)
			if (s[2][i] == '0') ++r;
		int cnt = 0;
		if (p >= n) ++cnt;
		if (q >= n) ++cnt;
		if (r >= n) ++cnt;
		for (int i = 0; i < n + n; ++i) A[i] = 0;
		int flag = 0;
		if (cnt < 2)
		{
			flag = 1;
			for (auto &x : s[0]) x = '0' + '1' - x;
			for (auto &x : s[1]) x = '0' + '1' - x;
			for (auto &x : s[2]) x = '0' + '1' - x;
			p = n + n - p;
			q = n + n - q;
			r = n + n - r;
		}
		//dbg(s[0]);
		//dbg(s[1]);
		//dbg(s[2]);
		{ // 0
			vi fu;
			if (p >= n) fu.pb(0);
			if (q >= n) fu.pb(1);
			if (r >= n) fu.pb(2);
			int a = fu[0], b = fu[1];
			int cur = 0, pos = 0;
			for (int i = 0; i < n + n; ++i)
			{
				if (s[a][i] == '0') 
				{
					A[pos] = max(A[pos], cur);
					++pos;
					cur = 0;
				} else ++cur;
			}
			if (cur) 
			{
				A[pos] = max(A[pos], cur);
				++pos;
			}
			int mx = pos;
			cur = 0; pos = 0;
			for (int i = 0; i < n + n; ++i)
			{
				if (s[b][i] == '0') 
				{
					A[pos] = max(A[pos], cur);
					++pos;
					cur = 0;
				} else ++cur;
			}//MEOW
			if (cur) 
			{
				A[pos] = max(A[pos], cur);
				++pos;
			}
			mx = max(mx, pos);
			
			for (int i = 0; i < mx; ++i)
			{
				for (int j = 0; j < A[i]; ++j)
					ans += '1';
				if (ans.length() < n + n + n)ans += '0';
			}
			//dbg(ans);
		}
		if (flag) for (auto x : ans) cout << (char)('1' + '0' - x);
		else cout << ans;
		cout << '\n';
	}
}

main()
{
	input();
	solve();
}