#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

//#define endl '\n'

typedef long long ll;

const ll mod = 1e9 + 7;

ll Madd(ll a, ll b){
	return (a + b) % mod;
}

ll Msub(ll a, ll b){
	return (a - b + mod) % mod;
}

template<size_t maxlen, size_t alpha>
struct SuffixAutomaton
{
	int go[2 * maxlen][alpha], slink[2 * maxlen], length[2 * maxlen], size, last;
	int endpos[2 * maxlen][3];

	int new_node()
	{
		memset(go[size], 0, sizeof go[size]);
		slink[size] = length[size] = 0;
		for (int i = 0; i < 3; ++i) endpos[size][i] = 0;
		return size++;
	}

	SuffixAutomaton() { reset(); }

	void reset()
	{
		size = last = 0;
		new_node();
		slink[0] = -1;
	}

	void add(int c, int id)
	{
		int e = last, nlast = new_node();
		for (; e >= 0 && !go[e][c]; e = slink[e])
			go[e][c] = nlast;

		length[nlast] = 1 + length[last];
		last = nlast;
		endpos[last][id] = 1;

		if (e == -1) slink[last] = 0;
		else
		{
			int q = go[e][c];

			if (length[q] == 1 + length[e]) slink[last] = q;
			else
			{
				int clone = new_node();
				memcpy(go[clone], go[q], sizeof go[q]);
				length[clone] = 1 + length[e];
				slink[clone] = slink[q];
				for (; e != -1 && go[e][c] == q; e = slink[e])
					go[e][c] = clone;
				slink[last] = slink[q] = clone;
			}
		}
	}

	int bucket[maxlen + 1], order[2 * maxlen];

	void top_sort()
	{
		for (int l = 0; l <= length[last]; ++l)
			bucket[l] = 0;

		for (int e = 0; e < size; ++e)
			++bucket[length[e]];

		for (int l = 1; l <= length[last]; ++l)
			bucket[l] += bucket[l - 1];

		for (int e = 0; e < size; ++e)
			order[--bucket[length[e]]] = e;
	}

	void calc_endpos()
	{
		top_sort();
		for (int i = size - 1; i > 0; --i)
		{
			int e = order[i];
			for (int j = 0; j < 3; ++j)
				endpos[slink[e]][j] += endpos[e][j];
		}
	}

	ll ans[maxlen];

	void solve(int N)
	{
		calc_endpos();

		for (int i = 0; i <= N; ++i) ans[i] = 0;

		for (int e = 1; e < size; ++e){
			ll a = endpos[e][0], b = endpos[e][1], c = endpos[e][2];

			if (a == 0 || b == 0 || c == 0) continue;

			ll m = a * b % mod * c % mod;

			ans[ length[e] ] = Madd(ans[ length[e] ], m);
			ans[ length[ slink[e] ] ] = Msub(ans[ length[ slink[e] ]], m);
		}

		for (int i = N - 1; i; --i)
			ans[i] = Madd(ans[i], ans[i + 1]);

		for (int i = 1; i <= N; ++i)
			cout << ans[i] << " ";
		cout << endl;
	}
};

vector<int> zfunction(const string &s)
{
	int n = s.length();

	vector<int> z(n, n);

	for (int i = 1, g = 0, f; i < n; ++i)
		if (i < g && z[i - f] != g - i)
			z[i] = min(z[i - f], g - i);
		else
		{
			for (g = max(g, f = i); g < n && s[g] == s[g - f]; ++g);
			z[i] = g - f;
		}

	return z;
}

vector<int> suffixes(const string &s)
{
	int n = s.length();

	vector<int> suff(n, n);

	for (int i = n - 2, g = n - 1, f; i >= 0; --i)
	{
		if (i > g && suff[i + n - 1 - f] != i - g)
			suff[i] = min(suff[i + n - 1 - f], i - g);
		else
		{
			for (g = min(g, f = i); g >= 0 && s[g] == s[g + n - 1 - f]; --g);
			suff[i] = f - g;
		}
	}

	return suff;
}

bool check(string s, string p){
	vector<int> pre = zfunction(p + "*" + s);
	vector<int> suf = suffixes(s + "*" + p);

	pre.erase(pre.begin(), pre.begin() + (int)p.length() + 1);
	suf.erase(suf.begin() + (int)s.length(), suf.end());

	vector<int> P(p.length() + 1, 1000000), S(p.length() + 1, -1000000);

	for (int i = 0; i < (int)s.length(); ++i){
		P[ pre[i] ] = min(P[pre[i]], i);
		S[ suf[i] ] = max(S[suf[i]], i);
	}

	for (int i = (int)p.length() - 1; i; --i){
		P[i] = min(P[i], P[i + 1]);
		S[i] = max(S[i], S[i + 1]);
	}

	int  m = (int)p.length();

	for (int i = 1; i < m; ++i){
		if (S[m - i] - P[i] + 1 >= m){
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;

	int n; cin >> n;

	int ans = 0;

	for (int i = 0; i < n; ++i){
		string p; cin >> p;

		ans += check(s, p);
	}

	cout << ans << endl;

	return 0;
}