#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;

struct node{
	int x;
	int mode;
	int p;

	bool operator<(const node &n) const{
		if (x == n.x) return abs(mode) > abs(n.mode);
		return x < n.x;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<node> events;
	for (int i = 0; i < n; ++i){
		int x, h, l, r;
		cin >> x >> h >> l >> r;

		events.push_back({x - h, 1, (100 - l)});
		events.push_back({x, -1, (100 - l)});
		events.push_back({x + 1, 1, (100 - r)});
		events.push_back({x + h + 1, -1, (100 - r)});
	}

	for (int i = 0; i < m; ++i){
		int x, p;
		cin >> x >> p;
		events.push_back({x, 0, p});
	}

	sort(events.begin(), events.end());

	int tot = 0;
	ld p = 0;
	ld ans = 0;

	for (auto e : events){
		if (e.mode == 1){
			if (e.p == 0) tot++;
			else p += log(e.p / 100.0);
		}
		else if (e.mode == -1){
			if (e.p == 0) tot--;
			else p -= log(e.p / 100.0);
		}
		else{
			if (tot == 0) ans += exp(p) * e.p;
		}
	}

	cout.precision(10);
	cout << fixed << ans << endl;

	return 0;
}