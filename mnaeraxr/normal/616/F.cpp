#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

template<size_t maxlen, size_t alpha>
struct SuffixAutomaton
{
	int go[2 * maxlen][alpha], slink[2 * maxlen], length[2 * maxlen], size, last;
	int64 dp[2 * maxlen];

	int new_node()
	{
		memset(go[size], 0, sizeof go[size]);
		slink[size] = length[size] = 0;
		dp[size] = 0;
		return size++;
	}

	SuffixAutomaton() { reset(); }

	void reset()
	{
		size = last = 0;
		new_node();
		slink[0] = -1;
	}

	int _extend(int c)
	{
		int p, q, np, nq;
		if (q = go[last][c])
		{
			if (length[q] == 1 + length[last]) return q;
			int nq = new_node();
			length[nq] = 1 + length[last];
			memcpy(go[nq], go[q], sizeof go[q]);
			slink[nq] = slink[q];
			slink[q] = nq;
			for (p = last; p != -1 && go[p][c] == q; p = slink[p])
				go[p][c] = nq;
			return nq;
		}
		np = new_node();
		length[np] = 1 + length[last];
		for (p = last; p != -1 && !go[p][c]; p = slink[p])
			go[p][c] = np;
		if (p == -1) return slink[np] = 0, np;
		if (length[q = go[p][c]] == 1 + length[p]) return slink[np] = q, np;
		nq = new_node();
		length[nq] = 1 + length[p];
		memcpy(go[nq], go[q], sizeof go[q]);
		slink[nq] = slink[q];
		slink[q] = slink[np] = nq;
		for (; p != -1 && go[p][c] == q; p = slink[p])
			go[p][c] = nq;
		return np;
	}

	void extend(int c, int s) 
	{ 
		last = _extend(c);		
		dp[last] += s;
	}

	int bucket[maxlen + 1], order[2 * maxlen];

	void top_sort()
	{
		int maxl = 0;
		for (int e = 0; e < size; ++e)
			maxl = max(maxl, length[e]);
		for (int l = 0; l <= maxl; ++l)
			bucket[l] = 0;
		for (int e = 0; e < size; ++e)
			++bucket[length[e]];
		for (int l = 1; l <= maxl; ++l)
			bucket[l] += bucket[l - 1];
		for (int e = 0; e < size; ++e)
			order[--bucket[length[e]]] = e;
	}

	int64 solve()
	{
		top_sort();
		int64 answer = 0;
		
		for (int i = size - 1; i >= 1; --i){
			int u = order[i];			
			answer = max(answer, dp[u] * length[u]);
			
			dp[ slink[u] ] += dp[u];
		}
		
		return answer;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	
	static SuffixAutomaton<500000,26> sa;
	
	vector<string> S(n);
	for (int i = 0; i < n; ++i)
		cin >> S[i];
	
	for (int i = 0; i < n; ++i){
		int cost; cin >> cost;
		
		sa.last = 0;
		for (auto c : S[i])
			sa.extend(c - 'a', cost);
	}	
	
	cout << sa.solve() << endl;
	
	return 0;
}