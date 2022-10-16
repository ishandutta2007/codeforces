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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	static SuffixAutomaton<300003, 29> sa;
	sa.reset();

	int N = 300000;

	for (int i = 0; i < 3; ++i){
		string s; cin >> s;

		N = min(N, (int)s.length());

		for (auto c : s)
			sa.add(c - 'a', i);

		sa.add(26 + i, i);
	}

	sa.solve(N);

	return 0;
}