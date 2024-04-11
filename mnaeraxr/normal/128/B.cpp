#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define endl '\n'

typedef long long ll;

template<size_t maxlen, size_t alpha>
struct SuffixAutomaton
{
	int go[2 * maxlen][alpha], slink[2 * maxlen], length[2 * maxlen], size, last;
	int endpos[2 * maxlen];

	int new_node()
	{
		memset(go[size], 0, sizeof go[size]);
		slink[size] = length[size] = endpos[size] = 0;
		return size++;
	}

	SuffixAutomaton() { reset(); }

	void reset()
	{
		size = last = 0;
		new_node();
		slink[0] = -1;
	}

	void add(int c)
	{
		int e = last, nlast = new_node();
		for (; e >= 0 && !go[e][c]; e = slink[e])
			go[e][c] = nlast;

		length[nlast] = 1 + length[last];
		last = nlast;
		endpos[last] = 1;

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
	ll dp[2 * maxlen];

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
			endpos[slink[e]] += endpos[e];
		}

		endpos[0] = 0;

		for (int i = size - 1; i >= 0; --i)
		{
			int e = order[i];
			for (int c = 0; c < alpha; ++c)
				if (go[e][c]) dp[e] += dp[go[e][c]];
			dp[e] += endpos[e];
		}
	}

	void getk(int k)
	{
		if (dp[0] < k)
		{
			cout << "No such line." << endl;
			return;
		}

		for (int e = 0; k >= 1;)
			for (int c = 0; c < alpha && k >= 1; ++c) if (go[e][c])
			{
				int w = go[e][c];

				if (dp[w] < k) k -= dp[w];
				else
				{
					cout << char(c + 'a');
					k -= endpos[w];
					e = w;
					break;
				}
			}

		cout << endl;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	static SuffixAutomaton<100000, 26> sa;
	sa.reset();

	string s;
	cin >> s;

	for (char c : s)
		sa.add(c - 'a');

	int k;
	cin >> k;

	sa.calc_endpos();
	sa.getk(k);

	return 0;
}