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
string s;
int n, m;
int val[maxn];
int v[64];
int fre[6];
int ans[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
}

void solve()
{
	n = s.size();
	cin >> m;
	F1 (i, m)
	{
		int k; string t;
		cin >> k >> t;
		F (j, t.length()) 
		{
			val[k] += 1 << (t[j] - 'a');
		}
		F (j, 64) if ((j & val[k]) == val[k]) --v[j];
	}
	F (i, n) ++fre[s[i] - 'a'];
	F (i, 6)
		F (j, 64)
			if ((j & (1 << i)) == (1 << i))
				v[j] += fre[i];
	F1 (t, n)
	{
		if (val[t]) F (i, 64) if ((i & val[t]) == val[t]) ++v[i];
		//F (i, 5) dbgg(fre[i]); dbg(fre[5]);
		//dbg(t);
		//dbg(val[t]);
		//dbg(v[2]);
		F (i, 6)
		{
			if (val[t] && ((val[t] & (1 << i)) == 0)) continue;
			if (!fre[i]) continue;
			bool ok = true;
			F (j, 64)
				if ((j & (1 << i)) == (1 << i))
					if (v[j] <= 0) ok = false;
			if (ok) 
			{
				ans[t] = i + 1;
				//dbg(ans[t]);
				F (j, 64)
					if ((j & (1 << i)) == (1 << i))
						--v[j];
				--fre[i];
				break;
			}
		}
		//dbg(t);
		if (!ans[t]) { cout << "Impossible\n"; return; }
		
	}
	F1 (i, n) putchar('a' + ans[i] - 1);
}

main()
{
	input();
	solve();
}