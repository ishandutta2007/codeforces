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

int m, n;
int a[34];

void input()
{
	cin >> m >> n;
}

void solve()
{
	
	int c;
	F (i, n)
	{
		cout << 1 << '\n';
		fflush(stdout);
		cin >> c;
		if (c == 0) return;
		if (c == 1) a[i] = 1;
	}
	int l = 1, r = m;
	int cnt = 0;
	while (true)
	{
		int mid = (l + r) / 2;
		cout << mid << '\n';
		fflush(stdout);
		cin >> c;
		if (c == 0) return;
		if (c == 1 && a[cnt])   l = mid + 1;
		if (c == 1 && !a[cnt])  r = mid - 1;
		if (c == -1 && a[cnt])  r = mid - 1;
		if (c == -1 && !a[cnt]) l = mid + 1;
		cnt = (cnt + 1) % n;
	}
}

main()
{
	input();
	solve();
}