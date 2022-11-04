#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	set<int> st;
	int v[200005], len[200005], act, l;
	ll n;
	priority_queue<ll> pq;

	cin >> n;

	act = 0;
	v[0] = -1;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];

		if (v[i] != v[act]) {
			act = i;
			len[i] = 0;
			st.insert(i);
		}

		len[act]++;
	}

	for (int x : st)
		pq.push(len[x] * n + n - x);

	int res = 0;

	while (st.size()) {
		int x = n - pq.top() % n;
		pq.pop();

		if (st.find(x) == st.end())
			continue;

		res++;

		auto it = st.lower_bound(x), a = it, b = it;

		if (++b != st.end() && a != st.begin()) {
			a--;

			if (v[*a] == v[*b]) {
				len[*a] += len[*b];
				st.erase(b);
				pq.push(len[*a] * n + n - *a);
			}

			st.erase(it);
		} else {
			st.erase(it);
		}
	}

	cout << res << endl;

	return 0;
}