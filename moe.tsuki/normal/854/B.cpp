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

int a, b;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b;
}

void solve()
{
	if (b == 0 || b == a) {cout << 0 << ' ' << 0<<'\n'; return;}
	if (a >= 3 * b) {cout << 1 << ' ' << 2*b<<'\n'; return;}
	cout << 1 << ' ' << a - b << '\n';
	

}

main()
{
	input();
	solve();
}