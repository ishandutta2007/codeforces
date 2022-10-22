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

int k, n;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
}

void query(vi v)
{
	cout << "? ";
	for (auto x : v) cout << x << ' ';
	cout << '\n';
	cout.flush();
}

void solve()
{
	vi v, big, sml;
	F1 (i, k) v.pb(i);
	query(v);
	v.clear();
	int pos, apos;
	cin >> pos >> apos;
	int ans = 0;
	for (int i = k + 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
			if (j != pos) v.pb(j);
		v.pb(i);
		query(v);
		v.clear();
		int b, bpos; cin >> b >> bpos;
		if (bpos > apos) big.pb(i);
		else sml.pb(i);
	}
	for (int i = 1; i <= k; ++i)
	{
		if (i == pos) continue;
		for (int j = 1; j <= k; ++j)
			if (j != i) v.pb(j);
		bool blg = false;
		if (big.size())
		{
			v.pb(big[0]);
			blg = true;	
		} else if (sml.size())
		{
			v.pb(sml[0]);
		}
		query(v);
		v.clear();
		int b, bpos; cin >> b >> bpos;
		if (blg)
		{
			if (b != pos) ++ans;
		}
		else if (b == pos) ++ans;
	}
	cout << "! " << ans + 1 << '\n'; 
	//dbg(big); dbg(sml);
}

main()
{
	input();
	solve();
}