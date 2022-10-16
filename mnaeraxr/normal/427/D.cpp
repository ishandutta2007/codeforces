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
	int endpos[2 * maxlen][2];

	int new_node()
	{
		memset(go[size], 0, sizeof go[size]);
		slink[size] = length[size] = endpos[size][0] = endpos[size][1] = 0;
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
			endpos[slink[e]][0] += endpos[e][0];
			endpos[slink[e]][1] += endpos[e][1];
		}
	}

	int solve()
	{
		calc_endpos();

		int ans = -1;

		for (int e = 1; e < size; ++e)
			if (endpos[e][0] == 1 && endpos[e][1] == 1 && (ans == -1 || ans > length[slink[e]] + 1))
				ans = length[slink[e]] + 1;

		return ans;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	static SuffixAutomaton<10000+100, 27> sa;
	sa.reset();

	string s;
	cin >> s;

	for (char c : s)
		sa.add(c - 'a', 0);

	sa.add(26, 1);

	cin >> s;

	for (char c : s)
		sa.add(c - 'a', 1);

	cout << sa.solve() << endl;

	return 0;
}