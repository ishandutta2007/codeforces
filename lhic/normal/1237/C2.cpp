#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
using pt = array<int, 4>;

const int N = 51000;

pt a[N];

int n;

vector<pair<int, int>> ans;

void add(int x, int y) {
    ans.emplace_back(x, y);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][3] = i;
    }
    sort(a, a + n);
    /*map<pair<int, int>, vector<int>> mm;
    for (int i = 0; i < n; ++i) {
        if (mm[{a[i][0], a[i][1]}].size()) {
            add(mm[{a[i][0], a[i][1]}].back(), a[i][3]);
            mm[{a[i][0], a[i][1]}].pop_back();
        }
    }

    vector<array<int, 3>> b;

    for (auto x: mm) {
        if (x.second.size()) {
            b.push_back({x.first.first, x.first.second, x.second[0]});
        }
    }

    map<int, vector<int>> mm2;
    for (int i = 0; i < b.size(); ++i) {
        if (mm2[b[i][0]].size()) {
            add(mm2[b[i][0]][0], b[i][2]);
            mm2[b[i][0]].pop_back();
        }
    }*/

    vector<pt> b;

    for (int i = 0; i < n; ++i) {
        if (b.size() && b.back()[0] == a[i][0] && b.back()[1] == a[i][1]) {
            add(b.back()[3], a[i][3]);
            b.pop_back();
        } else {
            b.push_back(a[i]);
        }
    }

    vector<pt> tmp = b;
    b.clear();

    for (int i = 0; i < tmp.size(); ++i) {
        if (b.size() && b.back()[0] == tmp[i][0]) {
            add(b.back()[3], tmp[i][3]);
            b.pop_back();
        } else {
            b.push_back(tmp[i]);
        }
    }


    for (int i = 0; i < b.size(); i += 2) {
        add(b[i][3], b[i + 1][3]);
    }

    for (auto p: ans) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

	return 0;
}