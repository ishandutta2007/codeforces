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

const int maxn = 1234567;
int n;
int val[maxn];
int m[maxn];
int l[maxn], r[maxn];
int ans[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	string s;
	F1 (i, n)
	{
		cin >> s;
		if (s[0] == 'I') cin >> val[i];
		else if (s[0] == 'N') 
		{
			m[i] = 3;
			cin >> l[i];
			//p[l[i]] = i;
		}
		else 
		{
			if (s[0] == 'A') m[i] = 0;
			if (s[0] == 'O') m[i] = 1;
			if (s[0] == 'X') m[i] = 2;
			cin >> l[i] >> r[i];
			//p[l[i]] = p[r[i]] = i;
		}
	}
}

int dfs(int cur)
{
	if (!l[cur]) return val[cur];
	int a, b;
	a = dfs(l[cur]);
	if (m[cur] == 3) return val[cur] = 1 - a;
	b = dfs(r[cur]);
	if (m[cur] == 0) return val[cur] = a & b;
	if (m[cur] == 1) return val[cur] = a | b;
	if (m[cur] == 2) return val[cur] = a ^ b;
}

void dfs_ans(int cur)
{
	//dbg(cur);
	if (!l[cur]) return;
	if (cur == 1) ans[1] = 1 - val[1];
	int a = val[l[cur]];
	if (m[cur] == 3) 
	{
		ans[l[cur]] = ans[cur];
		dfs_ans(l[cur]);
		return;
	}
	int b = val[r[cur]];
	int c;
	if (m[cur] == 0) c = a & b;
	if (m[cur] == 1) c = a | b;
	if (m[cur] == 2) c = a ^ b;
	
	
	//dbgg(a); dbgg(b); dbg(c);
	
	a = 1 - a;
	//dbg((a & b));
	if (m[cur] == 0) 
	{
		
		if (c == (a & b)) 
		{
			ans[l[cur]] = val[1];
			//dbg("fuck");
		}
		else ans[l[cur]] = ans[cur];
	}
	if (m[cur] == 1) 
		if (c == (a | b)) ans[l[cur]] = val[1];
		else ans[l[cur]] = ans[cur];
	if (m[cur] == 2) 
		if (c == (a ^ b)) ans[l[cur]] = val[1];
		else ans[l[cur]] = ans[cur];
	a = 1 - a;
	b = 1 - b;
	if (m[cur] == 0) 
		if (c == (a & b)) ans[r[cur]] = val[1];
		else ans[r[cur]] = ans[cur];
	if (m[cur] == 1) 
		if (c == (a | b)) ans[r[cur]] = val[1];
		else ans[r[cur]] = ans[cur];
	if (m[cur] == 2) 
		if (c == (a ^ b)) ans[r[cur]] = val[1];
		else ans[r[cur]] = ans[cur];
	b = 1 - b;
	//dbg(val[1]);
	//dbg(ans[3]);
	dfs_ans(l[cur]);
	dfs_ans(r[cur]);
}

void solve()
{
	dfs(1);
	dfs_ans(1);
	F1 (i, n) if (!l[i]) cout << ans[i];
	//cout << '\n';
	//F1 (i, n) cout << ans[i];
	//MEOW;
	//F1 (i, n) dbg(val[i]);
}

main()
{
	input();
	solve();
}