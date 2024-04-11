#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

struct pt {
    int x, y, z, id;
};

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pt> p(n), q;

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].id = i;
    }

    sort(p.begin(), p.end(), [](const pt& p1, const pt& p2) {
        return make_tuple(p1.x, p1.y, p1.z) < make_tuple(p2.x, p2.y, p2.z);
    });

    vector<pii> result;
    vector<int> del(n);

    for (int i = 0; i + 1 < n; i++) {
        if (del[p[i].id] || del[p[i + 1].id]) continue;
        if (i + 1 < n && p[i].x == p[i + 1].x && p[i].y == p[i + 1].y) {
            del[p[i].id] = del[p[i + 1].id] = 1;
            result.emplace_back(p[i].id, p[i + 1].id);
        } else {
        }
    }

    for (int i = 0; i < n; i++) {
        if (!del[p[i].id]) {
            q.push_back(p[i]);
        }
    }

    p = q;
    n = (int) p.size();
    q.clear();

    sort(p.begin(), p.end(), [](const pt& p1, const pt& p2) {
        return make_tuple(p1.x, p1.y, p1.z) < make_tuple(p2.x, p2.y, p2.z);
    });

    for (int i = 0; i + 1 < n; i++) {
        if (del[p[i].id] || del[p[i + 1].id]) continue;
        if (i + 1 < n && p[i].x == p[i + 1].x) {
            del[p[i].id] = del[p[i + 1].id] = 1;
            result.emplace_back(p[i].id, p[i + 1].id);
        } else {
        }
    }

    for (int i = 0; i < n; i++) {
        if (!del[p[i].id]) {
            q.push_back(p[i]);
        }
    }

    p = q;
    n = (int) p.size();
    q.clear();

    sort(p.begin(), p.end(), [](const pt& p1, const pt& p2) {
        return make_tuple(p1.x, p1.y, p1.z) < make_tuple(p2.x, p2.y, p2.z);
    });

    q = p;

    int pos = (int) q.size() / 2;

    for (int it = 0; it < pos; it++) {
        result.emplace_back(q[pos + it].id, q[pos - it - 1].id);
    }

    for (auto r : result) {
        cout << r.first + 1 << " " << r.second + 1 << "\n";
    }

    return 0;
}