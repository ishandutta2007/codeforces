#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, vm, M = 1000000007, fin[100005], op, l, r, x, y;
ll seed, a[100005];
set<int> st;

int rnd () {
	int res = seed;
	seed = (seed * 7 + 13) % M;
	return res;
}

ll pot (ll b, int p, int m) {
	ll res = 1;
	b %= m;

	while (p) {
		if (p & 1) {
			res *= b;
			res %= m;
		}

		b *= b;
		b %= m;
		p >>= 1;
	}

	return res;
}

void sumOp () {
	auto it = st.upper_bound(l);
	it--;

	if (*it < l && fin[*it] >= l) {
		fin[l] = fin[*it];
		fin[*it] = l-1;

		a[l] = a[*it];
		st.insert(l);
		it++;
	} else if (fin[*it] < l){
		it++;
	}

	while (it != st.end() && fin[*it] <= r) {
		a[*it] += x;
		it++;
	}

	if (it != st.end() && *it <= r) {
		a[r+1] = a[*it];
		a[*it] += x;
		st.insert(r+1);

		fin[r+1] = fin[*it];
		fin[*it] = r;
	}
}

void update () {
	auto it = st.upper_bound(l);
	it--;

	if (*it < l) {
		fin[l] = fin[*it];
		fin[*it] = l-1;

		a[l] = x;
		st.insert(l);

		if (fin[l] > r) {
			fin[r+1] = fin[l];
			st.insert(r+1);
			a[r+1] = a[*it];
		}
		it++;
	} else if (*it == l) {
		if (fin[l] > r) {
			fin[r+1] = fin[l];
			st.insert(r+1);
			a[r+1] = a[*it];
		}
	}
	a[l] = x;

	while (it != st.end() && *it <= l)
		it++;
	
	while (it != st.end() && fin[*it] <= r) {
		auto aux = it;
		it++;
		st.erase(aux);
	}

	if (it != st.end() && *it <= r) {
		a[r+1] = a[*it];
		st.insert(r+1);

		fin[r+1] = fin[*it];
		st.erase(it);

		it++;
	}

	fin[l] = r;
}

ll xMN () {
	auto it = st.upper_bound(l);
	it--;
	priority_queue<ii> pq;
	int acu = 0;

	if (*it < l) {
		acu += min(fin[*it], r) - l + 1;
		pq.emplace(a[*it], min(fin[*it], r) - l + 1);
		it++;
	}

	while (it != st.end() && fin[*it] <= r) {
		acu += fin[*it] - *it + 1;
		pq.emplace(a[*it], fin[*it] - *it + 1);
		it++;
	}

	if (it != st.end() && *it <= r) {
		acu += r - *it + 1;
		pq.emplace(a[*it], r - *it + 1);
	}

	while (acu - pq.top().se >= x) {
		acu -= pq.top().se;
		pq.pop();
	}

	return pq.top().fi;
}

int obtRes () {
	auto it = st.upper_bound(l);
	it--;
	ll sum = 0;

	if (*it < l) {
		sum += pot(a[*it], x, y) * (min(fin[*it], r) - l + 1);
		sum %= y;
		it++;
	}

	while (it != st.end() && fin[*it] <= r) {
		sum += pot(a[*it], x, y) * (fin[*it] - *it + 1);
		sum %= y;
		it++;
	}

	if (it != st.end() && *it <= r) {
		sum += pot(a[*it], x, y) * (r - *it + 1);
		sum %= y;
	}

	return sum;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> seed >> vm;

	for (int i = 1; i <= n; i++) {
		a[i] = rnd() % vm + 1;
		st.insert(i);
		fin[i] = i;
	}

	while (m--) {
		op = rnd() % 4;
		l = rnd() % n + 1;
		r = rnd() % n + 1;

		if (l > r)
			swap(l, r);

		if (op == 0) {
			x = rnd() % vm + 1;
			sumOp();
		} else if (op == 1) {
			x = rnd() % vm + 1;
			update();
		} else if (op == 2) {
			x = rnd() % (r - l + 1) + 1;
			cout << xMN () << endl;
		} else {
			x = rnd() % vm + 1;
			y = rnd() % vm + 1;

			cout << obtRes() << endl;
		}
	}

	return 0;
}