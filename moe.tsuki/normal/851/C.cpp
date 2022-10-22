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
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c)
{
	s << "[ "; for (auto it : c) s << it << " "; s << "\b]\n";
	return s;
}

const int maxn = 1234;
int n, a[maxn][5], b[maxn][5];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	
}

void solve()
{
	if (n > 250) 
	{
		cout << 0 << '\n';
		return;
	}
	F1 (i, n) F (j, 5) cin >> a[i][j];
	vi out;
	F1 (i, n)
	{
		bool ans = true;
		F1 (j , n)
			F (k, 5) b[j][k] = a[j][k] - a[i][k];
		F1 (p, n) F1 (q, n)
		{
			if (q == p) continue;
			int cur = 0;
			F (k, 5) cur += b[p][k] * b[q][k];
			if (cur > 0) { ans = false; goto meow; } 
		}
		meow:
		if (ans) out.pb(i);
	}
	cout << out.size() << '\n';
	F (i, out.size()) cout << out[i] << '\n';
}

int main()
{
	input();
	solve();
}