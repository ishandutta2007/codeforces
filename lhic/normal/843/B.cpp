#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

mt19937 rnd(time(NULL));

pair<int, int> get(int x) {
	cout << "? " << x << "\n";
	cout.flush();
	int val, nx;
	cin >> val >> nx;
	return make_pair(val, nx);
}

void ans(int x) {
	cout << "! " << x << "\n";
	cout.flush();
	exit(0);
}

int main() {
	int n, st, X;
	cin >> n >> st >> X;
	int y = get(st).first;
	pair<int, int> cur;
	if (y < X) {
		cur = make_pair(y, st);
	}
	else {
		ans(y);
	}
	for (int i = 0; i < 1000; ++i) {
		int x = rnd() % n + 1;
		int y = get(x).first;
		if (y < X && y > cur.first)
			cur = make_pair(y, x);
	}
	while (true) {
		int y = get(cur.second).second;
		if (y == -1)
			ans(-1);
		cur = make_pair(get(y).first, y);
		if (cur.first >= X)
			ans(cur.first);
	}
    return 0;
}