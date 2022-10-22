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
int n;
int a[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i];
}

struct node
{
	node *c[2];
	int num;
	int inv;
};

void add(node *cur, int val, int at)
{
	int bit = 0;
	if (!cur -> c[bit])
	{
		cur -> c[bit] = new node();
		cur -> c[bit] -> num = 0;
		cur -> c[bit] -> inv = 0;
		cur -> c[bit] -> c[0] = cur -> c[bit] -> c[1] = NULL;
	}
	bit = 1;
	if (!cur -> c[bit])
	{
		cur -> c[bit] = new node();
		cur -> c[bit] -> num = 0;
		cur -> c[bit] -> inv = 0;
		cur -> c[bit] -> c[0] = cur -> c[bit] -> c[1] = NULL;
	}
	if (at)
		bit = ((1ll << (at - 1)) & val) ? 1 : 0;
	++cur -> num;
	if (at > 0)
	{
		if (bit == 0)
		{
			cur -> inv += cur -> c[1] -> num;
		}
		add(cur -> c[bit], val, at - 1);
	}
}

int ch[34];
int Inv;

void dfs(node *cur, int at)
{
	if (cur -> num == 0) return;
	if (at > 0)
	{
		ch[at] += cur -> c[0] -> num * cur -> c[1] -> num; 
		ch[at] -= cur -> inv * 2;
		//dbg(cur -> c[0] -> num * cur -> c[1] -> num);
		//dbgg(cur -> inv); dbg(at);
		Inv += cur -> inv;
	}
	if (cur -> c[0])
		dfs(cur -> c[0], at - 1);
	if (cur -> c[1])
		dfs(cur -> c[1], at - 1);
	//
}

void solve()
{
	node *ze = new node();
	ze -> num = 0;
	ze -> inv = 0;
	ze -> c[0] = ze -> c[1] = NULL;
	F1 (i, n)
		add(ze, a[i], 31);
	dfs(ze, 31);
	int ans = 0;
	F1 (i, 33)
		if (ch[i] < 0)
		{
			ans += 1ll << (i - 1);
			Inv += ch[i];
		}
	cout << Inv << ' ' << ans << '\n';
}

main()
{
	input();
	solve();
}